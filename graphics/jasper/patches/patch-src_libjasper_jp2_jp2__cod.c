$NetBSD: patch-src_libjasper_jp2_jp2__cod.c,v 1.3 2016/12/16 09:44:44 he Exp $

Only output debug info if debuglevel >= 1.

--- src/libjasper/jp2/jp2_cod.c.orig	2016-11-16 15:03:41.000000000 +0000
+++ src/libjasper/jp2/jp2_cod.c
@@ -808,11 +808,15 @@ static void jp2_cmap_dumpdata(jp2_box_t 
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
+				(int) ent->cmptno, (int) ent->map, (int) ent->pcol);
+		}
 	}
 }
 
