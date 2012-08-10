$NetBSD: patch-src_frame.c,v 1.1 2012/08/10 18:01:48 joerg Exp $

--- src/frame.c.orig	2012-08-10 13:07:17.000000000 +0000
+++ src/frame.c
@@ -60,6 +60,8 @@ extern int print_data (unsigned char *da
 /* tag.c */
 extern int write_tag_v1 (stream_t *stream, FILE *file);
 
+#define log logfile
+
 /*
  * isheader: 
  *
