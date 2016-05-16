$NetBSD: patch-src_libjasper_base_jas__cm.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/base/jas_cm.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/base/jas_cm.c
@@ -704,8 +704,7 @@ static int jas_cmpxformseq_resize(jas_cm
 {
 	jas_cmpxform_t **p;
 	assert(n >= pxformseq->numpxforms);
-	p = (!pxformseq->pxforms) ? jas_malloc(n * sizeof(jas_cmpxform_t *)) :
-	  jas_realloc(pxformseq->pxforms, n * sizeof(jas_cmpxform_t *));
+	p = jas_realloc2(pxformseq->pxforms, n, sizeof(jas_cmpxform_t *));
 	if (!p) {
 		return -1;
 	}
@@ -889,13 +888,13 @@ static int jas_cmshapmatlut_set(jas_cmsh
 	jas_cmshapmatlut_cleanup(lut);
 	if (curv->numents == 0) {
 		lut->size = 2;
-		if (!(lut->data = jas_malloc(lut->size * sizeof(jas_cmreal_t))))
+		if (!(lut->data = jas_alloc2(lut->size, sizeof(jas_cmreal_t))))
 			goto error;
 		lut->data[0] = 0.0;
 		lut->data[1] = 1.0;
 	} else if (curv->numents == 1) {
 		lut->size = 256;
-		if (!(lut->data = jas_malloc(lut->size * sizeof(jas_cmreal_t))))
+		if (!(lut->data = jas_alloc2(lut->size, sizeof(jas_cmreal_t))))
 			goto error;
 		gamma = curv->ents[0] / 256.0;
 		for (i = 0; i < lut->size; ++i) {
@@ -903,7 +902,7 @@ static int jas_cmshapmatlut_set(jas_cmsh
 		}
 	} else {
 		lut->size = curv->numents;
-		if (!(lut->data = jas_malloc(lut->size * sizeof(jas_cmreal_t))))
+		if (!(lut->data = jas_alloc2(lut->size, sizeof(jas_cmreal_t))))
 			goto error;
 		for (i = 0; i < lut->size; ++i) {
 			lut->data[i] = curv->ents[i] / 65535.0;
@@ -953,7 +952,7 @@ static int jas_cmshapmatlut_invert(jas_c
 			return -1;
 		}
 	}
-	if (!(invlut->data = jas_malloc(n * sizeof(jas_cmreal_t))))
+	if (!(invlut->data = jas_alloc2(n, sizeof(jas_cmreal_t))))
 		return -1;
 	invlut->size = n;
 	for (i = 0; i < invlut->size; ++i) {
