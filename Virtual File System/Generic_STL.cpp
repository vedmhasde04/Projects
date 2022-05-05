/*///////////////////////////////////////////////////////////////////////////////////////////////////////////
PROJECT NAME: GENERIC STANDARD TEMPLATE LIBRARY(DATA STRUCTURES)
1. LINEAR SINGLY LINKEDLIST
2. LINEAR DOUBLY LINKEDLIST
3. CIRCULAR SINGLY LINKEDLIST
4. CIRCULAR DOUBLY LINKEDLIST
5. STACK AND QUEUE
6. BINARY SEARCH TREE
NAME: PAVAN CHANDRAKANT JAGTAP
*////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template<typename T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
    struct node *lchild;
    struct node *rchild;
};

//////////////////////////////////////////LINEAR SINGLY LINKEDLIST////////////////////////////////////////
template<class T>
class SinglyLL
{
private:
    node<T> *first;
    int size;
    
public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
       
};

template<class T>
SinglyLL<T>:: SinglyLL()
    {
        first = NULL;
        size = 0;
    }

    
    template<class T>
    void SinglyLL<T> :: InsertFirst(T no)
    {
         node <T> * newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
    
    template<class T>
    void SinglyLL<T> :: InsertLast(T no)
    {
         node<T> * newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
             node<T> * temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }
    
    template<class T>
    void SinglyLL<T> :: InsertAtPos(T no, int ipos)
    {
        
        int size=0;
        node<T> * newn = NULL;
        node<T> * temp = first;
        size = Count();
        int i=0;
        

        if(ipos == 1){
            InsertFirst(no);
        }

        else if(ipos == size+1){
            InsertLast(no);
        }

        else{
            node<T> * newn = new node<T>;

            newn->data = no;
            newn->next = NULL;

            for(i=1; i<ipos-1; i++){
                temp = temp->next;
            }
            newn->next=temp->next;
            temp->next = newn;
        }
      
    }

    template<class T>
    void SinglyLL<T> :: DeleteFirst()
    {
         node<T> * temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
    
    template<class T>
    void SinglyLL<T> :: DeleteLast()
    {
         node<T> * temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }

    template<class T>
    void SinglyLL<T> :: DeleteAtPos(int ipos)
    {
        int size=0;
        node<T> * newn = first;
        node<T> * temp = NULL;
        node<T> * targated =NULL;
        int i=0;
        size = Count();

        if(ipos == 1){
            DeleteFirst();
        }

        else if(ipos == size){
            DeleteLast();
        }

        else{
            for(i=1; i<size; i++){
                temp = temp->next;
            }
            targated = temp->next;
            temp->next = targated->next;
            free(targated);
            
        }
        
    }
    
    template<class T>
    void SinglyLL<T> :: Display()
    {
         node<T>* temp = first;
        
        while(temp!= NULL)
        {
           // cout<<"            ";
            cout<<"|"<<temp->data<<"|->";
            
            temp = temp->next;
            
        }
        cout<<"NULL";
    }
    
    template<class T>
    int SinglyLL<T> :: Count()
    {
        cout<<"\n";
       return size;
    }

  //////////////////////////////////////LINEAR DOUBLY LINKEDLIST//////////////////////////////////////  
template<class T>
class DoublyLL{
    private:
        node<T> *first;
        node<T> *last;
        int size;

    public:
        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T , int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();      
};


template<class T>
DoublyLL<T> :: DoublyLL(){
    first = NULL;
    last = NULL;
    size=0;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T no){
        node<T> * newn = new node<T>;
        newn->data =no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first == NULL){
            first = newn;
        }

        else{
            newn->next= first;
            (first)->prev = newn;
            first = newn;
        }

    }

template<class T>
void DoublyLL<T> :: InsertLast(T no){
       // PNODE newn = NULL;
        node<T> * temp = first;

        node <T> * newn = new node<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first == NULL){
            first = newn;
        }

        else{
            while(temp->next != NULL){
                temp= temp->next;
            }

            temp->next = newn;
            newn->prev = temp;
        }
    }

