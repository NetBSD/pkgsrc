$NetBSD: patch-src_sunaudio.c,v 1.1 2015/05/25 19:06:24 bsiegert Exp $

Fix segfault when playing (PR pkg/49929).
--- src/sunaudio.c.orig	2015-05-25 19:00:39.000000000 +0000
+++ src/sunaudio.c
@@ -443,7 +443,7 @@ static size_t sunwrite(
         size_t cbStride;
         int cbWritten;
 
-        cStride = cInput;
+        cStride = cInputRemaining;
         if (cStride > pPriv->cOutput) {
             cStride = pPriv->cOutput;
         }
