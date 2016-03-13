$NetBSD: patch-src_libjasper_base_jas__image.c,v 1.1 2016/03/13 04:11:18 tnn Exp $

CVE-2016-2089 denial of service. Via Debian.

--- src/libjasper/base/jas_image.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/base/jas_image.c
@@ -426,6 +426,10 @@ int jas_image_readcmpt(jas_image_t *imag
 		return -1;
 	}
 
+	if (!data->rows_) {
+		return -1;
+	}
+
 	if (jas_matrix_numrows(data) != height || jas_matrix_numcols(data) != width) {
 		if (jas_matrix_resize(data, height, width)) {
 			return -1;
@@ -479,6 +483,10 @@ int jas_image_writecmpt(jas_image_t *ima
 		return -1;
 	}
 
+	if (!data->rows_) {
+		return -1;
+	}
+
 	if (jas_matrix_numrows(data) != height || jas_matrix_numcols(data) != width) {
 		return -1;
 	}