template<class T>
void DoublyLL<T> :: DeleteFirst(){
        node<T> * temp = first;
        if(first != NULL){
            first = (first)->next;
            (first)->prev = temp;
            free(temp);
        }
       // size--;
    }

template<class T>
void DoublyLL<T> :: DeleteLast(){
        node<T> * newn = NULL;
        node<T> * temp = first;

        if(first == NULL){
            return;
        }

        else if((first)->next == NULL){
            free(first);
            first = NULL;
        }

        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->prev->next = NULL;
            free(temp);
        }
    }

template<class T>
void DoublyLL<T> :: InsertAtPos(T no,int pos){
        int size = Count();
        int i=0;
        node<T> * temp = first;
        node<T> * newn = NULL;

        if((pos<1) || (pos>size+1)){
            cout<<"Invalid Position";
            return;
        }
        
        if(pos == 1){
            InsertFirst(no);
        }

        else if(pos == size+1){
            InsertLast(no);
        }

        else{
            node<T> * newn = new node<T>;

            newn->data =no;
            newn->next = NULL;
            newn->prev = NULL;

            for(i=1; i<pos-1; i++){
                first = first->next;
                first->prev= temp;
            }

            newn->next = first->next;
            first->next = first->prev;
            first->prev = newn;
        
        }
 }

template<class T>
void DoublyLL<T> :: DeleteAtPos(int iPos){
        int size= Count();
        int i=0;
        node<T> * temp = first;

        if((iPos<1) || (iPos>size)){
            cout<<"Invalid position\n";
            return;
        }

        if(iPos == 1){
            DeleteFirst();
        }

        else if(iPos == size){
            DeleteLast();
        }

        else{
            for(i=1; i<iPos-1; i++){
                temp= temp->next;
            }
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;

        }
    }

template<class T>
void DoublyLL<T> :: Display(){
        node<T> * temp = first;
         while(temp!= NULL)
        {
           
            cout<<"|"<<temp->data<<"|->";
            
            temp = temp->next;
            
        }
        cout<<"NULL";
    
    
        
    }

template<class T>
int DoublyLL<T> :: Count(){
        int iCnt=0;
        while(first != NULL){
            iCnt++;
            first = first->next;
        }
        return iCnt;
}

/////////////////////////////////////////CIRCULAR SINGLY LINKEDLIST/////////////////////////////////////
template<class T>
class SinglyCL{
    private:
        node<T> * first;
        int size;

    public:
        SinglyCL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T , int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
        
};     
        

template<class T>
SinglyCL<T> :: SinglyCL(){
            first = NULL;
            size=0;
        }

template<class T>
void SinglyCL<T> :: InsertFirst(T no){
        node<T> *newn = new node<T>; //newn = (PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        if(first==NULL){
            first=newn;
        }

        else{
            newn->next=first;
            first=newn;
        }
        size++;
    }


template<class T>
void SinglyCL<T> :: InsertLast(T no){
        node<T> *newn = new node<T>;//Allocate the memory

    //Intailise the node
        newn->data = no;
        newn->next= NULL;

    //Insert the node
        if(first == NULL){
            first = newn;
        }

        else{
            node<T> * temp = first;

            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newn;
            
        }
        size++;
    }

template<class T>
void SinglyCL<T> :: InsertAtPos(T no,int pos){
        int size=1;
       // node<T> * newn = NULL;
        
       
        int i=0;

        if((pos<1) || (pos>size+1)){
            cout<<"Invalid Position";
            return;
        }

        if(pos == 1){
            InsertFirst(no);
        }

        else if(pos == size+1){
            InsertLast(no);
        }

        else{
            node<T> * newn = new node<T>;

            newn->data = no;
            newn->next = NULL;
            node<T> * temp = first;
            for(i=1; i<pos-1; i++){
                temp = temp->next;
            }
            newn->next=temp->next;
            temp->next = newn;
        }
        size++;
    }

