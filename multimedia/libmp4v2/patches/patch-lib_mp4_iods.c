$NetBSD: patch-lib_mp4_iods.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/iods.c.orig	2017-09-25 14:54:03.383726487 +0000
+++ lib/mp4/iods.c
@@ -31,12 +31,12 @@ int quicktime_iods_init(quicktime_iods_t
 	return 0;
 }
 
-int quicktime_iods_set_audio_profile(quicktime_iods_t* iods, int id)
+void quicktime_iods_set_audio_profile(quicktime_iods_t* iods, int id)
 {
 	iods->audioProfileId = id;
 }
 
-int quicktime_iods_set_video_profile(quicktime_iods_t* iods, int id)
+void quicktime_iods_set_video_profile(quicktime_iods_t* iods, int id)
 {
 	iods->videoProfileId = id;
 }
@@ -46,7 +46,7 @@ int quicktime_iods_delete(quicktime_iods
 	return 0;
 }
 
-int quicktime_iods_dump(quicktime_iods_t *iods)
+void quicktime_iods_dump(quicktime_iods_t *iods)
 {
 	printf(" initial object descriptor\n");
 	printf("  version %d\n", iods->version);
@@ -55,7 +55,7 @@ int quicktime_iods_dump(quicktime_iods_t
 	printf("  videoProfileId %u\n", iods->videoProfileId);
 }
 
-int quicktime_read_iods(quicktime_t *file, quicktime_iods_t *iods)
+void quicktime_read_iods(quicktime_t *file, quicktime_iods_t *iods)
 {
 	iods->version = quicktime_read_char(file);
 	iods->flags = quicktime_read_int24(file);
@@ -68,13 +68,13 @@ int quicktime_read_iods(quicktime_t *fil
 	/* will skip the remainder of the atom */
 }
 
-int quicktime_write_iods(quicktime_t *file, quicktime_iods_t *iods)
+void quicktime_write_iods(quicktime_t *file, quicktime_iods_t *iods)
 {
 	quicktime_atom_t atom;
 	int i;
 
 	if (!file->use_mp4) {
-		return 0;
+		return;
 	}
 
 	quicktime_atom_write_header(file, &atom, "iods");
