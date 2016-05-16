$NetBSD: patch-src_libjasper_base_jas__image.c,v 1.2 2016/05/16 14:03:40 he Exp $

CVE-2016-2089 denial of service. Via Debian.

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/base/jas_image.c.old	2016-03-31 14:47:00.000000000 +0200
+++ src/libjasper/base/jas_image.c	2016-03-31 14:47:50.000000000 +0200
@@ -142,7 +142,7 @@
 	image->inmem_ = true;
 
 	/* Allocate memory for the per-component information. */
-	if (!(image->cmpts_ = jas_malloc(image->maxcmpts_ *
+	if (!(image->cmpts_ = jas_alloc2(image->maxcmpts_,
 	  sizeof(jas_image_cmpt_t *)))) {
 		jas_image_destroy(image);
 		return 0;
@@ -426,6 +426,10 @@
 		return -1;
 	}
 
+	if (!data->rows_) {
+		return -1;
+	}
+
 	if (jas_matrix_numrows(data) != height || jas_matrix_numcols(data) != width) {
 		if (jas_matrix_resize(data, height, width)) {
 			return -1;
@@ -479,6 +483,10 @@
 		return -1;
 	}
 
+	if (!data->rows_) {
+		return -1;
+	}
+
 	if (jas_matrix_numrows(data) != height || jas_matrix_numcols(data) != width) {
 		return -1;
 	}
@@ -774,8 +782,7 @@
 	jas_image_cmpt_t **newcmpts;
 	int cmptno;
 
-	newcmpts = (!image->cmpts_) ? jas_malloc(maxcmpts * sizeof(jas_image_cmpt_t *)) :
-	  jas_realloc(image->cmpts_, maxcmpts * sizeof(jas_image_cmpt_t *));
+	newcmpts = jas_realloc2(image->cmpts_, maxcmpts, sizeof(jas_image_cmpt_t *));
 	if (!newcmpts) {
 		return -1;
 	}