template<class T>
void SinglyCL<T> :: DeleteFirst(){
        node<T> * temp = first;

        if(first != NULL){
            first = first->next;
            delete temp;
        }
        size--;
        
    }


template<class T>
void SinglyCL<T> :: DeleteLast(){
        node<T> * temp = first;

        if(first == NULL){
            return;
        }

        else if(first->next == NULL){
            delete first;
            first = NULL;
            size--;
        }

        else{
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }

template<class T>
void SinglyCL<T> :: DeleteAtPos(int iPos){
        int size=0;
       
       // node<T> *temp = NULL;
        node<T> * targated =NULL;
        int i=0;
        size = Count();

        if(iPos == 1){
            DeleteFirst();
        }

        else if(iPos == size){
            DeleteLast();
        }

        else{
            node<T> * temp = first;
            for(i=1; i<iPos-1; i++){
                temp = temp->next;
            }
            targated = temp->next;
            temp->next = targated->next;
            free(targated);
            
        }
    }

template<class T>
void SinglyCL<T> :: Display(){
    node<T>* temp = first;
     while(temp->next != NULL){
        cout<<"|"<<temp->data<<"|->";
        temp= temp->next;
     }
    cout<<"NULL";
}

template<class T>
int SinglyCL<T> :: Count(){
    int iCnt=0;
        node<T> * temp = first;
        while(temp != NULL){
            iCnt++;
            temp = temp->next;
        }
        return iCnt;
       // return size;
    
}

/////////////////////////////////////CIRCULAR DOUBLY LINKEDLIST////////////////////////////////////
template<class T>
class DoublyCL
{
private:
    node<T> * first;
    node<T> * last;
    int size;
    
public:
    DoublyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();
};

// Return_Value Class_Name :: Fnuction_Name(Parameters)
template<class T>
DoublyCL<T> :: DoublyCL(){
    
        first = NULL;
        last = NULL;
        size = 0;
}

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    node<T> * newn = new node<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}
      /// size--;



template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
    node<T> * newn = new node<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template<class T>
void DoublyCL<T> :: Display()
{
    node<T> * temp = first;
     
        for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"NULL";
    
    
}

template<class T>
int DoublyCL<T> :: Count()
{
    return size;
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template<class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        node<T> * newn= new node<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        node<T> * temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        node<T> *temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}

/////////////////////////////////////////////////Stack////////////////////////////////////////////////
template<class T>
class Stack{
    private:
    node<T> * first;
    int size=0;

    public:
    Stack();
    void Push(T);
    void Pop();
    void Display();
    int Count();

};

template<class T>
Stack<T> ::Stack(){
        first = NULL;
        size =0;
    }

    template<class T>
    void Stack<T> :: Display(){
        node<T> * temp = first;
        while(temp != NULL){
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp= temp->next;
        }
        cout<<"\n";
    }    
    
    template<class T>
    int Stack<T> :: Count(){
        int iCnt=0;
        while(first != NULL){
            iCnt++;
            first = first->next;
        }
        return iCnt ;
    }

    template<class T>
    void Stack<T> :: Push(T no){  //InsertFirst
       // PNODE newn = NULL;
        node<T> * newn = new node<T>;

        newn->data =no;
        newn->next =NULL;

        if(first == NULL){
            first = newn;
        }
        else{
            newn->next = first;
            first = newn;
        }
    }

    template<class T>
    void Stack<T> :: Pop()  //DeleteFirst
    {
        node<T> * temp = first;

        if(first != NULL){
          first = first->next;
            delete temp;
        }
    }

///////////////////////////////////////////////QUEUE//////////////////////////////////////////
template<class T>
class Queue{
    private:
    node<T> * first;
    int size;

