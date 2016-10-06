$NetBSD: patch-src_gd__webp.c,v 1.1.2.2 2016/10/06 18:25:40 bsiegert Exp $

Fix for CVE-2016-7568.

--- src/gd_webp.c.orig	2016-07-21 08:06:42.000000000 +0000
+++ src/gd_webp.c
@@ -126,6 +126,14 @@ void gdImageWebpCtx (gdImagePtr im, gdIO
 		quantization = 80;
 	}
 
+	if (overflow2(gdImageSX(im), 4)) {
+		return;
+	}
+
+	if (overflow2(gdImageSX(im) * 4, gdImageSY(im))) {
+		return;
+	}
+
 	argb = (uint8_t *)gdMalloc(gdImageSX(im) * 4 * gdImageSY(im));
 	if (!argb) {
 		return;
