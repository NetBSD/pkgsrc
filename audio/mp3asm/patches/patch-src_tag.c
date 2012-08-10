$NetBSD: patch-src_tag.c,v 1.1 2012/08/10 18:01:49 joerg Exp $

--- src/tag.c.orig	2012-08-10 13:07:07.000000000 +0000
+++ src/tag.c
@@ -25,6 +25,7 @@
 #include "utils.h"
 #include "frame.h"
 
+#define log logfile
 
 /* utils.c */
 extern void *tmalloc (size_t size);