    public:
    Queue();
    void Enqueue(T);
    void Dequeue();
    void Display();
    int Count();
   
};

template<class T>
Queue<T> :: Queue(){
        first = NULL;
        size =0;
    }

    template<class T>
    void Queue<T> :: Display(){
        node<T> * temp = first;

        while(temp != NULL){
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp = temp->next;
        }
        cout<<"\n";        
    }

    template<class T>
    int Queue<T> ::  Count(){
        int iCnt=0;
        while(first != NULL){
            iCnt++;
            first = first->next;
        }
        return iCnt;
    }

    template<class T>
    void Queue<T> ::Enqueue(T no){ //InsertLast
        node<T> * newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL){
            first = newn;
        }
        else{
            node<T> * temp =first;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newn->next =temp->next;
            temp->next = newn;
        }
    }

    template<class T>
    void Queue<T> :: Dequeue(){  //Deletefirst
        node<T> * temp = first;

        if(first != NULL){
          first = first->next;
            delete temp;
        }
    }

//////////////////////////////////////////BINARY SEARCH TREE/////////////////////////////////////////
template<class T>
class BST{
    private:
    node<T> * first;
    int size;

    public:
    BST();
    void Insert(T);
    bool Search(T);
    void Display();
};

template<class T>
BST<T> :: BST(){
    first = NULL;
    size = 0;
    }

