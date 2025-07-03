$NetBSD: patch-src_dmstor.cpp,v 1.1 2025/07/03 23:40:38 gdt Exp $

Fix ctype usage.

Submitted to https://github.com/OSGeo/PROJ/pull/4539

--- src/dmstor.cpp.orig	2025-04-01 21:34:48.000000000 +0000
+++ src/dmstor.cpp
@@ -46,7 +46,7 @@ double dmstor_ctx(PJ_CONTEXT *ctx, const
      * It is possible that a really odd input (like lots of leading zeros)
      * could be truncated in copying into work.  But ...
      */
-    while ((isgraph(*p) || *p == DEG_SIGN1 || *p == DEG_SIGN2) && --n)
+    while ((isgraph((unsigned char) *p) || *p == DEG_SIGN1 || *p == DEG_SIGN2) && --n)
         *s++ = *p++;
     *s = '\0';
     int sign = *(s = work);
