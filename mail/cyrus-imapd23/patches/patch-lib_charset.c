$NetBSD: patch-lib_charset.c,v 1.1 2012/11/23 12:35:57 joerg Exp $

--- lib/charset.c.orig	2012-11-21 16:19:54.000000000 +0000
+++ lib/charset.c
@@ -861,7 +861,7 @@ void mimeheader_cat(struct convert_rock 
     int len;
     char *res;
 
-    if (!s) return 0;
+    if (!s) return;
 
     /* set up the conversion path */
     input = table_init(0, target);
