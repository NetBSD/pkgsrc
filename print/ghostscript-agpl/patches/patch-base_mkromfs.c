$NetBSD: patch-base_mkromfs.c,v 1.2 2020/03/24 16:34:45 adam Exp $

Fix build with _FORTIFY_SOURCE=2; it seems the arguments sometimes
overlap.

--- base/mkromfs.c.orig	2020-03-19 08:21:42.000000000 +0000
+++ base/mkromfs.c
@@ -2137,7 +2137,7 @@ ws(const byte *str, int len)
     if (len >= LINE_SIZE)
         exit(1);
 
-    memcpy(linebuf, str, len);
+    memmove(linebuf, str, len);
     flush_line_buf(len);
 }
 
