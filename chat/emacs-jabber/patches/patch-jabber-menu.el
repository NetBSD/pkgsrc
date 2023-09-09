$NetBSD: patch-jabber-menu.el,v 1.1 2023/09/09 10:27:20 mef Exp $

wrong number of argumnet with emacs28

--- jabber-menu.el.orig	2013-05-08 08:51:18.000000000 +0900
+++ jabber-menu.el	2023-09-09 19:15:03.205372682 +0900
@@ -100,7 +100,7 @@ With prefix argument, remove it."
   (interactive "P")
   (setq jabber-display-menu (if remove nil t))
   (force-mode-line-update))
-(make-obsolete 'jabber-menu "set the variable `jabber-display-menu' instead.")
+(make-obsolete 'jabber-menu "set the variable `jabber-display-menu' instead." t)
 
 ;; This used to be:
 ;; (define-key-after global-map [menu-bar jabber-menu] ...)
