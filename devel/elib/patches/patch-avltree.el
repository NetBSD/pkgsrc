$NetBSD: patch-avltree.el,v 1.1 2023/09/08 22:08:18 mef Exp $

for emacs28

--- avltree.el.orig	1995-12-11 09:50:53.000000000 +0900
+++ avltree.el	2023-09-09 06:10:11.235237927 +0900
@@ -69,19 +69,19 @@
 (defmacro elib-avl-node-create (left right data balance)
 
   ;; Create and return an avl-tree node.
-  (` (vector (, left) (, right) (, data) (, balance))))
+   ` (vector  , left   , right   , data   , balance)  )
 
 
 (defmacro elib-avl-node-balance (node)
 
   ;; Return the balance field of a node.
-  (` (aref (, node) 3)))
+   ` (aref  , node  3) )
 
 
 (defmacro elib-avl-node-set-balance (node newbal)
 
   ;; Set the balance field of a node.
-  (` (aset (, node) 3 (, newbal))))
+   ` (aset  , node  3  , newbal ) )
 
 
 
@@ -96,20 +96,20 @@
 (defmacro elib-avl-root (tree)
 
   ;; Return the root node for an avl-tree.  INTERNAL USE ONLY.
-  (` (elib-node-left (car (cdr (, tree))))))
+   ` (elib-node-left (car (cdr  , tree)))  )
 
 
 (defmacro elib-avl-dummyroot (tree)
 
   ;; Return the dummy node of an avl-tree.  INTERNAL USE ONLY.
 
-  (` (car (cdr (, tree)))))
+   ` (car (cdr  , tree))  )
 
 
 (defmacro elib-avl-cmpfun (tree)
 
   ;; Return the compare function of AVL tree TREE.  INTERNAL USE ONLY.
-  (` (cdr (cdr (, tree)))))
+   ` (cdr (cdr  , tree))  )
 
 
 ;; ----------------------------------------------------------------
