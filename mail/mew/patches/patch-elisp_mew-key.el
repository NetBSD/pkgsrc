$NetBSD: patch-elisp_mew-key.el,v 1.1 2023/02/13 13:32:43 taca Exp $

* Specify default icon directory for pkgsrc.

--- elisp/mew-key.el.orig	2023-02-13 03:51:46.000000000 +0000
+++ elisp/mew-key.el
@@ -626,7 +626,7 @@
 	(if (file-exists-p (expand-file-name file path))
 	    (throw 'loop (expand-file-name "etc" path)))))))
 
-(defvar mew-icon-directory (mew-which-mew-etc))
+(defvar mew-icon-directory "@ICONDIR@")
 
 (defvar mew-icon-separate nil)
 (defvar mew-icon-blank nil)
