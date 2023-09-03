$NetBSD: patch-mime-def.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mime-def.el	2007-09-06 17:04:09.000000000 +0900
+++ ./mime-def.el	2023-08-31 08:29:38.604422981 +0900
@@ -1,4 +1,4 @@
-;;; mime-def.el --- definition module about MIME -*- coding: iso-8859-4; -*-
+;;; mime-def.el --- definition module about MIME -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1995,96,97,98,99,2000,2001,2002,2003,2004,2005,2006
 ;;   Free Software Foundation, Inc.
@@ -33,7 +33,7 @@
 (eval-when-compile (require 'luna))	; luna-arglist-to-arguments
 
 (eval-and-compile
-  (defconst mime-library-product ["FLIM" (1 14 9) "GojÚ"]
+  (defconst mime-library-product ["FLIM-LB" (1 14 9) "Goj≈ç"]
     "Product name, version number and code name of MIME-library package."))
 
 (defmacro mime-product-name (product)
@@ -96,8 +96,7 @@
   '(("X-Nsubject" . iso-2022-jp-2)
     ("Newsgroups" . nil)
     ("Message-ID" . nil)
-    (t            . mime)
-    )
+    (t            . mime))
   "*Alist to specify field encoding method.
 Its key is field-name, value is encoding method.
 
@@ -130,9 +129,6 @@
 (defsubst regexp-or (&rest args)
   (concat "\\(" (mapconcat (function identity) args "\\|") "\\)"))
 
-(or (fboundp 'char-int)
-    (defalias 'char-int 'identity))
-
 
 ;;; @ MIME constants
 ;;;
@@ -142,8 +138,14 @@
 (defconst mime-token-regexp
   (concat "[^" mime-tspecial-char-list "\000-\040]+"))
 (defconst mime-attribute-char-regexp
-  (concat "[^" mime-tspecial-char-list "\000-\040"
+  (concat "[^" mime-tspecial-char-list
+	  "*'%"				; introduced in RFC 2231.
+	  "\000-\040"
+	  "]"))
+(defconst mime-non-attribute-char-regexp
+  (concat "[" mime-tspecial-char-list
 	  "*'%"				; introduced in RFC 2231.
+	  "\000-\040\177-\377"		; non-printable, non-US-ASCII.
 	  "]"))
 
 (defconst mime-charset-regexp
@@ -151,7 +153,8 @@
 	  "*'%"				; should not include "%"?
 	  "]+"))
 
-;; More precisely, length of "[A-Za-z]+" is limited to at most 8.
+;; More precisely, length of each "[A-Za-z]+" is limited to at most 8.
+;; See RFC 3066 "Tags for the Identification of Languages".
 ;; (defconst mime-language-regexp "[A-Za-z]+\\(-[A-Za-z]+\\)*")
 (defconst mime-language-regexp "[-A-Za-z]+")
 
@@ -275,7 +278,8 @@
 
 (make-variable-buffer-local 'mime-message-structure)
 
-(make-obsolete-variable 'mime-message-structure "should not use it.")
+(make-obsolete-variable 'mime-message-structure
+			"should not use it." "26 May 1999")
 
 
 ;;; @ for mel-backend
@@ -294,9 +298,7 @@
 	   `((defun ,name ,args
 	       ,@rest
 	       (funcall (mel-find-function ',name ,(car (last args)))
-			,@(luna-arglist-to-arguments (butlast args)))
-	       )))
-     ))
+			,@(luna-arglist-to-arguments (butlast args))))))))
 
 (put 'mel-define-service 'lisp-indent-function 'defun)
 
@@ -310,10 +312,8 @@
 	  (while (and rest
 		      (progn
 			(require (car rest))
-			(null (setq f (intern-soft encoding ob-array)))
-			))
-	    (setq rest (cdr rest))
-	    )
+			(null (setq f (intern-soft encoding ob-array)))))
+	    (setq rest (cdr rest)))
 	  f))))
 
 (defsubst mel-copy-method (service src-backend dst-backend)
@@ -323,8 +323,7 @@
     (when f
       (setq sym (intern dst-backend oa))
       (or (fboundp sym)
-	  (fset sym (symbol-function f))
-	  ))))
+	  (fset sym (symbol-function f))))))
        
 (defsubst mel-copy-backend (src-backend dst-backend)
   (let ((services mel-service-list))
@@ -338,8 +337,7 @@
 Each parent must be backend name (string)."
   (cons 'progn
 	(mapcar (lambda (parent)
-		  `(mel-copy-backend ,parent ,type)
-		  )
+		  `(mel-copy-backend ,parent ,type))
 		parents)))
 
 (defmacro mel-define-method (name args &rest body)
@@ -380,19 +378,25 @@
 	 (class (nth 1 specializer)))
     `(progn
        (define-function ,function
-	 (intern ,class ,(intern (format "%s-obarray" name))))
-       )))
+	 (intern ,class ,(intern (format "%s-obarray" name)))))))
 
-(defvar base64-dl-module
-  (if (and (fboundp 'base64-encode-string)
-	   (subrp (symbol-function 'base64-encode-string)))
-      nil
-    (if (fboundp 'dynamic-link)
-	(let ((path (expand-file-name "base64.so" exec-directory)))
-	  (and (file-exists-p path)
-	       path)
-	  ))))
+(defvar base64-dl-module nil)
 
+(defsubst mime-charset-decode-string (string charset &optional lbt)
+  "Decode the STRING as MIME CHARSET.
+Buffer's multibyteness is ignored."
+  (let ((cs (mime-charset-to-coding-system charset lbt)))
+    (if cs
+	(decode-coding-string string cs)
+      string)))
+
+(defsubst mime-charset-encode-string (string charset &optional lbt)
+  "Encode the STRING as MIME CHARSET.
+Buffer's multibyteness is ignored."
+  (let ((cs (mime-charset-to-coding-system charset lbt)))
+    (if cs
+	(encode-coding-string string cs)
+      string)))
 
 ;;; @ end
 ;;;
