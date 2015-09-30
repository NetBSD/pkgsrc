$NetBSD: patch-lisp_vc_vc.el,v 1.1 2015/09/30 10:11:45 hauke Exp $

Work around '(error/warning) Error in process sentinel: (error Marker
does not point anywhere)' which shadows the buffer worked on, see
<http://xemacs-beta.xemacs.narkive.com/khCckwa3/package-maintainers-heads-up>

Supposedly fixed upstream, whereever that is these days, see
<http://tracker.xemacs.org/XEmacs/its/issue682>

--- lisp/vc/vc.el.orig	2009-12-28 19:51:30.000000000 +0000
+++ lisp/vc/vc.el
@@ -959,7 +959,8 @@ Else, add CODE to the process' sentinel.
 	(set-process-sentinel proc
 	  `(lambda (p s)
 	     (with-current-buffer ',(current-buffer)
-	       (goto-char (process-mark p))
+	       ;;(goto-char (process-mark p))
+	       (ignore-errors (goto-char (process-mark p)))
 	       ,@(append (cdr (cdr (cdr ;strip off `with-current-buffer buf
                                         ;             (goto-char...)'
 			   (car (cdr (cdr ;strip off `lambda (p s)'
