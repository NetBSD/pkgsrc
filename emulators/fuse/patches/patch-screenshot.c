$NetBSD: patch-screenshot.c,v 1.2 2013/06/14 20:53:04 wiz Exp $

Include Zlib header.

--- screenshot.c.orig	2013-05-16 20:26:23.000000000 +0000
+++ screenshot.c
@@ -47,6 +47,7 @@
 
 #ifdef USE_LIBPNG
 
+#include <zlib.h>
 #include <png.h>
 #ifdef HAVE_ZLIB_H
 #include <zlib.h>
