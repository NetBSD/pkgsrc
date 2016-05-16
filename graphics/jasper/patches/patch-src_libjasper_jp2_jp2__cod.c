$NetBSD: patch-src_libjasper_jp2_jp2__cod.c,v 1.2 2016/05/16 14:03:40 he Exp $

Only output debug info if debuglevel >= 1.

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jp2/jp2_cod.c.old	2016-03-31 14:47:00.000000000 +0200
+++ src/libjasper/jp2/jp2_cod.c	2016-03-31 14:48:20.000000000 +0200
@@ -372,7 +372,7 @@
 	jp2_bpcc_t *bpcc = &box->data.bpcc;
 	unsigned int i;
 	bpcc->numcmpts = box->datalen;
-	if (!(bpcc->bpcs = jas_malloc(bpcc->numcmpts * sizeof(uint_fast8_t)))) {
+	if (!(bpcc->bpcs = jas_alloc2(bpcc->numcmpts, sizeof(uint_fast8_t)))) {
 		return -1;
 	}
 	for (i = 0; i < bpcc->numcmpts; ++i) {
@@ -416,7 +416,7 @@
 		break;
 	case JP2_COLR_ICC:
 		colr->iccplen = box->datalen - 3;
-		if (!(colr->iccp = jas_malloc(colr->iccplen * sizeof(uint_fast8_t)))) {
+		if (!(colr->iccp = jas_alloc2(colr->iccplen, sizeof(uint_fast8_t)))) {
 			return -1;
 		}
 		if (jas_stream_read(in, colr->iccp, colr->iccplen) != colr->iccplen) {
@@ -453,7 +453,7 @@
 	if (jp2_getuint16(in, &cdef->numchans)) {
 		return -1;
 	}
-	if (!(cdef->ents = jas_malloc(cdef->numchans * sizeof(jp2_cdefchan_t)))) {
+	if (!(cdef->ents = jas_alloc2(cdef->numchans, sizeof(jp2_cdefchan_t)))) {
 		return -1;
 	}
 	for (channo = 0; channo < cdef->numchans; ++channo) {
@@ -766,7 +766,7 @@
 	unsigned int i;
 
 	cmap->numchans = (box->datalen) / 4;
-	if (!(cmap->ents = jas_malloc(cmap->numchans * sizeof(jp2_cmapent_t)))) {
+	if (!(cmap->ents = jas_alloc2(cmap->numchans, sizeof(jp2_cmapent_t)))) {
 		return -1;
 	}
 	for (i = 0; i < cmap->numchans; ++i) {
@@ -795,11 +795,15 @@
 	jp2_cmap_t *cmap = &box->data.cmap;
 	unsigned int i;
 	jp2_cmapent_t *ent;
-	fprintf(out, "numchans = %d\n", (int) cmap->numchans);
+	if (jas_getdbglevel() >= 1) {
+		fprintf(out, "numchans = %d\n", (int) cmap->numchans);
+	}
 	for (i = 0; i < cmap->numchans; ++i) {
 		ent = &cmap->ents[i];
-		fprintf(out, "cmptno=%d; map=%d; pcol=%d\n",
-		  (int) ent->cmptno, (int) ent->map, (int) ent->pcol);
+		if (jas_getdbglevel() >= 1) {
+			fprintf(out, "cmptno=%d; map=%d; pcol=%d\n",
+			  (int) ent->cmptno, (int) ent->map, (int) ent->pcol);
+		}
 	}
 }
 
@@ -828,10 +832,10 @@
 		return -1;
 	}
 	lutsize = pclr->numlutents * pclr->numchans;
-	if (!(pclr->lutdata = jas_malloc(lutsize * sizeof(int_fast32_t)))) {
+	if (!(pclr->lutdata = jas_alloc2(lutsize, sizeof(int_fast32_t)))) {
 		return -1;
 	}
-	if (!(pclr->bpc = jas_malloc(pclr->numchans * sizeof(uint_fast8_t)))) {
+	if (!(pclr->bpc = jas_alloc2(pclr->numchans, sizeof(uint_fast8_t)))) {
 		return -1;
 	}
 	for (i = 0; i < pclr->numchans; ++i) {
