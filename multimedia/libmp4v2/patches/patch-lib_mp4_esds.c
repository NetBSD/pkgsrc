$NetBSD: patch-lib_mp4_esds.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/esds.c.orig	2017-09-25 14:52:45.360067272 +0000
+++ lib/mp4/esds.c
@@ -66,7 +66,7 @@ int quicktime_esds_delete(quicktime_esds
 	return 0;
 }
 
-int quicktime_esds_dump(quicktime_esds_t *esds)
+void quicktime_esds_dump(quicktime_esds_t *esds)
 {
 	int i;
 
@@ -135,12 +135,12 @@ int quicktime_read_esds(quicktime_t *fil
 	return 0;
 }
 
-int quicktime_write_esds_common(quicktime_t *file, quicktime_esds_t *esds, int esid, u_int objectType, u_int streamType)
+void quicktime_write_esds_common(quicktime_t *file, quicktime_esds_t *esds, int esid, u_int objectType, u_int streamType)
 {
 	quicktime_atom_t atom;
 
 	if (!file->use_mp4) {
-		return 0;
+		return;
 	}
 
 	quicktime_atom_write_header(file, &atom, "esds");
@@ -187,13 +187,13 @@ int quicktime_write_esds_common(quicktim
 	quicktime_atom_write_footer(file, &atom);
 }
 
-int quicktime_write_esds_audio(quicktime_t *file, quicktime_esds_t *esds, int esid)
+void quicktime_write_esds_audio(quicktime_t *file, quicktime_esds_t *esds, int esid)
 {
-	return quicktime_write_esds_common(file, esds, esid, (u_int)0x40, (u_int)0x05);
+	quicktime_write_esds_common(file, esds, esid, (u_int)0x40, (u_int)0x05);
 }
 
-int quicktime_write_esds_video(quicktime_t *file, quicktime_esds_t *esds, int esid)
+void quicktime_write_esds_video(quicktime_t *file, quicktime_esds_t *esds, int esid)
 {
-	return quicktime_write_esds_common(file, esds, esid, (u_int)0x20, (u_int)0x04);
+	quicktime_write_esds_common(file, esds, esid, (u_int)0x20, (u_int)0x04);
 }
 
