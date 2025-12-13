$NetBSD: patch-src_osgPlugins_zip_unzip.cpp,v 1.1 2025/12/13 09:40:51 vins Exp $

Prevent conflicting types with system zlib.

--- src/osgPlugins/zip/unzip.cpp.orig	2020-01-31 11:03:07.000000000 +0000
+++ src/osgPlugins/zip/unzip.cpp
@@ -399,8 +399,9 @@ typedef unsigned int   uInt;  // 16 bits
 typedef unsigned long  uLong; // 32 bits or more
 typedef void *voidpf;
 typedef void     *voidp;
-typedef long z_off_t;
-
+#ifndef z_off_t
+#define z_off_t long
+#endif
 
 
 
