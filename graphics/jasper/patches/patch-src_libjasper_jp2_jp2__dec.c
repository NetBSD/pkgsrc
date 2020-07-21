$NetBSD: patch-src_libjasper_jp2_jp2__dec.c,v 1.5 2020/07/21 07:31:28 adam Exp $

Only output debug info if debuglevel >= 1.
And .. cast argument to jas_iccprof_createfrombuf() to match.

--- src/libjasper/jp2/jp2_dec.c.orig	2020-07-20 13:56:40.000000000 +0000
+++ src/libjasper/jp2/jp2_dec.c
@@ -297,14 +297,16 @@ jas_image_t *jp2_decode(jas_stream_t *in
 		jas_image_setclrspc(dec->image, jp2_getcs(&dec->colr->data.colr));
 		break;
 	case JP2_COLR_ICC:
-		iccprof = jas_iccprof_createfrombuf(dec->colr->data.colr.iccp,
+		iccprof = jas_iccprof_createfrombuf((jas_uchar *)dec->colr->data.colr.iccp,
 		  dec->colr->data.colr.iccplen);
 		if (!iccprof) {
 			jas_eprintf("error: failed to parse ICC profile\n");
 			goto error;
 		}
 		jas_iccprof_gethdr(iccprof, &icchdr);
-		jas_eprintf("ICC Profile CS %08x\n", icchdr.colorspc);
+		if (jas_getdbglevel() >= 1) {
+			jas_eprintf("ICC Profile CS %08x\n", icchdr.colorspc);
+		}
 		jas_image_setclrspc(dec->image, fromiccpcs(icchdr.colorspc));
 		dec->image->cmprof_ = jas_cmprof_createfromiccprof(iccprof);
 		if (!dec->image->cmprof_) {
