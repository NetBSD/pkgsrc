$NetBSD: patch-src_stream.c,v 1.1 2012/08/10 18:01:48 joerg Exp $

--- src/stream.c.orig	2012-08-10 13:07:34.000000000 +0000
+++ src/stream.c
@@ -26,6 +26,8 @@
 #include "stream.h"
 #include "frame.h"
 
+#define log logfile
+
 /* utils.c */
 
 extern void *tmalloc (size_t size);
