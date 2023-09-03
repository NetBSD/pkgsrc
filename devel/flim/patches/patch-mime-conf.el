$NetBSD: patch-mime-conf.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mime-conf.el	2005-07-06 11:09:04.000000000 +0900
+++ ./mime-conf.el	2023-08-31 08:29:38.602782237 +0900
@@ -1,4 +1,4 @@
-;;; mime-conf.el --- mailcap parser and MIME playback configuration
+;;; mime-conf.el --- mailcap parser and MIME playback configuration  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1997,1998,1999,2000,2004 Free Software Foundation, Inc.
 
@@ -34,7 +34,7 @@
 ;;;
 
 (defsubst mime-mailcap-skip-comment ()
-  (let ((chr (char-after (point))))
+  (let ((chr (following-char)))
     (when (and chr
 	       (or (= chr ?\n)
 		   (= chr ?#)))
@@ -50,8 +50,7 @@
       (let ((beg (match-beginning 0))
 	    (end (match-end 0)))
 	(goto-char end)
-	(buffer-substring beg end)
-	)))
+	(buffer-substring beg end))))
 
 
 ;;; @ typefield
@@ -60,17 +59,15 @@
 (defsubst mime-mailcap-look-at-type-field ()
   (let ((type (mime-mailcap-look-at-token)))
     (if type
-	(if (eq (char-after (point)) ?/)
+	(if (eq (following-char) ?/)
 	    (progn
 	      (forward-char)
 	      (let ((subtype (mime-mailcap-look-at-token)))
 		(if subtype
 		    (cons (cons 'type (intern type))
 			  (unless (string= subtype "*")
-			    (list (cons 'subtype (intern subtype)))
-			    )))))
-	  (list (cons 'type (intern type)))
-	  ))))
+			    (list (cons 'subtype (intern subtype))))))))
+	  (list (cons 'type (intern type)))))))
 
 
 ;;; @ field separator
@@ -87,29 +84,27 @@
 ;;;
 
 (defsubst mime-mailcap-look-at-schar ()
-  (let ((chr (char-after (point))))
+  (let ((chr (following-char)))
     (if (and chr
-	     (>= chr ? )
+	     (>= chr ?\s)
 	     (/= chr ?\;)
-	     (/= chr ?\\)
-	     )
+	     (/= chr ?\\))
 	(prog1
 	    chr
 	  (forward-char)))))
 
 (defsubst mime-mailcap-look-at-qchar ()
-  (when (eq (char-after (point)) ?\\)
+  (when (eq (following-char) ?\\)
     (prog2
 	(forward-char)
-	(char-after (point))
+	(following-char)
       (forward-char))))
 
 (defsubst mime-mailcap-look-at-mtext ()
   (let ((beg (point)))
     (while (or (mime-mailcap-look-at-qchar)
 	       (mime-mailcap-look-at-schar)))
-    (buffer-substring beg (point))
-    ))
+    (buffer-substring beg (point))))
 
 
 ;;; @ field
@@ -123,10 +118,8 @@
 			   (goto-char (match-end 0))
 			   (mime-mailcap-look-at-mtext))))
 	      (if value
-		  (cons (intern token) value)
-		))
-	  (list (intern token))
-	  ))))
+		  (cons (intern token) value)))
+	  (list (intern token))))))
 
 
 ;;; @ mailcap entry
@@ -139,10 +132,8 @@
 	      fields field)
 	  (when view
 	    (while (and (mime-mailcap-skip-field-separator)
-			(setq field (mime-mailcap-look-at-field))
-			)
-	      (setq fields (cons field fields))
-	      )
+			(setq field (mime-mailcap-look-at-field)))
+	      (setq fields (cons field fields)))
 	    (nconc type
 		   (list (cons 'view view))
 		   fields))))))
@@ -164,15 +155,12 @@
     (let (entries entry)
       (while (progn
 	       (while (mime-mailcap-skip-comment))
-	       (setq entry (mime-mailcap-look-at-entry))
-	       )
+	       (setq entry (mime-mailcap-look-at-entry)))
 	(setq entries (cons entry entries))
-	(forward-line)
-	)
+	(forward-line))
       (cond ((functionp order) (sort entries order))
 	    ((null order) (nreverse entries))
-	    (t entries)
-	    ))))
+	    (t entries)))))
 
 
 ;;;###autoload
