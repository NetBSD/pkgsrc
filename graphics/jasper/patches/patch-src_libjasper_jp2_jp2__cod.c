$NetBSD: patch-src_libjasper_jp2_jp2__cod.c,v 1.4 2020/09/14 17:47:14 adam Exp $

Only output debug info if debuglevel >= 1.

--- src/libjasper/jp2/jp2_cod.c.orig	2020-09-05 14:52:22.000000000 +0000
+++ src/libjasper/jp2/jp2_cod.c
@@ -828,11 +828,15 @@ static void jp2_cmap_dumpdata(const jp2_
 {
 	const jp2_cmap_t *cmap = &box->data.cmap;
 	unsigned int i;
-	fprintf(out, "numchans = %d\n", (int) cmap->numchans);
+	if (jas_getdbglevel() >= 1) {
+		fprintf(out, "numchans = %d\n", (int) cmap->numchans);
+	}
 	for (i = 0; i < cmap->numchans; ++i) {
 		const jp2_cmapent_t *ent = &cmap->ents[i];
-		fprintf(out, "cmptno=%d; map=%d; pcol=%d\n",
-		  (int) ent->cmptno, (int) ent->map, (int) ent->pcol);
+		if (jas_getdbglevel() >= 1) {
+			fprintf(out, "cmptno=%d; map=%d; pcol=%d\n",
+			  (int) ent->cmptno, (int) ent->map, (int) ent->pcol);
+		}
 	}
 }
 
