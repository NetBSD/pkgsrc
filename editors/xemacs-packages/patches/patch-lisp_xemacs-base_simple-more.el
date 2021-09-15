$NetBSD: patch-lisp_xemacs-base_simple-more.el,v 1.1 2021/09/15 21:06:42 hauke Exp $

On 21.4, line-move only takes one argument.

--- lisp/xemacs-base/simple-more.el.orig	2015-12-14 21:30:40.000000000 +0000
+++ lisp/xemacs-base/simple-more.el
@@ -40,7 +40,11 @@ To ignore intangibility, bind `inhibit-p
 
     ;; Move by lines, if ARG is not 1 (the default).
     (if (/= arg 1)
-	(line-move (1- arg) 'noerror))
+	(if (and (featurep 'xemacs)
+		 (<= emacs-major-version 21)
+		 (<  emacs-minor-version 5)))
+	    (line-move (1- arg))
+	  (line-move (1- arg) 'noerror))
 
     ;; Move to beginning-of-line, ignoring fields and invisible text.
     (skip-chars-backward "^\n")
@@ -78,7 +82,11 @@ If point reaches the beginning or end of
       (let ((newpos
 	     (save-excursion
 	       (let ((goal-column 0))
-		 (line-move arg 'noerror)
+		 (if (and (featurep 'xemacs)
+			  (<= emacs-major-version 21)
+			  (<  emacs-minor-version 5))
+		     (line-move arg)
+		   (line-move arg 'noerror))
 		 (and
 		  ;; With bidi reordering, we may not be at bol,
 		  ;; so make sure we are.
