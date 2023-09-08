$NetBSD: patch-dll.el,v 1.1 2023/09/08 22:08:18 mef Exp $

for emacs28

--- dll.el.orig	1995-12-11 09:50:54.000000000 +0900
+++ dll.el	2023-09-09 06:54:37.229080637 +0900
@@ -89,7 +89,7 @@
   "Get the element of a NODE in a doubly linked list DLL.
 Args: DLL NODE."
 
-  (` (elib-node-data (, node))))
+   ` (elib-node-data  , node ) )
 
 
 (defun dll-create ()
