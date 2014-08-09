$NetBSD: patch-src_file_file__posix.c,v 1.1 2014/08/09 20:19:35 wiz Exp $

Use ftell/fseek if ftello/fseeko are not defined.

--- src/file/file_posix.c.orig	2014-05-27 10:34:15.000000000 +0000
+++ src/file/file_posix.c
@@ -30,6 +30,14 @@
 #include <stdlib.h>
 #include <inttypes.h>
 
+#ifndef ftello
+#define ftello ftell
+#endif
+
+#ifndef fseeko
+#define fseeko fseek
+#endif
+
 static void file_close_linux(BD_FILE_H *file)
 {
     if (file) {
