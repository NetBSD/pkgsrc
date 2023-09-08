$NetBSD: patch-elib-node.el,v 1.1 2023/09/08 22:08:18 mef Exp $

for emacs28

--- elib-node.el.orig	1995-12-11 09:50:53.000000000 +0900
+++ elib-node.el	2023-09-09 05:24:49.583969921 +0900
@@ -49,42 +49,41 @@
 (defmacro elib-node-create (left right data)
 
   ;; Create a tree node from LEFT, RIGHT and DATA.
-  (` (vector (, left) (, right) (, data))))
+    `(vector  , left   , right   , data) ) 
 
 
 (defmacro elib-node-left (node)
 
   ;; Return the left pointer of NODE.
-  (` (aref (, node) 0)))
+    `(aref  , node  0) )
 
 
 (defmacro elib-node-right (node)
 
   ;; Return the right pointer of NODE.
-  (` (aref (, node) 1)))
-
+    `(aref  , node  1) )
 
 (defmacro elib-node-data (node)
 
   ;; Return the data of NODE.
-  (` (aref (, node) 2)))
+    `(aref  , node  2) )
 
 
 (defmacro elib-node-set-left (node newleft)
 
   ;; Set the left pointer of NODE to NEWLEFT.
-  (` (aset (, node) 0 (, newleft))))
+    `(aset  , node  0  , newleft)  )
 
 
 (defmacro elib-node-set-right (node newright)
 
   ;; Set the right pointer of NODE to NEWRIGHT.
-  (` (aset (, node) 1 (, newright))))
+    `(aset  , node  1  , newright)  )
 
 
 (defmacro elib-node-set-data (node newdata)
   ;; Set the data of NODE to NEWDATA.
-  (` (aset (, node) 2 (, newdata))))
+    `(aset  , node  2  , newdata)  )
 
 
 
@@ -94,7 +93,7 @@
   ;; 
   ;; NODE is the node, and BRANCH is the branch.
   ;; 0 for left pointer, 1 for right pointer and 2 for the data."
-  (` (aref (, node) (, branch))))
+    `(aref  , node   , branch)  )
 
 
 (defmacro elib-node-set-branch (node branch newval)
@@ -104,6 +103,6 @@
   ;; NODE is the node, and BRANCH is the branch.
   ;; 0 for left pointer, 1 for the right pointer and 2 for the data.
   ;; NEWVAL is new value of the branch."
-  (` (aset (, node) (, branch) (, newval))))
+    `(aset  , node   , branch   , newval)  )
 
 ;;; elib-node.el ends here.
