$NetBSD: patch-lisp_guided-tour_guided-tour.el,v 1.1 2015/11/11 15:02:33 hauke Exp $

xemacs-nox11 does not sport a menu, but just returning nil will blow
up later - we need to at least return an empty tuple.

--- lisp/guided-tour/guided-tour.el.orig	2008-03-25 07:43:42.000000000 +0000
+++ lisp/guided-tour/guided-tour.el
@@ -79,8 +79,10 @@ removing any existing instances of the s
 
 ;; #### this probably should move to help.el or menubar-items.el
 (defun guided-tour-find-menubar-help-menu (&optional menubar)
-  "Return the Help submenu for MENUBAR if present, else nil."
-  (assoc "%_Help" (or menubar default-menubar)))
+  "Return the Help submenu for MENUBAR if present, else an empty menu."
+  (if (boundp 'default-menubar)
+      (assoc "%_Help" (or menubar default-menubar))
+    '(nil nil)))
 
 (defun guided-tour-about-xemacs-index (menu)
   "Return the (zero-based) index of the About XEmacs item in MENU.
