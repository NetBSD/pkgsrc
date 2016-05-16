$NetBSD: patch-import_probe_im.c,v 1.1 2016/05/16 19:41:17 adam Exp $

Fix for ImageMagick v7.

--- import/probe_im.c.orig	2016-05-15 13:05:12.000000000 +0000
+++ import/probe_im.c
@@ -42,7 +42,7 @@
 # ifdef HAVE_BROKEN_WAND
 # include <wand/magick-wand.h>
 # else /* we have a SANE wand header */
-# include <wand/MagickWand.h>
+# include <MagickWand/MagickWand.h>
 # endif /* HAVE_BROKEN_WAND */
 
 # undef PACKAGE_BUGREPORT
