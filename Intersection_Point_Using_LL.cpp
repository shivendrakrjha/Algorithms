#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *t1=head1;
    Node *t2=head2;
    int c1=0,c2=0;
    while(t1!=NULL){
        c1+=1;
        //t1->data = t1->data * (-1);
        t1=t1->next;
    }
    while(t2!=NULL){
        c2+=1;
        t2=t2->next;
    }
    t1=head1;
    t2=head2;
    int d=abs(c1-c2);
    int x=0;
    if(c1 > c2){
        while(d--){
            if(t1==NULL)
            return -1;
            t1=t1->next;
            //c1--;
        }
        x=c2;
    }else{
        while(d--){
            if(t2==NULL)
            return -1;
            t2=t2->next;
            //c2--;
        }
        x=c1;
    }
    while(t1!=NULL && t2!=NULL){
        //cout<<t1->data<<" "<<t2->data<<endl;
        if( t1 == t2 ){
        return t1->data;
        //break;
        }
        t1=t1->next;
        t2=t2->next;
        //x--;
    }
    return -1;
}
