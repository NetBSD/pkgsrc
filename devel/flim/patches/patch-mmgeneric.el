$NetBSD: patch-mmgeneric.el,v 1.1 2023/09/03 14:58:39 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mmgeneric.el	2005-07-06 11:09:05.000000000 +0900
+++ ./mmgeneric.el	2023-08-31 08:29:38.616263525 +0900
@@ -1,4 +1,4 @@
-;;; mmgeneric.el --- MIME generic entity module
+;;; mmgeneric.el --- MIME generic entity module  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1995,96,97,98,99,2000 Free Software Foundation, Inc.
 
@@ -24,11 +24,10 @@
 
 ;;; Code:
 
+(require 'mcharset)
+(require 'std11)
 (require 'luna)
-
-(eval-when-compile
-  (require 'eword-decode) ; mime-find-field-presentation-method
-  )
+(require 'eword-decode)
 
 
 ;;; @ MIME entity
@@ -50,8 +49,7 @@
 		      ;; for other fields
 		      original-header parsed-header))
 
-  (luna-define-internal-accessors 'mime-entity)
-  )
+  (luna-define-internal-accessors 'mime-entity))
 
 (defalias 'mime-entity-representation-type-internal 'luna-class-name)
 (defalias 'mime-entity-set-representation-type-internal 'luna-set-class-name)
@@ -70,8 +68,7 @@
 				    (mime-entity-content-type entity)
 				    "charset")
 				   default-mime-charset)
-			       'CRLF)
-   ))
+			       'CRLF)))
 
 
 ;;; @ for mm-backend
@@ -83,8 +80,7 @@
 (defmacro mm-define-backend (type &optional parents)
   `(luna-define-class ,(mm-expand-class-name type)
 		      ,(nconc (mapcar (lambda (parent)
-					(mm-expand-class-name parent)
-					)
+					(mm-expand-class-name parent))
 				      parents)
 			      '(mime-entity))))
 
@@ -96,8 +92,7 @@
 	  (cons (list (car spec)
 		      (mm-expand-class-name (nth 1 spec)))
 		(cdr args)))
-    `(luna-define-method ,name ,args ,@body)
-    ))
+    `(luna-define-method ,name ,args ,@body)))
 
 (put 'mm-define-method 'lisp-indent-function 'defun)
 
@@ -105,8 +100,7 @@
   (&define name ((arg symbolp)
 		 [&rest arg]
 		 [&optional ["&optional" arg &rest arg]]
-		 &optional ["&rest" arg]
-		 )
+		 &optional ["&rest" arg])
 	   def-body))
 
 
@@ -117,57 +111,48 @@
 ;; mechanism.  Please discuss in the emacs-mime mailing lists.
 
 (defun mime-visible-field-p (field-name visible-fields invisible-fields)
-  (or (catch 'found
-	(while visible-fields
-	  (let ((regexp (car visible-fields)))
-	    (if (string-match regexp field-name)
-		(throw 'found t)
-	      ))
-	  (setq visible-fields (cdr visible-fields))
-	  ))
-      (catch 'found
-	(while invisible-fields
-	  (let ((regexp (car invisible-fields)))
-	    (if (string-match regexp field-name)
-		(throw 'found nil)
-	      ))
-	  (setq invisible-fields (cdr invisible-fields))
-	  )
-	t)))
+  (let ((case-fold-search t))
+    (catch 'found
+      (while visible-fields
+	(when (string-match (car visible-fields) field-name)
+	  (throw 'found t))
+	(setq visible-fields (cdr visible-fields)))
+      (while invisible-fields
+	(when (string-match (car invisible-fields) field-name)
+	  (throw 'found nil))
+	(setq invisible-fields (cdr invisible-fields)))
+      t)))
 
 (defun mime-insert-header-from-buffer (buffer start end
 					      &optional invisible-fields
 					      visible-fields)
-  (let ((the-buf (current-buffer))
-	(mode-obj (mime-find-field-presentation-method 'wide))
-	field-decoder
-	f-b p f-e field-name len field field-body)
-    (save-excursion
-      (set-buffer buffer)
-      (save-restriction
-	(narrow-to-region start end)
-	(goto-char start)
-	(while (re-search-forward std11-field-head-regexp nil t)
-	  (setq f-b (match-beginning 0)
-		p (match-end 0)
-		field-name (buffer-substring f-b p)
-		len (string-width field-name)
-		f-e (std11-field-end))
-	  (when (mime-visible-field-p field-name
-				      visible-fields invisible-fields)
-	    (setq field (intern
-			 (capitalize (buffer-substring f-b (1- p))))
-		  field-body (buffer-substring p f-e)
-		  field-decoder (inline (mime-find-field-decoder-internal
-					 field mode-obj)))
-	    (with-current-buffer the-buf
-	      (insert field-name)
-	      (insert (if field-decoder
-			  (funcall field-decoder field-body len)
-			;; Don't decode
-			field-body))
-	      (insert "\n")
-	      )))))))
+  (let ((mode-obj (mime-find-field-presentation-method 'wide))
+	field-decoder f-b p field-name field-body result)
+    (with-current-buffer buffer
+      (goto-char start)
+      (while (re-search-forward std11-field-head-regexp end t)
+	(setq f-b (match-beginning 0)
+	      p (match-end 0)
+	      field-name (buffer-substring f-b p))
+	(when (mime-visible-field-p field-name
+				    visible-fields invisible-fields)
+	  (setq	field-body (buffer-substring p (std11-field-end end))
+		field-decoder
+		(mime-find-field-decoder-internal
+		 (intern (capitalize
+			  (buffer-substring-no-properties f-b (1- p))))
+		 mode-obj)
+		result
+		(cons "\n"
+		      (cons (if field-decoder
+				(funcall field-decoder
+					 field-body
+					 (string-width field-name))
+			      ;; Don't decode
+			      field-body)
+			    (cons field-name result)))))))
+    (when result
+      (apply #'insert (nreverse result)))))
 
 
 ;;; @ end
