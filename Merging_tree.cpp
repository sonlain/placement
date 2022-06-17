#include <bits/stdc++.h>
using namespace std;//addition of two trees,merging
struct node{
    int data;
    node*left;
    node*right;
};
node* newnode(int data)
{
    node* nnode=new node();
    nnode->data=data;
    nnode->left=nnode->right=NULL;
    return nnode;
}
void inorder(node * root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* mergenode(node*root1,node*root2)
{
    if(!root1)
        return root2;
    if(!root2)
        return root1;
    root1->data+=root2->data;
    root1->left=mergenode(root1->left,root2->left);
    root1->right=mergenode(root1->right,root2->right);
    return root1;
}
int main() {
	// your code goes here
    node * root1=newnode(1);
    root1->left=newnode(2);
    root1->right=newnode(3);
    root1->left->left=newnode(4);
    root1->left->right=newnode(5);
    root1->right->right=newnode(6);
    inorder(root1);
    cout<<endl;
    node* root2=newnode(4);
    root2->left=newnode(1);
    root2->right=newnode(7);
    root2->left->left=newnode(3);
    root2->right->left=newnode(2);
    root2->right->right=newnode(6);
    inorder(root2);
    cout<<endl;
    node *root3=mergenode(root1,root2);
    inorder(root3);
    return 0;
    
    
	
	return 0;
}
