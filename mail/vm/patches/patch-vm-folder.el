$NetBSD: patch-vm-folder.el,v 1.1 2013/03/01 21:15:38 markd Exp $

--- vm-folder.el.orig	2003-05-30 19:53:21.000000000 +0000
+++ vm-folder.el
@@ -4049,7 +4049,8 @@ files."
   (use-local-map vm-mode-map)
   ;; if the user saves after M-x recover-file, let them get new
   ;; mail again.
-  (make-local-hook 'after-save-hook)
+  (if (fboundp 'make-local-hook)
+      (make-local-hook 'after-save-hook))
   (add-hook 'after-save-hook 'vm-unblock-new-mail)
   (and (vm-menu-support-possible-p)
        (vm-menu-install-menus))
