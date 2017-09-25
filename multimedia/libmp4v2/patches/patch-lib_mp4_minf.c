$NetBSD: patch-lib_mp4_minf.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/minf.c.orig	2017-09-25 14:55:53.118744073 +0000
+++ lib/mp4/minf.c
@@ -2,7 +2,7 @@
 
 
 
-int quicktime_minf_init(quicktime_minf_t *minf)
+void quicktime_minf_init(quicktime_minf_t *minf)
 {
 	minf->is_video = minf->is_audio = minf->is_hint = 0;
 	quicktime_vmhd_init(&(minf->vmhd));
@@ -12,7 +12,7 @@ int quicktime_minf_init(quicktime_minf_t
 	quicktime_stbl_init(&(minf->stbl));
 }
 
-int quicktime_minf_init_video(quicktime_t *file, 
+void quicktime_minf_init_video(quicktime_t *file, 
 								quicktime_minf_t *minf, 
 								int frame_w,
 								int frame_h, 
@@ -27,7 +27,7 @@ int quicktime_minf_init_video(quicktime_
 	quicktime_dinf_init_all(&(minf->dinf));
 }
 
-int quicktime_minf_init_audio(quicktime_t *file, 
+void quicktime_minf_init_audio(quicktime_t *file, 
 							quicktime_minf_t *minf, 
 							int channels, 
 							int sample_rate, 
@@ -44,7 +44,7 @@ int quicktime_minf_init_audio(quicktime_
 	quicktime_dinf_init_all(&(minf->dinf));
 }
 
-int quicktime_minf_init_hint(quicktime_t *file, 
+void quicktime_minf_init_hint(quicktime_t *file, 
 								quicktime_minf_t *minf, 
 								quicktime_trak_t *refTrak,
 								int maxPktSize,
@@ -59,7 +59,7 @@ int quicktime_minf_init_hint(quicktime_t
 	quicktime_dinf_init_all(&(minf->dinf));
 }
 
-int quicktime_minf_delete(quicktime_minf_t *minf)
+void quicktime_minf_delete(quicktime_minf_t *minf)
 {
 	quicktime_vmhd_delete(&(minf->vmhd));
 	quicktime_smhd_delete(&(minf->smhd));
@@ -70,7 +70,7 @@ int quicktime_minf_delete(quicktime_minf
 	quicktime_hdlr_delete(&(minf->hdlr));
 }
 
-int quicktime_minf_dump(quicktime_minf_t *minf)
+void quicktime_minf_dump(quicktime_minf_t *minf)
 {
 	printf("   media info\n");
 	printf("    is_audio %d\n", minf->is_audio);
@@ -108,7 +108,7 @@ int quicktime_read_minf(quicktime_t *fil
 			{ minf->is_hint = 1; quicktime_read_gmhd(file, &(minf->gmhd), &leaf_atom); }
 		else
 		if(quicktime_atom_is(&leaf_atom, "hmhd"))
-			{ minf->is_hint = 1; quicktime_read_hmhd(file, &(minf->hmhd), &leaf_atom); }
+			{ minf->is_hint = 1; quicktime_read_hmhd(file, &(minf->hmhd)); }
 		else
 		if(quicktime_atom_is(&leaf_atom, "hdlr"))
 			{ 
@@ -138,7 +138,7 @@ int quicktime_read_minf(quicktime_t *fil
 	return 0;
 }
 
-int quicktime_write_minf(quicktime_t *file, quicktime_minf_t *minf)
+void quicktime_write_minf(quicktime_t *file, quicktime_minf_t *minf)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "minf");
