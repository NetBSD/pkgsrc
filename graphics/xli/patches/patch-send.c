$NetBSD: patch-send.c,v 1.1 2024/04/17 14:11:05 nat Exp $

Fix overflow caused by typo at bit depths < 8.

--- send.c.orig	2024-04-17 02:27:43.661453625 +0000
+++ send.c
@@ -687,7 +687,7 @@ XImageInfo *imageToXImage(Display *disp,
 	byte *src;
 
 	src = image->data;
-        for (y = 0; y < image->height; ++x) {
+        for (y = 0; y < image->height; ++y) {
 	  for (x = 0; x < image->width; ++x) {
 	    XPutPixel(xii->ximage, x, y,
 	      xii->index[c + memToVal(src, image->pixlen)]);
