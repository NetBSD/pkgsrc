$NetBSD: patch-rw_readWriteXWD.c,v 1.1 2011/12/05 22:48:59 joerg Exp $

--- rw/readWriteXWD.c.orig	2011-12-05 20:25:22.000000000 +0000
+++ rw/readWriteXWD.c
@@ -27,6 +27,7 @@
 
 #include "image.h"
 #include <stdio.h>
+#include <string.h>
 
 #include <X11/XWDFile.h>
 
@@ -59,7 +60,7 @@ void *calloc(int, int);
 #define ZPixmap		2
 
 #define StaticGray	0
-#define GrayScale	1
+#define GrayScale2	1
 #define StaticColor	2
 #define PseudoColor	3
 #define TrueColor	4
@@ -559,7 +560,7 @@ Image *
 	    scale = 256 / (1 << hdr.bits_per_pixel) - 1;
 	}
 	break;
-    default:			/* StaticColor, PseudoColor, GrayScale */
+    default:			/* StaticColor, PseudoColor, GrayScale2 */
 	if (image != NULL)
 	    break;
 	image = ImageNew(hdr.pixmap_width, hdr.pixmap_height);
@@ -586,7 +587,7 @@ Image *
     for (y = 0; y < image->height; y++) {
 	switch (hdr.visual_class) {
 	case StaticGray:
-	case GrayScale:
+	case GrayScale2:
 	case StaticColor:
 	case PseudoColor:
 	    for (x = 0; x < image->width; x++) {
