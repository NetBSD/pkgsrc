$NetBSD: patch-src_file_file__default.c,v 1.1 2015/01/31 21:48:03 adam Exp $

Fix build on systems without fseeko().

--- src/file/file_default.c.orig	2015-01-31 21:40:11.000000000 +0000
+++ src/file/file_default.c
@@ -37,6 +37,10 @@
 #   define fseeko fseeko64
 #endif
 
+#ifndef fseeko
+#define fseeko fseek
+#endif
+
 static void _file_close(BDPLUS_FILE_H *file)
 {
     if (file) {
