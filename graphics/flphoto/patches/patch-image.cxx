$NetBSD: patch-image.cxx,v 1.1 2011/07/08 20:48:28 wiz Exp $

Fix build with png-1.5.

--- image.cxx.orig	2003-10-22 03:49:41.000000000 +0000
+++ image.cxx
@@ -91,6 +91,7 @@ extern "C" {
 #endif // HAVE_LIBJPEG
 
 #ifdef HAVE_LIBPNG
+#  include <zlib.h>
 #  include <png.h>
 #endif // HAVE_LIBPNG
 
