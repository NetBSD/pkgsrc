$NetBSD: patch-cookie.el,v 1.1 2023/09/08 22:08:18 mef Exp $

for emacs28

--- cookie.el.orig	1995-12-11 09:50:54.000000000 +0900
+++ cookie.el	2023-09-09 06:14:56.369095803 +0900
@@ -139,13 +139,13 @@
 
   (let ((old-buffer (make-symbol "old-buffer"))
 	(hnd (make-symbol "collection")))
-    (` (let* (((, old-buffer) (current-buffer))
-	      ((, hnd) (, collection))
-	      (dll (elib-collection->dll (, hnd))))
-	 (set-buffer (elib-collection->buffer (, hnd)))
+     ` (let* (( , old-buffer  (current-buffer))
+	      ( , hnd   , collection )
+	      (dll (elib-collection->dll  , hnd ) )
+	 (set-buffer (elib-collection->buffer  , hnd ))
 	 (unwind-protect
-	     (progn (,@ forms))
-	   (set-buffer (, old-buffer)))))))
+	     (progn  ,@ forms )
+	   (set-buffer  , old-buffer )))))
 
 
 (put 'elib-set-buffer-bind-dll-let* 'lisp-indent-hook 2)
@@ -160,14 +160,14 @@
 
   (let ((old-buffer (make-symbol "old-buffer"))
 	(hnd (make-symbol "collection")))
-    (` (let* (((, old-buffer) (current-buffer))
-	      ((, hnd) (, collection))
-	      (dll (elib-collection->dll (, hnd)))
-	      (,@ varlist))
-	 (set-buffer (elib-collection->buffer (, hnd)))
+     ` (let* (( , old-buffer  (current-buffer))
+	      ( , hnd   , collection )
+	      (dll (elib-collection->dll  , hnd ))
+	       ,@ varlist )
+	 (set-buffer (elib-collection->buffer  , hnd ))
 	 (unwind-protect
-	     (progn (,@ forms))
-	   (set-buffer (, old-buffer)))))))
+	     (progn  ,@ forms )
+	   (set-buffer  , old-buffer) )))))
 
 
 (defmacro elib-filter-hf (collection tin)
@@ -179,12 +179,12 @@
 
   (let ((tempvar (make-symbol "tin"))
 	(tmpcoll (make-symbol "tmpcollection")))
-    (` (let (((, tempvar) (, tin))
-	     ((, tmpcoll) (, collection)))
-	 (if (or (eq (, tempvar) (elib-collection->header (, tmpcoll)))
-		 (eq (, tempvar) (elib-collection->footer (, tmpcoll))))
+     ` (let (( , tempvar   , tin) 
+	     ( , tmpcoll   , collection) )
+	 (if (or (eq  , tempvar  (elib-collection->header  , tmpcoll ))
+		 (eq  , tempvar  (elib-collection->footer  , tmpcoll )))
 	     nil
-	   (, tempvar))))))
+	    , tempvar))) )
 
 
 
