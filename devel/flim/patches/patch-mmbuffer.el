$NetBSD: patch-mmbuffer.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mmbuffer.el	2005-07-06 11:09:04.000000000 +0900
+++ ./mmbuffer.el	2023-08-31 08:29:38.613469028 +0900
@@ -1,4 +1,4 @@
-;;; mmbuffer.el --- MIME entity module for binary buffer
+;;; mmbuffer.el --- MIME entity module for binary buffer  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1998,1999,2000 Free Software Foundation, Inc.
 
@@ -35,16 +35,14 @@
 		      body-start
 		      body-end))
 
-  (luna-define-internal-accessors 'mime-buffer-entity)
-  )
+  (luna-define-internal-accessors 'mime-buffer-entity))
 
 (luna-define-method initialize-instance :after ((entity mime-buffer-entity)
-						&rest init-args)
+						&rest _init-args)
   (or (mime-buffer-entity-buffer-internal entity)
       (mime-buffer-entity-set-buffer-internal
        entity (get-buffer (mime-entity-location-internal entity))))
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (let ((header-start
 	   (or (mime-buffer-entity-header-start-internal entity)
 	       (mime-buffer-entity-set-header-start-internal
@@ -64,8 +62,7 @@
 	  (setq header-end (point-min)
 		body-start (point-min)))
 	(mime-buffer-entity-set-header-end-internal entity header-end)
-	(mime-buffer-entity-set-body-start-internal entity body-start)
-	)
+	(mime-buffer-entity-set-body-start-internal entity body-start))
       (or (mime-entity-content-type-internal entity)
 	  (save-restriction
 	    (narrow-to-region header-start header-end)
@@ -73,15 +70,11 @@
 	     entity
 	     (let ((str (std11-fetch-field "Content-Type")))
 	       (if str
-		   (mime-parse-Content-Type str)
-		 )))
-	    ))
-      ))
+		   (mime-parse-Content-Type str))))))))
   entity)
 
 (luna-define-method mime-entity-name ((entity mime-buffer-entity))
-  (buffer-name (mime-buffer-entity-buffer-internal entity))
-  )
+  (buffer-name (mime-buffer-entity-buffer-internal entity)))
 
 
 ;;; @ entity
@@ -90,12 +83,10 @@
 (luna-define-method mime-insert-entity ((entity mime-buffer-entity))
   (insert-buffer-substring (mime-buffer-entity-buffer-internal entity)
 			   (mime-buffer-entity-header-start-internal entity)
-			   (mime-buffer-entity-body-end-internal entity))
-  )
+			   (mime-buffer-entity-body-end-internal entity)))
 
 (luna-define-method mime-write-entity ((entity mime-buffer-entity) filename)
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (let ((coding-system-for-write 'raw-text-dos))
       (write-region (mime-buffer-entity-header-start-internal entity)
 		    (mime-buffer-entity-body-end-internal entity)
@@ -110,21 +101,18 @@
 ;;;
 
 (luna-define-method mime-entity-body ((entity mime-buffer-entity))
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (buffer-substring (mime-buffer-entity-body-start-internal entity)
 		      (mime-buffer-entity-body-end-internal entity))))
 
 (luna-define-method mime-insert-entity-body ((entity mime-buffer-entity))
   (insert-buffer-substring (mime-buffer-entity-buffer-internal entity)
 			   (mime-buffer-entity-body-start-internal entity)
-			   (mime-buffer-entity-body-end-internal entity))
-  )
+			   (mime-buffer-entity-body-end-internal entity)))
 
 (luna-define-method mime-write-entity-body ((entity mime-buffer-entity)
 					    filename)
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (binary-write-decoded-region
      (mime-buffer-entity-body-start-internal entity)
      (mime-buffer-entity-body-end-internal entity)
@@ -135,8 +123,7 @@
 ;;;
 
 (luna-define-method mime-entity-content ((entity mime-buffer-entity))
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (mime-decode-string
      (buffer-substring (mime-buffer-entity-body-start-internal entity)
 		       (mime-buffer-entity-body-end-internal entity))
@@ -151,13 +138,11 @@
 
 (luna-define-method mime-write-entity-content ((entity mime-buffer-entity)
 					       filename)
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (mime-write-decoded-region (mime-buffer-entity-body-start-internal entity)
 			       (mime-buffer-entity-body-end-internal entity)
 			       filename
-			       (or (mime-entity-encoding entity) "7bit"))
-    ))
+			       (or (mime-entity-encoding entity) "7bit"))))
 
 
 ;;; @ header field
@@ -166,8 +151,7 @@
 (luna-define-method mime-entity-fetch-field :around
   ((entity mime-buffer-entity) field-name)
   (or (luna-call-next-method)
-      (save-excursion
-	(set-buffer (mime-buffer-entity-buffer-internal entity))
+      (with-current-buffer (mime-buffer-entity-buffer-internal entity)
 	(save-restriction
 	  (narrow-to-region (mime-buffer-entity-header-start-internal entity)
 			    (mime-buffer-entity-header-end-internal entity))
@@ -188,8 +172,7 @@
    (mime-buffer-entity-buffer-internal entity)
    (mime-buffer-entity-header-start-internal entity)
    (mime-buffer-entity-header-end-internal entity)
-   invisible-fields visible-fields)
-  )
+   invisible-fields visible-fields))
 
 
 ;;; @ header buffer
@@ -275,8 +258,7 @@
 	   (dc-ctl
 	    (if (eq (mime-content-type-subtype content-type) 'digest)
 		(make-mime-content-type 'message 'rfc822)
-	      (make-mime-content-type 'text 'plain)
-	      ))
+	      (make-mime-content-type 'text 'plain)))
 	   (body-start (mime-buffer-entity-body-start-internal entity))
 	   (body-end (mime-buffer-entity-body-end-internal entity)))
       (save-restriction
@@ -299,25 +281,20 @@
 		(save-restriction
 		  (narrow-to-region cb ce)
 		  (setq ret (mime-parse-message representation-type dc-ctl
-						entity (cons i node-id)))
-		  )
+						entity (cons i node-id))))
 		(setq children (cons ret children))
 		(goto-char (setq cb ncb))
-		(setq i (1+ i))
-		)
+		(setq i (1+ i)))
 	      (setq ce (point-max))
 	      (save-restriction
 		(narrow-to-region cb ce)
 		(setq ret (mime-parse-message representation-type dc-ctl
-					      entity (cons i node-id)))
-		)
+					      entity (cons i node-id))))
 	      (setq children (cons ret children))
-	      (mime-entity-set-children-internal entity (nreverse children))
-	      )
+	      (mime-entity-set-children-internal entity (nreverse children)))
 	  (mime-entity-set-content-type-internal
 	   entity (make-mime-content-type 'message 'x-broken))
-	  nil)
-	))))
+	  nil)))))
 
 (defun mmbuffer-parse-encapsulated (entity &optional external
 					   representation-type)
