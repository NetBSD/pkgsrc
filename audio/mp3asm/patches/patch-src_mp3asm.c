$NetBSD: patch-src_mp3asm.c,v 1.1 2012/08/10 18:01:48 joerg Exp $

--- src/mp3asm.c.orig	2012-08-10 13:07:47.000000000 +0000
+++ src/mp3asm.c
@@ -25,6 +25,8 @@
 #include "parse.h"
 #include "utils.h"
 
+#define log logfile
+
 /* stream.c */
 
 extern stream_t *read_stream (FILE *file);
