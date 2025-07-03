$NetBSD: patch-src_oss.c,v 1.1 2025/07/03 15:46:59 wiz Exp $

Fix segfault when playing (PR pkg/49929).

--- src/oss.c.orig	2025-05-26 15:24:07.000000000 +0000
+++ src/oss.c
@@ -367,7 +367,7 @@ static size_t osswrite(
         size_t cbStride;
         int cbWritten;
 
-        cStride = cInput;
+        cStride = cInputRemaining;
         if (cStride > pPriv->cOutput) {
             cStride = pPriv->cOutput;
         }
