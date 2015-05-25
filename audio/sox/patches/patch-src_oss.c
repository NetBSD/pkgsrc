$NetBSD: patch-src_oss.c,v 1.1 2015/05/25 19:06:24 bsiegert Exp $

Fix segfault when playing (PR pkg/49929).
--- src/oss.c.orig	2015-05-25 18:58:54.000000000 +0000
+++ src/oss.c
@@ -369,7 +369,7 @@ static size_t osswrite(
         size_t cbStride;
         int cbWritten;
 
-        cStride = cInput;
+        cStride = cInputRemaining;
         if (cStride > pPriv->cOutput) {
             cStride = pPriv->cOutput;
         }
