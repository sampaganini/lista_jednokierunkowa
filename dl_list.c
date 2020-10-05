//
// Created by kkuli on 16.06.2020.
//

#include <stdio.h>
#include <stdlib.h>

#include "dl_list.h"



struct linked_list_t* ll_create()
{
    struct linked_list_t* lista = (struct linked_list_t*)calloc(1,sizeof(struct linked_list_t));
    if(lista == NULL)
    {
        return NULL;

    }
    return lista;

}

int ll_push_back(struct linked_list_t* ll, int value)
{

    if(ll == NULL)
    {
        return 1;
    }
    struct node_t* node = (struct node_t*)calloc(1,sizeof( struct node_t));
    if(node == NULL)
    {
        return 2;
    }
    node->data = value;
    if(ll->head == NULL && ll->tail == NULL)
    {
        ll->head = ll->tail = node;

    }
    ll->tail->next = node;
    ll->tail = node;
    return 0;
}
int ll_push_front(struct linked_list_t* ll, int value)
{
    if(ll == NULL)
    {
        return 1;
    }
    struct node_t* node = (struct node_t*)calloc(1,sizeof( struct node_t));
    if(node == NULL)
    {
        return 2;
    }
    node->data = value;
    if(ll->head == NULL && ll->tail == NULL)
    {
        ll->head = ll->tail = node;

    }
    node->next = ll->head;
    ll->head = node;
    return 0;
}
int ll_pop_front(struct linked_list_t* ll, int* err_code)
{
    if(ll == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return 2;
    }
    if(ll->head == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return 3;
    }
    struct node_t* afterhead = ll->head->next;
    int val = ll->head->data;
    if(afterhead == NULL)
    {
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
        if(err_code != NULL)
        {
            *err_code = 0;
        }
        return val;
    }
    free(ll->head);
    ll->head = afterhead;
    if(err_code != NULL)
    {
        err_code = 0;
    }
    return val;
}
int ll_pop_back(struct linked_list_t* ll, int* err_code)
{
    if(ll == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return 2;
    }
    if(ll->head == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return 3;
    }
    struct node_t* node = ll->head;
    struct node_t* prenode = NULL;
    int val;
    if(node->next == NULL)
    {
        val = ll->head->data;
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
        if(err_code != NULL)
        {
            err_code = 0;
        }
        return val;
    }
    while(node->next)
    {
        prenode = node;
        node = node->next;

    }
    val = node->data;
    prenode->next = NULL;
    free(node);
    ll->tail = prenode;
    if(err_code != NULL)
    {
        err_code = 0;
    }
    return val;
}

struct node_t* ll_begin(struct linked_list_t* ll)
{
    if(ll == NULL)
    {
        return NULL;
    }
    if(ll->head == NULL)
    {
        return NULL;
    }
    return ll->head;
};
struct node_t* ll_end(struct linked_list_t* ll)
{
    if(ll == NULL)
    {
        return NULL;
    }
    if(ll->head == NULL)
    {
        return NULL;
    }
    struct node_t* node = ll->head;

    while(node->next)
    {
        node = node->next;
    }
    return node;
}

int ll_back(const struct linked_list_t* ll, int* err_code)
{
    if(ll == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return -1;
    }
    if(ll->head == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return -1;
    }
    struct node_t* node = ll->head;

    while(node->next)
    {
        node = node->next;
    }
    if(err_code != NULL)
    {
        *err_code = 0;
    }

    return node->data;
}
int ll_front(const struct linked_list_t* ll, int* err_code)
{

    if(ll == NULL)
    {
        return 1;
    }
    if(ll->head == NULL)
    {
        return 2;
    }
    return ll->head->data;
}

int ll_size(const struct linked_list_t* ll)
{
    if(ll == NULL)
    {
        return -1;
    }
    if(ll->head == NULL)
    {
        return 0;
    }
    struct node_t* node = ll->head;
    int licznik = 0;
    while(node)
    {
        node = node->next;
        licznik++;
    }
    return licznik;
}
int ll_is_empty(const struct linked_list_t* ll)
{
    if(ll == NULL)
    {
        return-1;
    }
    if(ll->head == NULL)
    {
        return 1;
    }
    else  return 0;
}
int ll_at(const struct linked_list_t* ll, unsigned int index, int* err_code)
{
    if(ll == NULL || index < 0 || ( ll->head == NULL && index != 0) )
    {
        if( err_code != NULL)
        {
            *err_code = 1 ;
        }
        return -1;
    }
    struct node_t* node = ll->head;
    int i = 0;
    for( i = 0; i < (int)index; i++)
    {
        if(node == NULL)
        {
            break;
        }
        node = node->next;
    }
    if(node == NULL || i != (int)index)
    {
        if( err_code != NULL)
        {
            *err_code = 1 ;
        }
        return -1;
    }
    if( err_code != NULL)
    {
        *err_code = 0 ;
    }
    return node->data;

}

int ll_insert(struct linked_list_t* ll, unsigned int index, int value)
{

    if(ll == NULL || index < 0 || ( ll->head == NULL && index != 0) )
    {
        return -1;
    }
    struct node_t* node = ll->head;
    int i = 0;
    for(i = 0; i < ((int)index-1); i++)
    {
        if(node==NULL) break;
        node = node->next;
    }
    if(node == NULL || i != ((int)index-1))
    {

        return 2;
    }
    struct node_t* insertnode = (struct node_t*)calloc(1,sizeof(struct node_t));
    if(insertnode == NULL)
    {
        return -1;
    }
    insertnode->data = value;
    insertnode->next = node->next;
    node->next = insertnode;
    return 0;

}

int ll_remove(struct linked_list_t* ll, unsigned int index, int* err_code)
{
    if (ll == NULL || ll->tail == NULL || ll->head == NULL || (int)index < 0 || (int)index >(ll_size(ll) - 1))
    {

        if (err_code != NULL)
        {
            *err_code = 1;
        }
        return 1;
    }
    if(index == 0)
    {
        return ll_pop_front(ll,err_code);
    }
    if((int)index == ll_size(ll))
    {
        return ll_pop_back(ll,err_code);
    }
    struct node_t* node = ll->head;
    struct node_t* prenode = NULL;
    for(int i = 0 ; i < (int)index; i++ )
    {
        prenode = node;
        node = node->next;

    }
    int val = node->data;
    prenode->next = node->next;
    free(node);
    node = NULL;
    if( err_code != NULL)
    {
        *err_code = 0 ;
    }
    return val;

}

void ll_clear(struct linked_list_t* ll)
{
    if(ll == NULL)
    {
        return ;
    }
    struct node_t* node = ll->head ;
    while(node)
    {
        ll->head = node->next;
        free(node);
        node = ll->head;

    }
    ll->tail = NULL;
}

void ll_display(const struct linked_list_t* ll)
{
    if (ll == NULL || ll->tail == NULL || ll->head == NULL)
    {

        return;
    }
    struct node_t* element = ll->head;

    for (;;)
    {
        if (element == NULL)
        {
            break;
        }

        printf("%d ", element->data);
        element = element->next;
    }




}

