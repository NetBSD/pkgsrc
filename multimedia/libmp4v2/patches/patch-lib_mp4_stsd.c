$NetBSD: patch-lib_mp4_stsd.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/stsd.c.orig	2017-09-25 14:55:24.131811993 +0000
+++ lib/mp4/stsd.c
@@ -1,14 +1,14 @@
 #include "quicktime.h"
 
 
-int quicktime_stsd_init(quicktime_stsd_t *stsd)
+void quicktime_stsd_init(quicktime_stsd_t *stsd)
 {
 	stsd->version = 0;
 	stsd->flags = 0;
 	stsd->total_entries = 0;
 }
 
-int quicktime_stsd_init_table(quicktime_stsd_t *stsd)
+void quicktime_stsd_init_table(quicktime_stsd_t *stsd)
 {
 	if(!stsd->total_entries)
 	{
@@ -18,7 +18,7 @@ int quicktime_stsd_init_table(quicktime_
 	}
 }
 
-int quicktime_stsd_init_video(quicktime_t *file, 
+void quicktime_stsd_init_video(quicktime_t *file, 
 								quicktime_stsd_t *stsd, 
 								int frame_w,
 								int frame_h, 
@@ -37,7 +37,7 @@ int quicktime_stsd_init_video(quicktime_
 	table->ctab_id = 65535;
 }
 
-int quicktime_stsd_init_audio(quicktime_t *file, 
+void quicktime_stsd_init_audio(quicktime_t *file, 
 							quicktime_stsd_t *stsd, 
 							int channels,
 							int sample_rate, 
@@ -54,7 +54,7 @@ int quicktime_stsd_init_audio(quicktime_
 	table->sample_rate = sample_rate;
 }
 
-int quicktime_stsd_init_hint(quicktime_t *file, 
+void quicktime_stsd_init_hint(quicktime_t *file, 
 							quicktime_stsd_t *stsd, 
 							int maxPktSize,
 							int timeScale)
@@ -70,7 +70,7 @@ int quicktime_stsd_init_hint(quicktime_t
 	table->tims.timeScale = timeScale;
 }
 
-int quicktime_stsd_delete(quicktime_stsd_t *stsd)
+void quicktime_stsd_delete(quicktime_stsd_t *stsd)
 {
 	int i;
 	if(stsd->total_entries)
@@ -83,13 +83,13 @@ int quicktime_stsd_delete(quicktime_stsd
 	stsd->total_entries = 0;
 }
 
-int quicktime_stsd_dump(void *minf_ptr, quicktime_stsd_t *stsd)
+void quicktime_stsd_dump(void *minf_ptr, quicktime_stsd_t *stsd)
 {
 	int i;
 	printf("     sample description\n");
 	printf("      version %d\n", stsd->version);
-	printf("      flags %d\n", stsd->flags);
-	printf("      total_entries %d\n", stsd->total_entries);
+	printf("      flags %ld\n", stsd->flags);
+	printf("      total_entries %ld\n", stsd->total_entries);
 	
 	for(i = 0; i < stsd->total_entries; i++)
 	{
@@ -97,7 +97,7 @@ int quicktime_stsd_dump(void *minf_ptr, 
 	}
 }
 
-int quicktime_read_stsd(quicktime_t *file, quicktime_minf_t *minf, quicktime_stsd_t *stsd)
+void quicktime_read_stsd(quicktime_t *file, quicktime_minf_t *minf, quicktime_stsd_t *stsd)
 {
 	int i;
 	quicktime_atom_t leaf_atom;
@@ -113,7 +113,7 @@ int quicktime_read_stsd(quicktime_t *fil
 	}
 }
 
-int quicktime_write_stsd(quicktime_t *file, quicktime_minf_t *minf, quicktime_stsd_t *stsd)
+void quicktime_write_stsd(quicktime_t *file, quicktime_minf_t *minf, quicktime_stsd_t *stsd)
 {
 	quicktime_atom_t atom;
 	int i;
