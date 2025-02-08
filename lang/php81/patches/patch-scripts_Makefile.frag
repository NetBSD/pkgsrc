$NetBSD: patch-scripts_Makefile.frag,v 1.1 2025/02/08 02:59:30 taca Exp $

* Adjust PHP directories.

--- scripts/Makefile.frag.orig	2024-11-19 15:24:51.000000000 +0000
+++ scripts/Makefile.frag
@@ -2,8 +2,8 @@
 # Build environment install
 #
 
-phpincludedir = $(includedir)/php
-phpbuilddir = $(libdir)/build
+phpincludedir = $(includedir)/php/$(PHP_API_VERS)
+phpbuilddir = $(prefix)/$(PHP_LIBDIR)/build
 
 BUILD_FILES = \
 	scripts/phpize.m4 \
