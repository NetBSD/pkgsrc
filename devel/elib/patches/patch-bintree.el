$NetBSD: patch-bintree.el,v 1.1 2023/09/08 22:08:18 mef Exp $

For emacs28

--- bintree.el.orig	1995-12-11 09:50:53.000000000 +0900
+++ bintree.el	2023-09-09 06:07:01.242411450 +0900
@@ -64,19 +64,19 @@
 (defmacro elib-bintree-root (tree)
 
   ;; Return the root node for a binary tree.  INTERNAL USE ONLY.
-  (` (elib-node-left (car (cdr (, tree))))))
+   ` (elib-node-left (car (cdr  , tree))) )
 
 
 (defmacro elib-bintree-dummyroot (tree)
 
   ;; Return the dummy node of a binary tree.  INTERNAL USE ONLY.
-  (` (car (cdr (, tree)))))
+   ` (car (cdr (, tree))) )
 
 
 (defmacro elib-bintree-cmpfun (tree)
 
   ;; Return the compare function of binary tree TREE.  INTERNAL USE ONLY."
-  (` (cdr (cdr (, tree)))))
+   ` (cdr (cdr (, tree))) )
 
 
 
