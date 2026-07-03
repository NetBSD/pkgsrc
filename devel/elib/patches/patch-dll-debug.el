$NetBSD: patch-dll-debug.el,v 1.2 2026/07/03 10:33:29 wiz Exp $

for emacs28

--- dll-debug.el	1995-12-11 09:50:54.000000000 +0900
+++ dll-debug.el	2023-09-09 06:49:20.470715606 +0900
@@ -74,9 +74,9 @@
 (defmacro dll-insert-after (node element)
   (let ((node-v (make-symbol "node"))
 	(element-v (make-symbol "element")))
-    (` (let (((, node-v) (, node))
-	     ((, element-v) (, element)))
-	 (setcdr (, node-v) (cons (, element-v) (cdr (, node-v))))))))
+     ` (let ((  , node-v   , node )
+	     ( , element-v   , element ))
+	 (setcdr  , node-v  (cons  , element-v  (cdr  , node-v ))))) )
 
 ;;; ===================================================================
 ;;;       The public functions which operate on doubly linked lists.
@@ -86,7 +86,7 @@
   "Get the element of a NODE in a doubly linked list DLL.
 Args: DLL NODE."
 
-  (` (car (, node))))
+   ` (car  , node)  )
 
 
 (defun dll-create ()
