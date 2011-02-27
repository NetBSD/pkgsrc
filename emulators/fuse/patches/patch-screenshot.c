$NetBSD: patch-screenshot.c,v 1.1 2011/02/27 12:33:56 adam Exp $

Include Zlib header.

--- screenshot.c.orig	2011-02-27 12:30:57.000000000 +0000
+++ screenshot.c
@@ -48,6 +48,7 @@
 
 #ifdef USE_LIBPNG
 
+#include <zlib.h>
 #include <png.h>
 
 static int get_rgb32_data( libspectrum_byte *rgb32_data, size_t stride,
