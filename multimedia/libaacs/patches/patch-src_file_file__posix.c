$NetBSD: patch-src_file_file__posix.c,v 1.2 2014/01/09 10:25:14 wiz Exp $

Fix build on systems without fseeko/ftello.

--- src/file/file_posix.c.orig	2013-12-18 09:21:16.000000000 +0000
+++ src/file/file_posix.c
@@ -33,6 +33,14 @@
 #include <stdio.h>
 #include <stdlib.h>
 
+#ifndef ftello
+#define ftello ftell
+#endif
+
+#ifndef fseeko
+#define fseeko fseek
+#endif
+
 static void file_close_linux(AACS_FILE_H *file)
 {
     if (file) {
