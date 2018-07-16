$NetBSD: patch-riece-unread.el,v 1.1 2018/07/16 05:56:10 mef Exp $

make-face of recent emacs accepts only one argument

--- lisp/riece-unread.el.orig	2011-04-04 15:47:48.000000000 +0900
+++ lisp/riece-unread.el	2018-07-16 10:00:32.885104499 +0900
@@ -60,8 +60,8 @@
 (defvar riece-channel-list-unread-face 'riece-channel-list-unread-face)
 
 (unless (riece-facep 'riece-modeline-unread-face)
-  (make-face 'riece-modeline-unread-face
-	     "Face used for displaying unread channels in modeline.")
+  (make-face 'riece-modeline-unread-face)
+;	     "Face used for displaying unread channels in modeline.")
   (if (featurep 'xemacs)
       (set-face-parent 'riece-modeline-unread-face 'modeline))
   (set-face-foreground 'riece-modeline-unread-face
