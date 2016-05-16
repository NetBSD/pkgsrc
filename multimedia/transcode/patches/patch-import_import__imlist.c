$NetBSD: patch-import_import__imlist.c,v 1.1 2016/05/16 19:41:17 adam Exp $

Fix for ImageMagick v7.

--- import/import_imlist.c.orig	2016-05-15 13:04:14.000000000 +0000
+++ import/import_imlist.c
@@ -36,7 +36,7 @@
 #ifdef HAVE_BROKEN_WAND
 #include <wand/magick-wand.h>
 #else /* we have a SANE wand header */
-#include <wand/MagickWand.h>
+#include <MagickWand/MagickWand.h>
 #endif /* HAVE_BROKEN_WAND */
 
 #undef PACKAGE_BUGREPORT
