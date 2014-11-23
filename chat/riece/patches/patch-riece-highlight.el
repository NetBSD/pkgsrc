$NetBSD: patch-riece-highlight.el,v 1.1 2014/11/23 06:13:37 mef Exp $

riece-highlight.el:197:4:Warning: make-face called with 2 arguments, but
    accepts only 1

--- lisp/riece-highlight.el~	2011-04-04 15:43:24.000000000 +0900
+++ lisp/riece-highlight.el	2014-06-15 21:59:23.000000000 +0900
@@ -194,8 +194,8 @@
   :group 'riece-highlight)
 
 (unless (riece-facep 'riece-modeline-current-face)
-  (make-face 'riece-modeline-current-face
-	     "Face used for displaying the current channel in modeline.")
+  (make-face 'riece-modeline-current-face)
+;;	     "Face used for displaying the current channel in modeline.")
   (if (featurep 'xemacs)
       (set-face-parent 'riece-modeline-current-face 'modeline))
   (set-face-foreground 'riece-modeline-current-face
