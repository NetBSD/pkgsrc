$NetBSD: patch-src_gd__crop.c,v 1.1 2016/06/30 09:00:18 taca Exp $

Fix for CVE-2016-6128 from
https://github.com/libgd/libgd/commit/1ccfe21e14c4d18336f9da8515cd17db88c3de61.

--- src/gd_crop.c.orig	2015-01-06 09:16:03.000000000 +0000
+++ src/gd_crop.c
@@ -136,6 +136,10 @@ BGD_DECLARE(gdImagePtr) gdImageCropThres
 		return NULL;
 	}
 
+	if (color < 0 || (!gdImageTrueColor(im) && color >= gdImageColorsTotal(im))) {
+		return NULL;
+	}
+
 	/* TODO: Add gdImageGetRowPtr and works with ptr at the row level
 	 * for the true color and palette images
 	 * new formats will simply work with ptr
