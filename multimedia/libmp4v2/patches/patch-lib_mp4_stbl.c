$NetBSD: patch-lib_mp4_stbl.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/stbl.c.orig	2017-09-25 14:55:31.669269970 +0000
+++ lib/mp4/stbl.c
@@ -1,6 +1,6 @@
 #include "quicktime.h"
 
-int quicktime_stbl_init(quicktime_stbl_t *stbl)
+void quicktime_stbl_init(quicktime_stbl_t *stbl)
 {
 	stbl->version = 0;
 	stbl->flags = 0;
@@ -13,7 +13,7 @@ int quicktime_stbl_init(quicktime_stbl_t
 	quicktime_ctts_init(&(stbl->ctts));
 }
 
-int quicktime_stbl_init_video(quicktime_t *file, 
+void quicktime_stbl_init_video(quicktime_t *file, 
 							quicktime_stbl_t *stbl, 
 							int frame_w,
 							int frame_h, 
@@ -31,7 +31,7 @@ int quicktime_stbl_init_video(quicktime_
 }
 
 
-int quicktime_stbl_init_audio(quicktime_t *file, 
+void quicktime_stbl_init_audio(quicktime_t *file, 
 							quicktime_stbl_t *stbl, 
 							int channels, 
 							int sample_rate, 
@@ -50,7 +50,7 @@ int quicktime_stbl_init_audio(quicktime_
 	quicktime_ctts_init_common(file, &(stbl->ctts));
 }
 
-int quicktime_stbl_init_hint(quicktime_t *file, 
+void quicktime_stbl_init_hint(quicktime_t *file, 
 							quicktime_stbl_t *stbl, 
 							quicktime_trak_t *refTrak,
 							int maxPktSize,
@@ -67,7 +67,7 @@ int quicktime_stbl_init_hint(quicktime_t
 	quicktime_ctts_init_common(file, &(stbl->ctts));
 }
 
-int quicktime_stbl_delete(quicktime_stbl_t *stbl)
+void quicktime_stbl_delete(quicktime_stbl_t *stbl)
 {
 	quicktime_stsd_delete(&(stbl->stsd));
 	quicktime_stts_delete(&(stbl->stts));
@@ -78,7 +78,7 @@ int quicktime_stbl_delete(quicktime_stbl
 	quicktime_ctts_delete(&(stbl->ctts));
 }
 
-int quicktime_stbl_dump(void *minf_ptr, quicktime_stbl_t *stbl)
+void quicktime_stbl_dump(void *minf_ptr, quicktime_stbl_t *stbl)
 {
 	printf("    sample table\n");
 	quicktime_stsd_dump(minf_ptr, &(stbl->stsd));
@@ -130,7 +130,7 @@ int quicktime_read_stbl(quicktime_t *fil
 	return 0;
 }
 
-int quicktime_write_stbl(quicktime_t *file, quicktime_minf_t *minf, quicktime_stbl_t *stbl)
+void quicktime_write_stbl(quicktime_t *file, quicktime_minf_t *minf, quicktime_stbl_t *stbl)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "stbl");
