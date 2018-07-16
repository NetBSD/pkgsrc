$NetBSD: patch-riece-history.el,v 1.1 2018/07/16 05:56:10 mef Exp $

make-face of recent emacs accepts only one argument

--- lisp/riece-history.el.orig	2011-04-04 15:24:37.000000000 +0900
+++ lisp/riece-history.el	2018-07-16 09:36:39.094852673 +0900
@@ -65,8 +65,8 @@
 (defvar riece-channel-list-history-face 'riece-channel-list-history-face)
 
 (unless (riece-facep 'riece-modeline-history-face)
-  (make-face 'riece-modeline-history-face
-	     "Face used for displaying history channels in modeline.")
+  (make-face 'riece-modeline-history-face)
+;	     "Face used for displaying history channels in modeline.")
   (if (featurep 'xemacs)
       (set-face-parent 'riece-modeline-history-face 'modeline))
   (set-face-foreground 'riece-modeline-history-face
