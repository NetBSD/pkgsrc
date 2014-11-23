$NetBSD: patch-riece-ctlseq.el,v 1.1 2014/11/23 06:13:37 mef Exp $

In riece-ctlseq-make-face:
riece-ctlseq.el:104:27:Warning: `set-face-underline-p' is an obsolete function
    (as of 24.3); use `set-face-underline' instead.

--- lisp/riece-ctlseq.el~	2011-04-04 15:24:37.000000000 +0900
+++ lisp/riece-ctlseq.el	2014-06-15 21:57:58.000000000 +0900
@@ -102,7 +102,7 @@ To set up colors compatible with X-Chat 
     (if (plist-get attrs 'bold)
 	(make-face-bold face))
     (if (plist-get attrs 'underline)
-	(set-face-underline-p face t))
+	(set-face-underline face t))
     (if (setq foreground (plist-get attrs 'foreground))
 	(set-face-foreground face foreground))
     (if (setq background (plist-get attrs 'background))
