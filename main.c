#include <stdio.h>

struct node {
  int info;
  struct node *link;
};
struct node *START = NULL;

struct node* createNode() {
  struct node *n;
  n =(struct node*)malloc(sizeof(struct node));
  return(n);
}

// insert node at the last 
void insertNodeAtLast() {
  struct node *temp,*t;
  temp = createNode();
  printf("Enter a number ");
  scanf("%d ",&temp->info);
  
  if(START == NULL) 
    START = temp;
  else
  {
    t = START;
    while(t->link!=NULL)
      t= t->link;
    t->link = temp;
  }
}

// delete first node
void deleteFirstNode() {
  struct node *r ;
  
  if(START==NULL) 
    printf("List is empty could not able to delete ");
  else{
      r=START;
      START = START->link;
      free(r);
    }
}

// view the List

void viewList() {
  struct node *traverse;
   if(START==NULL) 
    printf("List is empty could not able to view ");
  else{
    traverse = START;
    while(traverse!=NULL){
      printf("%d ",&traverse->info);
      traverse=traverse->link;
    }
  }
}

// Menu driven code 
int menu() {
  int choice;
  printf("\n1. Add value ");
  printf("\n2. Delete first value");
  printf("\n3. View list");
  printf("\n4. Exit");
  scanf("%d",&choice);
  return choice;
}


int main(void) {

  while(1) {
    switch(menu()){
      case 1:
        insertNodeAtLast();
        break;
      case 2:
        deleteFirstNode();
        break;
      case 3:
        viewList();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid Entry");
    }
  }
  printf("code run successfully");
  
  return 0;
}