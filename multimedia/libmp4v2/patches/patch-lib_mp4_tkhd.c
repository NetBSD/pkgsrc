$NetBSD: patch-lib_mp4_tkhd.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/tkhd.c.orig	2017-09-25 14:55:14.099688587 +0000
+++ lib/mp4/tkhd.c
@@ -8,7 +8,7 @@ int quicktime_tkhd_init(quicktime_tkhd_t
 	tkhd->flags = 15;
 	tkhd->creation_time = quicktime_current_time();
 	tkhd->modification_time = quicktime_current_time();
-	tkhd->track_id;
+	tkhd->track_id = 0;
 	tkhd->reserved1 = 0;
 	tkhd->duration = 0;      /* need to set this when closing */
 	for(i = 0; i < 8; i++) tkhd->reserved2[i] = 0;
@@ -25,13 +25,13 @@ int quicktime_tkhd_init(quicktime_tkhd_t
 	return 0;
 }
 
-int quicktime_tkhd_init_audio(quicktime_t *file, 
+void quicktime_tkhd_init_audio(quicktime_t *file, 
 								quicktime_tkhd_t *tkhd)
 {
 	tkhd->is_audio = TRUE;
 }
 
-int quicktime_tkhd_init_video(quicktime_t *file, 
+void quicktime_tkhd_init_video(quicktime_t *file, 
 								quicktime_tkhd_t *tkhd, 
 								int frame_w, 
 								int frame_h)
@@ -42,7 +42,7 @@ int quicktime_tkhd_init_video(quicktime_
 	tkhd->volume = 0;
 }
 
-int quicktime_tkhd_init_hint(quicktime_t *file, 
+void quicktime_tkhd_init_hint(quicktime_t *file, 
 								quicktime_tkhd_t *tkhd)
 {
 	tkhd->is_hint = TRUE;
@@ -56,13 +56,13 @@ int quicktime_tkhd_delete(quicktime_tkhd
 	return 0;
 }
 
-int quicktime_tkhd_dump(quicktime_tkhd_t *tkhd)
+void quicktime_tkhd_dump(quicktime_tkhd_t *tkhd)
 {
 	printf("  track header\n");
 	printf("   version %d\n", tkhd->version);
 	printf("   flags %ld\n", tkhd->flags);
-	printf("   creation_time %u\n", tkhd->creation_time);
-	printf("   modification_time %u\n", tkhd->modification_time);
+	printf("   creation_time %lu\n", tkhd->creation_time);
+	printf("   modification_time %lu\n", tkhd->modification_time);
 	printf("   track_id %d\n", tkhd->track_id);
 	printf("   reserved1 %ld\n", tkhd->reserved1);
 	printf("   duration %ld\n", tkhd->duration);
@@ -70,13 +70,13 @@ int quicktime_tkhd_dump(quicktime_tkhd_t
 	printf("   layer %d\n", tkhd->layer);
 	printf("   alternate_group %d\n", tkhd->alternate_group);
 	printf("   volume %f\n", tkhd->volume);
-	printf("   reserved3 %d\n", tkhd->reserved3);
+	printf("   reserved3 %ld\n", tkhd->reserved3);
 	quicktime_matrix_dump(&(tkhd->matrix));
 	printf("   track_width %f\n", tkhd->track_width);
 	printf("   track_height %f\n", tkhd->track_height);
 }
 
-int quicktime_read_tkhd(quicktime_t *file, quicktime_tkhd_t *tkhd)
+void quicktime_read_tkhd(quicktime_t *file, quicktime_tkhd_t *tkhd)
 {
 	tkhd->version = quicktime_read_char(file);
 	tkhd->flags = quicktime_read_int24(file);
@@ -95,7 +95,7 @@ int quicktime_read_tkhd(quicktime_t *fil
 	tkhd->track_height = quicktime_read_fixed32(file);
 }
 
-int quicktime_write_tkhd(quicktime_t *file, quicktime_tkhd_t *tkhd)
+void quicktime_write_tkhd(quicktime_t *file, quicktime_tkhd_t *tkhd)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "tkhd");
