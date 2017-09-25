$NetBSD: patch-lib_mp4_mdia.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/mdia.c.orig	2017-09-25 14:55:55.174088895 +0000
+++ lib/mp4/mdia.c
@@ -1,14 +1,14 @@
 #include "quicktime.h"
 
 
-int quicktime_mdia_init(quicktime_mdia_t *mdia)
+void quicktime_mdia_init(quicktime_mdia_t *mdia)
 {
 	quicktime_mdhd_init(&(mdia->mdhd));
 	quicktime_hdlr_init(&(mdia->hdlr));
 	quicktime_minf_init(&(mdia->minf));
 }
 
-int quicktime_mdia_init_video(quicktime_t *file, 
+void quicktime_mdia_init_video(quicktime_t *file, 
 								quicktime_mdia_t *mdia,
 								int frame_w,
 								int frame_h, 
@@ -21,7 +21,7 @@ int quicktime_mdia_init_video(quicktime_
 	quicktime_hdlr_init_video(&(mdia->hdlr));
 }
 
-int quicktime_mdia_init_audio(quicktime_t *file, 
+void quicktime_mdia_init_audio(quicktime_t *file, 
 							quicktime_mdia_t *mdia, 
 							int channels,
 							int sample_rate, 
@@ -36,7 +36,7 @@ int quicktime_mdia_init_audio(quicktime_
 	quicktime_hdlr_init_audio(&(mdia->hdlr));
 }
 
-int quicktime_mdia_init_hint(quicktime_t *file, 
+void quicktime_mdia_init_hint(quicktime_t *file, 
 							quicktime_mdia_t *mdia, 
 							quicktime_trak_t *refTrak,
 							int maxPktSize,
@@ -49,14 +49,14 @@ int quicktime_mdia_init_hint(quicktime_t
 	quicktime_hdlr_init_hint(&(mdia->hdlr));
 }
 
-int quicktime_mdia_delete(quicktime_mdia_t *mdia)
+void quicktime_mdia_delete(quicktime_mdia_t *mdia)
 {
 	quicktime_mdhd_delete(&(mdia->mdhd));
 	quicktime_hdlr_delete(&(mdia->hdlr));
 	quicktime_minf_delete(&(mdia->minf));
 }
 
-int quicktime_mdia_dump(quicktime_mdia_t *mdia)
+void quicktime_mdia_dump(quicktime_mdia_t *mdia)
 {
 	printf("  media\n");
 	quicktime_mdhd_dump(&(mdia->mdhd));
@@ -93,7 +93,7 @@ int quicktime_read_mdia(quicktime_t *fil
 	return 0;
 }
 
-int quicktime_write_mdia(quicktime_t *file, quicktime_mdia_t *mdia)
+void quicktime_write_mdia(quicktime_t *file, quicktime_mdia_t *mdia)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "mdia");