@@ -189,8 +177,7 @@
       (setq filename mime-mailcap-file))
   (with-temp-buffer
     (insert-file-contents filename)
-    (mime-parse-mailcap-buffer (current-buffer) order)
-    ))
+    (mime-parse-mailcap-buffer (current-buffer) order)))
 
 
 ;;;###autoload
@@ -203,9 +190,9 @@
 SITUATION is an association-list about information of entity.  Its key
 may be:
 
-	'type		primary media-type
-	'subtype	media-subtype
-	'filename	filename
+	\\='type		primary media-type
+	\\='subtype	media-subtype
+	\\='filename	filename
 	STRING		parameter of Content-Type field"
   (let ((i 0)
 	(len (length mtext))
@@ -213,58 +200,52 @@
 	dest)
     (while (< i len)
       (let ((chr (aref mtext i)))
-	(cond ((eq chr ?%)
-	       (setq i (1+ i)
-		     chr (aref mtext i))
-	       (cond ((eq chr ?s)
-		      (let ((file (cdr (assq 'filename situation))))
-			(if (null file)
-			    (error "'filename is not specified in situation.")
-			  (setq dest (concat dest
-					     (substring mtext p (1- i))
-					     (shell-quote-argument file))
-				i (1+ i)
-				p i)
-			  )))
-		     ((eq chr ?t)
-		      (let ((type (or (mime-type/subtype-string
-				       (cdr (assq 'type situation))
-				       (cdr (assq 'subtype situation)))
-				      "text/plain")))
-			(setq dest (concat dest
-					   (substring mtext p (1- i))
-					   type)
-			      i (1+ i)
-			      p i)
-			))
-		     ((eq chr ?\{)
-		      (setq i (1+ i))
-		      (if (not (string-match "}" mtext i))
-			  (error "parse error!!!")
-			(let* ((me (match-end 0))
-			       (attribute (substring mtext i (1- me)))
-			       (parameter (cdr (assoc attribute situation))))
-			  (if (null parameter)
-			      (error "\"%s\" is not specified in situation."
-				     attribute)
-			    (setq dest (concat dest
-					       (substring mtext p (- i 2))
-					       parameter)
-				  i me
-				  p i)
-			    )
-			  )))
-		     (t (error "Invalid sequence `%%%c'." chr))
-		     ))
-	      ((eq chr ?\\)
-	       (setq dest (concat dest (substring mtext p i))
-		     p (1+ i)
-		     i (+ i 2))
-	       )
-	      (t (setq i (1+ i)))
-	      )))
-    (concat dest (substring mtext p))
-    ))
+	(cond
+	 ((eq chr ?%)
+	  (setq i (1+ i)
+		chr (aref mtext i))
+	  (cond
+	   ((eq chr ?s)
+	    (let ((file (cdr (assq 'filename situation))))
+	      (if file
+		  (setq file (shell-quote-argument file))
+		(error "'filename is not specified in situation."))
+	      (setq dest (concat dest
+				 (substring mtext p (1- i))
+				 ;; if the situation (wrongly) quotes
+				 ;; the argument, fix it.
+				 (if (eq ?' (aref mtext (- i 2)))
+				     (concat "'" file "'")
+				   file))
+		    i (1+ i)
+		    p i)))
+	   ((eq chr ?t)
+	    (let ((type (or (mime-type/subtype-string
+			     (cdr (assq 'type situation))
+			     (cdr (assq 'subtype situation)))
+			    "text/plain")))
+	      (setq dest (concat dest (substring mtext p (1- i)) type)
+		    i (1+ i)
+		    p i)))
+	   ((eq chr ?\{)
+	    (setq i (1+ i))
+	    (unless (string-match "}" mtext i)
+	      (error "parse error!!!"))
+	    (let* ((me (match-end 0))
+		   (attribute (substring mtext i (1- me)))
+		   (parameter (cdr (assoc attribute situation))))
+	      (unless parameter
+		(error "\"%s\" is not specified in situation." attribute))
+	      (setq dest (concat dest (substring mtext p (- i 2)) parameter)
+		    i me
+		    p i)))
+	   (t (error "Invalid sequence `%%%c'." chr))))
+	 ((eq chr ?\\)
+	  (setq dest (concat dest (substring mtext p i))
+		p (1+ i)
+		i (+ i 2)))
+	 (t (setq i (1+ i))))))
+    (concat dest (substring mtext p))))
 
 
 ;;; @ end
