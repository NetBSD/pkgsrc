$NetBSD: patch-mime.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mime.el	2005-07-06 11:09:04.000000000 +0900
+++ ./mime.el	2023-08-31 08:29:38.612092624 +0900
@@ -1,4 +1,4 @@
-;;; mime.el --- MIME library module
+;;; mime.el --- MIME library module  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1998,1999,2000,2001,2003 Free Software Foundation, Inc.
 
@@ -25,6 +25,7 @@
 ;;; Code:
 
 (require 'alist)
+(require 'luna)
 (require 'std11)
 (require 'mime-def)
 (require 'eword-decode)
@@ -61,9 +62,7 @@
   "Parse STRING as cid URI.")
 
 (autoload 'mime-parse-buffer "mime-parse"
-  "Parse BUFFER as a MIME message.")
-
-)
+  "Parse BUFFER as a MIME message."))
 
 (autoload 'mime-encode-field-body "eword-encode"
   "Encode FIELD-BODY as FIELD-NAME, and return the result.")
@@ -110,9 +109,7 @@
 	message
       (let ((rc (nth sn (mime-entity-children message))))
 	(if rc
-	    (mime-find-entity-from-number (cdr entity-number) rc)
-	  ))
-      )))
+	    (mime-find-entity-from-number (cdr entity-number) rc))))))
 
 (defun mime-find-entity-from-node-id (entity-node-id message)
   "Return entity from ENTITY-NODE-ID in MESSAGE."
@@ -273,8 +270,7 @@
       (let ((ret (mime-entity-fetch-field entity "Content-Type")))
 	(if ret
 	    (mime-entity-set-content-type-internal
-	     entity (mime-parse-Content-Type ret))
-	  ))))
+	     entity (mime-parse-Content-Type ret))))))
 
 (defun mime-entity-content-disposition (entity)
   "Return content-disposition of ENTITY."
@@ -282,8 +278,7 @@
       (let ((ret (mime-entity-fetch-field entity "Content-Disposition")))
 	(if ret
 	    (mime-entity-set-content-disposition-internal
-	     entity (mime-parse-Content-Disposition ret))
-	  ))))
+	     entity (mime-parse-Content-Disposition ret))))))
 
 (defun mime-entity-encoding (entity &optional default-encoding)
   "Return content-transfer-encoding of ENTITY.
@@ -295,8 +290,7 @@
 	(mime-entity-set-encoding-internal
 	 entity
 	 (or (and ret (mime-parse-Content-Transfer-Encoding ret))
-	     default-encoding "7bit"))
-	)))
+	     default-encoding "7bit")))))
 
 (defvar mime-field-parser-alist
   '((Return-Path	. std11-parse-route-addr)
@@ -324,8 +318,7 @@
     (In-Reply-To	. std11-parse-msg-ids)
     (References		. std11-parse-msg-ids)
     
-    (Content-Id		. mime-parse-msg-id)
-    ))
+    (Content-Id		. mime-parse-msg-id)))
 
 (defun mime-entity-read-field (entity field-name)
   (let ((sym (if (symbolp field-name)
@@ -334,14 +327,11 @@
 		   (setq field-name (symbol-name field-name)))
 	       (intern (capitalize field-name)))))
     (cond ((eq sym 'Content-Type)
-	   (mime-entity-content-type entity)
-	   )
+	   (mime-entity-content-type entity))
 	  ((eq sym 'Content-Disposition)
-	   (mime-entity-content-disposition entity)
-	   )
+	   (mime-entity-content-disposition entity))
 	  ((eq sym 'Content-Transfer-Encoding)
-	   (mime-entity-encoding entity)
-	   )
+	   (mime-entity-encoding entity))
 	  (t
 	   (let* ((header (mime-entity-parsed-header-internal entity))
 		  (field (cdr (assq sym header))))
@@ -355,8 +345,7 @@
 			   (if parser
 			       (funcall parser
 					(eword-lexical-analyze field-body))
-			     (mime-decode-field-body field-body sym 'plain)
-			     ))
+			     (mime-decode-field-body field-body sym 'plain)))
 		     (mime-entity-set-parsed-header-internal
 		      entity (put-alist sym field header))
 		     field))))))))
@@ -385,22 +374,20 @@
 	(mime-insert-entity-body entity)
 	(if (re-search-forward "^begin [0-9]+ " nil t)
 	    (if (looking-at ".+$")
-		(buffer-substring (match-beginning 0)(match-end 0))
-	      )))))
+		(buffer-substring (match-beginning 0)(match-end 0)))))))
 
 (defun mime-entity-filename (entity)
   "Return filename of ENTITY."
   (or (mime-entity-uu-filename entity)
-      (let ((ret (mime-content-disposition-filename
-		  (mime-entity-content-disposition entity))))
-	(if (and mime-header-accept-quoted-encoded-words
-		 ret)
+      (let ((ret (or (mime-content-disposition-filename
+		      (mime-entity-content-disposition entity))
+		     (cdr (let ((param (mime-content-type-parameters
+					(mime-entity-content-type entity))))
+			    (or (assoc "name" param)
+				(assoc "x-name" param)))))))
+	(if ret
 	    (eword-decode-string ret)
-	  ret))
-      (cdr (let ((param (mime-content-type-parameters
-			 (mime-entity-content-type entity))))
-	     (or (assoc "name" param)
-		 (assoc "x-name" param))))))
+	  ""))))
 
 
 (defsubst mime-entity-media-type (entity)
