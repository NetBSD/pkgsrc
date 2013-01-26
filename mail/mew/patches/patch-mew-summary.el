$NetBSD: patch-mew-summary.el,v 1.1 2013/01/26 05:55:37 ryoon Exp $

https://github.com/kazu-yamamoto/Mew/commit/c469b771ca404221ebccaf07d5bdd944fe47a78f

--- mew-summary.el.orig	2012-04-16 03:18:13.000000000 +0000
+++ mew-summary.el
@@ -346,6 +346,8 @@ and return (beg . end)."
   (setq buffer-read-only t)
   (setq truncate-lines t)
   ;;
+  (if (boundp 'bidi-paragraph-direction)
+      (setq bidi-paragraph-direction 'left-to-right))
   (make-local-variable 'tab-width)
   (make-local-variable 'search-invisible)
   (setq search-invisible nil)
