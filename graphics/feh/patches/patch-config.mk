$NetBSD: patch-config.mk,v 1.1.8.1 2012/05/06 00:16:05 tron Exp $

Fix man pages installation path

--- config.mk.orig	2012-03-25 11:16:59.000000000 +0000
+++ config.mk
@@ -6,7 +6,7 @@ PREFIX ?= /usr/local
 
 # Directories for manuals, executables, docs, data, etc.
 main_dir = ${DESTDIR}${PREFIX}
-man_dir = ${main_dir}/share/man
+man_dir = ${main_dir}/man
 bin_dir = ${main_dir}/bin
 doc_dir = ${main_dir}/share/doc/feh
 image_dir = ${main_dir}/share/feh/images
