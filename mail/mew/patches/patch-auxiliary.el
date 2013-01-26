$NetBSD: patch-auxiliary.el,v 1.1 2013/01/26 05:55:37 ryoon Exp $

https://github.com/kazu-yamamoto/Mew/commit/c469b771ca404221ebccaf07d5bdd944fe47a78f

--- auxiliary.el.orig	2012-04-16 03:18:13.000000000 +0000
+++ auxiliary.el
@@ -2,6 +2,7 @@
 (defvar ange-ftp-generate-anonymous-password nil)
 (defvar ange-ftp-tmp-name-template nil)
 (defvar auto-image-file-mode nil)
+(defvar bidi-paragraph-direction nil)
 (defvar coding-category-list nil)
 (defvar current-menubar nil)
 (defvar default-file-name-coding-system nil)
