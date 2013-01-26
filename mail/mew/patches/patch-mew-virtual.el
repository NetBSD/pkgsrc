$NetBSD: patch-mew-virtual.el,v 1.1 2013/01/26 05:55:37 ryoon Exp $

https://github.com/kazu-yamamoto/Mew/commit/c469b771ca404221ebccaf07d5bdd944fe47a78f

--- mew-virtual.el.orig	2012-04-16 03:18:13.000000000 +0000
+++ mew-virtual.el
@@ -36,6 +36,8 @@
   (setq buffer-read-only t)
   (setq truncate-lines t)
   ;;
+  (if (boundp 'bidi-paragraph-direction)
+      (setq bidi-paragraph-direction 'left-to-right))
   (make-local-variable 'tab-width)
   (make-local-variable 'search-invisible)
   (setq search-invisible nil)
