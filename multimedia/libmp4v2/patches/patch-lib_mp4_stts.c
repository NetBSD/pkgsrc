$NetBSD: patch-lib_mp4_stts.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/stts.c.orig	2017-09-25 14:55:16.067763826 +0000
+++ lib/mp4/stts.c
@@ -2,7 +2,7 @@
 
 
 
-int quicktime_stts_init(quicktime_stts_t *stts)
+void quicktime_stts_init(quicktime_stts_t *stts)
 {
 	stts->version = 0;
 	stts->flags = 0;
@@ -10,7 +10,7 @@ int quicktime_stts_init(quicktime_stts_t
 	stts->entries_allocated = 0;
 }
 
-int quicktime_stts_init_table(quicktime_stts_t *stts)
+void quicktime_stts_init_table(quicktime_stts_t *stts)
 {
 	if(!stts->entries_allocated)
 	{
@@ -21,7 +21,7 @@ int quicktime_stts_init_table(quicktime_
 	}
 }
 
-int quicktime_stts_init_video(quicktime_t *file, quicktime_stts_t *stts, int time_scale, float frame_rate)
+void quicktime_stts_init_video(quicktime_t *file, quicktime_stts_t *stts, int time_scale, float frame_rate)
 {
 	quicktime_stts_table_t *table;
 	quicktime_stts_init_table(stts);
@@ -31,7 +31,7 @@ int quicktime_stts_init_video(quicktime_
 	table->sample_duration = time_scale / frame_rate;
 }
 
-int quicktime_stts_init_audio(quicktime_t *file, quicktime_stts_t *stts, int time_scale, int sample_duration)
+void quicktime_stts_init_audio(quicktime_t *file, quicktime_stts_t *stts, int time_scale, int sample_duration)
 {
 	quicktime_stts_table_t *table;
 	quicktime_stts_init_table(stts);
@@ -41,7 +41,7 @@ int quicktime_stts_init_audio(quicktime_
 	table->sample_duration = sample_duration;
 }
 
-int quicktime_stts_init_hint(quicktime_t *file, quicktime_stts_t *stts, int sample_duration)
+void quicktime_stts_init_hint(quicktime_t *file, quicktime_stts_t *stts, int sample_duration)
 {
 	quicktime_stts_table_t *table;
 	quicktime_stts_init_table(stts);
@@ -51,26 +51,26 @@ int quicktime_stts_init_hint(quicktime_t
 	table->sample_duration = sample_duration;
 }
 
-int quicktime_stts_delete(quicktime_stts_t *stts)
+void quicktime_stts_delete(quicktime_stts_t *stts)
 {
 	if(stts->total_entries) free(stts->table);
 	stts->total_entries = 0;
 }
 
-int quicktime_stts_dump(quicktime_stts_t *stts)
+void quicktime_stts_dump(quicktime_stts_t *stts)
 {
 	int i;
 	printf("     time to sample\n");
 	printf("      version %d\n", stts->version);
-	printf("      flags %d\n", stts->flags);
-	printf("      total_entries %d\n", stts->total_entries);
+	printf("      flags %ld\n", stts->flags);
+	printf("      total_entries %ld\n", stts->total_entries);
 	for(i = 0; i < stts->total_entries; i++)
 	{
 		printf("       count %ld duration %ld\n", stts->table[i].sample_count, stts->table[i].sample_duration);
 	}
 }
 
-int quicktime_read_stts(quicktime_t *file, quicktime_stts_t *stts)
+void quicktime_read_stts(quicktime_t *file, quicktime_stts_t *stts)
 {
 	int i;
 	stts->version = quicktime_read_char(file);
@@ -85,7 +85,7 @@ int quicktime_read_stts(quicktime_t *fil
 	}
 }
 
-int quicktime_write_stts(quicktime_t *file, quicktime_stts_t *stts)
+void quicktime_write_stts(quicktime_t *file, quicktime_stts_t *stts)
 {
 	int i;
 	quicktime_atom_t atom;
@@ -102,7 +102,7 @@ int quicktime_write_stts(quicktime_t *fi
 	quicktime_atom_write_footer(file, &atom);
 }
 
-int quicktime_update_stts(quicktime_stts_t *stts, long sample_duration)
+void quicktime_update_stts(quicktime_stts_t *stts, long sample_duration)
 {
 	if (sample_duration == stts->table[stts->total_entries-1].sample_duration) {
 		stts->table[stts->total_entries-1].sample_count++;
