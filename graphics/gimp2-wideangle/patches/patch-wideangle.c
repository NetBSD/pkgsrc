$NetBSD: patch-wideangle.c,v 1.1 2013/02/26 11:12:19 joerg Exp $

--- wideangle.c.orig	2013-02-25 18:05:56.000000000 +0000
+++ wideangle.c
@@ -469,7 +469,7 @@ pixelAccessDelete(PixelAccess* pa)
   g_free(pa);
 }
 
-inline guchar*
+static inline guchar*
 pixelAccessAddress(PixelAccess* pa, int i, int j)
 {
   return pa->buffer[0] + pa->depth * (pa->width * (j + 1 - pa->tileMinY[0]) + (i + 1 - pa->tileMinX[0]));
