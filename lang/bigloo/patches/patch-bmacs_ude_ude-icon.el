$NetBSD: patch-bmacs_ude_ude-icon.el,v 1.1 2025/06/30 13:09:36 ktnb Exp $

Must have the image library required before appending image-load-path

--- bmacs/ude/ude-icon.el.orig	2023-12-22 16:18:46.000000000 +0000
+++ bmacs/ude/ude-icon.el
@@ -17,6 +17,7 @@
 (provide 'ude-icon)
 (require 'bmacs-config)
 (require 'ude-custom)
+(require 'image)
 
 ;;; add to emacs image-load-path the directory containing the toolbar icons
 (add-to-list 'image-load-path (concat bmacs-lispdir 
