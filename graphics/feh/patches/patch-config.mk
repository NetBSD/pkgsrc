$NetBSD: patch-config.mk,v 1.1 2011/05/25 19:44:27 gls Exp $

--- config.mk.orig      2011-05-19 20:36:13.000000000 +0000
+++ config.mk
@@ -6,7 +6,7 @@ PREFIX ?= /usr/local

 # Directories for manuals, executables, docs, data, etc.
 main_dir = ${DESTDIR}${PREFIX}
-man_dir = ${main_dir}/share/man
+man_dir = ${main_dir}/man
 bin_dir = ${main_dir}/bin
 doc_dir = ${main_dir}/share/doc/feh
 image_dir = ${main_dir}/share/feh/images
