$NetBSD: patch-src_libjasper_jp2_jp2__dec.c,v 1.1.2.2 2015/02/19 21:18:52 tron Exp $

Only output debug info if debuglevel >= 1.
Apply fix for oCERT-2014-012, from
https://bugzilla.redhat.com/show_bug.cgi?id=1173162

--- src/libjasper/jp2/jp2_dec.c.orig	2004-02-09 01:34:40.000000000 +0000
+++ src/libjasper/jp2/jp2_dec.c
@@ -293,7 +293,9 @@ jas_image_t *jp2_decode(jas_stream_t *in
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
@@ -386,6 +388,13 @@ jas_image_t *jp2_decode(jas_stream_t *in
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