template<class T>
void BST<T> :: Insert(T no){
    node<T> * newn = new node<T>;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL){
        first = newn;
    }

    else{
        node<T> *temp = first;
        while(1){ //Unconditional loop   for( ;  ; )
            if(temp->data == no){
                cout<<"Duplicacte node\n";
                delete newn;
                break;
            }

            else if(temp->data > no){   //left  : small number
                if(temp->lchild == NULL){
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;

           }

            else if(temp->data < no){   //right : motaa number
                if(temp->rchild == NULL){
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
        }
    }

}

template<class T>
    void BST<T> :: Display(){
        node<T> * temp = first;

        while(temp != NULL){
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp = temp->next;
        }
        cout<<"\n";        
    }

template<class T>
bool BST<T> :: Search(T no){
    
    if(first == NULL){  //if tree is empty
        return false;
    }

    else{      //Tree contain atleast one node
        while(first != NULL){
            if(first->data == no){  //node sapdlaa
                    
                    break;
            }

            else if(no> (first->data)){  //large
                first = first->rchild;
            }

            else if(no< (first->data)){  //small
                first = first->lchild;
            }

        }
        if(first == NULL){
            return false;
        }

        else{
            return true;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------TEST CASES------------------------------//
int main()
{
    SinglyLL<int>slobj;
    DoublyLL<int>dlobj;
    SinglyCL<int>scobj;
    DoublyCL<int>dcobj;
    Stack<int>stobj;
    Queue<int>quobj;
    BST<int>bsobj;
    
    int slRet = 0;
    cout<<"******************************************GENERIC  STANDARD  TEMPLATE  LIBRARY*******************************************\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<INTEGER>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    cout<<"\n";
    cout<<"-----------------------------------------------LINEAR SINGLY LINKEDLIST-------------------------------------------------\n";
    cout<<"1. Inserted Elements At First :  ";
    slobj.InsertFirst(51);
    slobj.InsertFirst(21);
    slobj.InsertFirst(11);
    slobj.Display();
    
    cout<<"\n";
    cout<<"2. Inserted Elements At Last :  ";
    slobj.InsertLast(101);
    slobj.InsertLast(111);
    slobj.Display();

    cout<<"\n";
    cout<<"3. Delete Elements AT First : ";
    slobj.DeleteFirst();
    slobj.Display();

    cout<<"\n";
    cout<<"4. Delete Elements AT Last : ";
    slobj.DeleteLast();
    slobj.Display();

    cout<<"\n";
    cout<<"5. Inserted Element At Position :  ";
    slobj.InsertAtPos(35,3);
    slobj.Display();

    cout<<"\n";
    cout<<"6. Deleted Element At Position :  ";
    slobj.DeleteAtPos(3);
    slobj.Display();

    slRet = slobj.Count();
    cout<<"7. Number of elements are in Linear Singly Linkelist : "<<slRet<<"\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int dlRet=0;
    
    cout<<"\n";
    cout<<"-----------------------------------------------LINEAR DOUBLY LINKEDLIST-------------------------------------------------\n";
    cout<<"1. Inserted Elements At First :  ";
    dlobj.InsertFirst(51);
    dlobj.InsertFirst(21);
    dlobj.InsertFirst(11);
    dlobj.Display();

    cout<<"\n";
    cout<<"1. Inserted Elements At First :  ";
    dlobj.InsertLast(101);
    dlobj.InsertLast(111);
    dlobj.Display();
    
    cout<<"\n";
    cout<<"3. Delete Elements AT First : ";
    dlobj.DeleteFirst();
    dlobj.Display();

    cout<<"\n";
    cout<<"4. Delete Elements AT Last : ";
    dlobj.DeleteLast();
    dlobj.Display();

    cout<<"\n";
    cout<<"5. Inserted Element At Position :  ";
    dlobj.InsertAtPos(35,1);
    dlobj.Display();

    cout<<"\n";
    cout<<"6. Deleted Element At Position :  ";
    dlobj.DeleteAtPos(1);
    dlobj.Display();

    cout<<"\n";
    dlRet = dlobj.Count();
    cout<<"7. Number of elements are in Linear Doubly LinkedList : "<<dlRet<<"\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int scRet=0;
    
    cout<<"\n" ;
    cout<<"-----------------------------------------------CIRCULAR SINGLY LINKEDLIST-------------------------------------------------\n";
    cout<<"1. Inserted Elements At First :  ";
    scobj.InsertFirst(51);
    scobj.InsertFirst(21);
    scobj.InsertFirst(11);
    scobj.Display();
    
    cout<<"\n";
    cout<<"2. Inserted Elements At Last :  ";
    scobj.InsertLast(101);
    scobj.InsertLast(111);
    scobj.Display();
    
    cout<<"\n";
    cout<<"3. Delete Elements AT First : ";
    scobj.DeleteFirst();
    scobj.Display();

    cout<<"\n";
    cout<<"4. Delete Elements AT Last : ";
    scobj.DeleteLast();
    scobj.Display();

    cout<<"\n";
    cout<<"5. Inserted Element At Position :  ";
    scobj.InsertAtPos(35,1);
    scobj.Display();

    cout<<"\n";
    cout<<"6. Deleted Element At Position :  ";
    scobj.DeleteAtPos(1);
    scobj.Display();

    
    scRet = scobj.Count();
    cout<<"\n7. Number of elemensts in Circular Singly LinkedList : "<<scRet<<"\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   int dcRet=0;
    
    cout<<"\n" ;
    cout<<"-----------------------------------------------CIRCULAR DOUBLY LINKEDLIST-------------------------------------------------\n";
    cout<<"1. Inserted Elements At First :  ";
    dcobj.InsertFirst(51);
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);
    dcobj.Display();
    
    cout<<"\n";
    cout<<"1. Inserted Elements At Last :  ";
    dcobj.InsertLast(101);
    dcobj.InsertLast(111);
    dcobj.Display();

    cout<<"\n";
    cout<<"3. Delete Elements At First : ";
    dcobj.DeleteFirst();
    dcobj.Display();

    cout<<"\n";
    cout<<"4. Delete Elements At Last : ";
    dcobj.DeleteLast();
    dcobj.Display();

    cout<<"\n";
    cout<<"5. Inserted Element At Position :  ";
    dcobj.InsertAtPos(35,1);
    dcobj.Display();

    cout<<"\n";
    cout<<"6. Deleted Element At Position :  ";
    dcobj.DeleteAtPos(1);
    dcobj.Display();
    
    dcRet = dcobj.Count();
    cout<<"\n7. Number of elemensts in Circular Singly LinkedList : "<<dcRet<<"\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

    cout<<"\n" ;
    cout<<"------------------------------------------------------STACK--------------------------------------------------------------\n";
    stobj.Push(31);
    stobj.Push(41);
    stobj.Push(61);
    cout<<"1. Pushed number in Stack are: ";
    stobj.Display();

    stobj.Pop();
    cout<<"1. Poped number in Stack are: ";
    stobj.Display();
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

    cout<<"\n" ;
    cout<<"------------------------------------------------------QUEUE--------------------------------------------------------------\n";
    quobj.Enqueue(31);
    quobj.Enqueue(41);
    quobj.Enqueue(61);
    cout<<"1. Enqueue number in Queue are: ";
    quobj.Display();

    quobj.Dequeue();
    cout<<"1. Dequeue number in Queue are: ";
    quobj.Display();
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

    cout<<"\n" ;
    cout<<"-------------------------------------------------------BST----------------------------------------------------------------\n";
    int no=0;
    bool bRet = false;
    bsobj.Insert(51);
    bsobj.Insert(101);
    bsobj.Insert(11);
    bsobj.Display();

    cout<<"Enter Number to search: ";
    cin>>no;
    bsobj.Search(no);
    bRet = bsobj. Search(no);
    if(bRet == true){
        cout<<"Data is there\n";
    }

    else{
        cout<<"Data is not there\n";
    }
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SinglyLL<char>slobj1;
    DoublyLL<char>dlobj1;
    SinglyCL<char>scobj1;
    DoublyCL<char>dcobj1;
    Stack<char>stobj1;
    Queue<char>qobj;
    BST<char>bsobj1;

    cout<<"\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CHARACTER>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    cout<<"\n";
    cout<<"-----------------------------------------------LINEAR SINGLY LINKEDLIST-------------------------------------------------\n"; 
    slobj1.InsertFirst('C');
    slobj1.InsertFirst('B');
    slobj1.InsertFirst('A');
    cout<<"1. Inserted Character At First :  ";
    slobj1.Display();
    
    cout<<"\n";
    slobj1.InsertLast('E');
    slobj1.InsertLast('D');
    cout<<"2. Inserted Character At Last :  ";
    slobj1.Display();

    cout<<"\n";
    cout<<"3. Delete Character At First : ";
    slobj1.DeleteFirst();
    slobj1.Display();

    cout<<"\n";
    cout<<"4. Delete Character At Last : ";
    slobj1.DeleteLast();
    slobj1.Display();

    cout<<"\n";
    cout<<"5. Inserted Character At Position :  ";
    slobj1.InsertAtPos('N',1);
    slobj1.Display();

    cout<<"\n";
    cout<<"6. Deleted Character At Position :  ";
    slobj1.DeleteAtPos(1);
    slobj1.Display();
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"-----------------------------------------------LINEAR DOUBLY LINKEDLIST-------------------------------------------------\n";

    dlobj1.InsertFirst('C');
    dlobj1.InsertFirst('B');
    dlobj1.InsertFirst('A');
    cout<<"1. Inserted Character At First :  ";
    dlobj1.Display();
    
    cout<<"\n";
    dlobj1.InsertLast('E');
    dlobj1.InsertLast('D');
    cout<<"1. Inserted Character At Last :  ";
    dlobj1.Display();
    
    cout<<"\n";
    cout<<"3. Delete Character At First : ";
    slobj1.DeleteFirst();
    slobj1.Display();

    cout<<"\n";
    cout<<"4. Delete Character At Last : ";
    dlobj1.DeleteLast();
    dlobj1.Display();

    cout<<"\n";
    cout<<"5. Inserted Character At Position :  ";
    dlobj1.InsertAtPos('N',1);
    dlobj1.Display();

    cout<<"\n";
    cout<<"6. Deleted Character At Position :  ";
    dlobj1.DeleteAtPos(1);
    dlobj1.Display();
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
    
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    
    cout<<"-----------------------------------------------CIRCULAR SINGLY LINKEDLIST-------------------------------------------------\n";
    scobj1.InsertFirst('C');
    scobj1.InsertFirst('B');
    scobj1.InsertFirst('A');
    cout<<"1. Inserted Character At First :  ";
    scobj1.Display();
    
    cout<<"\n";
    scobj1.InsertLast('E');
    scobj1.InsertLast('D');
    cout<<"1. Inserted Character At First :  ";
    scobj1.Display();

    cout<<"\n";
    cout<<"3. Delete Character At First : ";
    slobj1.DeleteFirst();
    slobj1.Display();

    cout<<"\n";
    cout<<"4. Delete Character At Last : ";
    slobj1.DeleteLast();
    slobj1.Display();

    cout<<"\n";
    cout<<"5. Inserted Character At Position :  ";
    slobj1.InsertAtPos('N',1);
    slobj1.Display();

    cout<<"\n";
    cout<<"6. Deleted Character At Position :  ";
    slobj1.DeleteAtPos(1);
    slobj1.Display();
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"-----------------------------------------------CIRCULAR DOUBLY LINKEDLIST-------------------------------------------------\n";
    
    dcobj1.InsertFirst('C');
    dcobj1.InsertFirst('B');
    dcobj1.InsertFirst('A');
    cout<<"1. Inserted Character At First :  ";
    dcobj1.Display();
    
    cout<<"\n";
    dcobj1.InsertLast('E');
    dcobj1.InsertLast('D');
    cout<<"1. Inserted Character At Last :  ";
    dcobj1.Display();

    cout<<"\n";
    cout<<"3. Delete Character At First : ";
    dcobj1.DeleteFirst();
    dcobj1.Display();

    cout<<"\n";
    cout<<"4. Delete Character At Last : ";
    dcobj1.DeleteLast();
    dcobj1.Display();

    cout<<"\n";
    cout<<"5. Inserted Character At Position :  ";
    dcobj1.InsertAtPos('N',1);
    dcobj1.Display();

    cout<<"\n";
    cout<<"6. Deleted Character At Position :  ";
    dcobj1.DeleteAtPos(1);
    dcobj1.Display();
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";

     cout<<"\n" ;
    cout<<"------------------------------------------------------STACK--------------------------------------------------------------\n";
    stobj1.Push('C');
    stobj1.Push('B');
    stobj1.Push('A');
    cout<<"1. Pushed number in Stack are: ";
    stobj1.Display();

    stobj1.Pop();
    cout<<"1. Poped number in Stack are: ";
    stobj1.Display();
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

    cout<<"\n" ;
    cout<<"------------------------------------------------------QUEUE--------------------------------------------------------------\n";
    qobj.Enqueue('A');
    qobj.Enqueue('B');
    qobj.Enqueue('C');
    cout<<"1. Enqueue number in Queue are: ";
    qobj.Display();

    qobj.Dequeue();
    cout<<"1. Dequeue number in Queue are: ";
    qobj.Display();
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

     cout<<"\n" ;
    cout<<"-------------------------------------------------------BST----------------------------------------------------------------\n";
    char no1= '\0';
    bool bRet2 = false;
    bsobj1.Insert('A');
    bsobj1.Insert('B');
    bsobj1.Insert('C');
    bsobj1.Display();

    cout<<"Enter Character to search: ";
    cin>>no1;

    bsobj1.Search(no1);
    bRet2 = bsobj1. Search(no1);
    if(bRet2 == true){
        cout<<"Data is there\n";
    }

    else{
        cout<<"Data is not there\n";
    }
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";

    cout<<"*************************************************************************************************************************************************************************\n";
    
    return 0;
}






























