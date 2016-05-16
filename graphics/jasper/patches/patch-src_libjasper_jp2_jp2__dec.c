$NetBSD: patch-src_libjasper_jp2_jp2__dec.c,v 1.2 2016/05/16 14:03:40 he Exp $

Only output debug info if debuglevel >= 1.
Apply fix for oCERT-2014-012, from
https://bugzilla.redhat.com/show_bug.cgi?id=1173162

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jp2/jp2_dec.c.old	2016-03-31 14:47:00.000000000 +0200
+++ src/libjasper/jp2/jp2_dec.c	2016-03-31 14:48:20.000000000 +0200
@@ -293,7 +293,9 @@
 		  dec->colr->data.colr.iccplen);
 		assert(iccprof);
 		jas_iccprof_gethdr(iccprof, &icchdr);
-		jas_eprintf("ICC Profile CS %08x\n", icchdr.colorspc);
+		if (jas_getdbglevel() >= 1) {
+			jas_eprintf("ICC Profile CS %08x\n", icchdr.colorspc);
+		}
 		jas_image_setclrspc(dec->image, fromiccpcs(icchdr.colorspc));
 		dec->image->cmprof_ = jas_cmprof_createfromiccprof(iccprof);
 		assert(dec->image->cmprof_);
@@ -336,7 +338,7 @@
 	}
 
 	/* Allocate space for the channel-number to component-number LUT. */
-	if (!(dec->chantocmptlut = jas_malloc(dec->numchans * sizeof(uint_fast16_t)))) {
+	if (!(dec->chantocmptlut = jas_alloc2(dec->numchans, sizeof(uint_fast16_t)))) {
 		jas_eprintf("error: no memory\n");
 		goto error;
 	}
@@ -354,7 +356,7 @@
 			if (cmapent->map == JP2_CMAP_DIRECT) {
 				dec->chantocmptlut[channo] = channo;
 			} else if (cmapent->map == JP2_CMAP_PALETTE) {
-				lutents = jas_malloc(pclrd->numlutents * sizeof(int_fast32_t));
+				lutents = jas_alloc2(pclrd->numlutents, sizeof(int_fast32_t));
 				for (i = 0; i < pclrd->numlutents; ++i) {
 					lutents[i] = pclrd->lutdata[cmapent->pcol + i * pclrd->numchans];
 				}
@@ -386,6 +388,13 @@
 	/* Determine the type of each component. */
 	if (dec->cdef) {
 		for (i = 0; i < dec->numchans; ++i) {
+			/* Is the channel number reasonable? */
+			if (dec->cdef->data.cdef.ents[i].channo >= dec->numchans) {
+				jas_eprintf("error: invalid channel number in CDEF box\n");
+
+				goto error;
+
+			}
 			jas_image_setcmpttype(dec->image,
 			  dec->chantocmptlut[dec->cdef->data.cdef.ents[i].channo],
 			  jp2_getct(jas_image_clrspc(dec->image),
