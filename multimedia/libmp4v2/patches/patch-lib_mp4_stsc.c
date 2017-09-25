$NetBSD: patch-lib_mp4_stsc.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/stsc.c.orig	2017-09-25 14:55:27.294079758 +0000
+++ lib/mp4/stsc.c
@@ -2,7 +2,7 @@
 
 
 
-int quicktime_stsc_init(quicktime_stsc_t *stsc)
+void quicktime_stsc_init(quicktime_stsc_t *stsc)
 {
 	stsc->version = 0;
 	stsc->flags = 0;
@@ -10,7 +10,7 @@ int quicktime_stsc_init(quicktime_stsc_t
 	stsc->entries_allocated = 0;
 }
 
-int quicktime_stsc_init_table(quicktime_t *file, quicktime_stsc_t *stsc)
+void quicktime_stsc_init_table(quicktime_t *file, quicktime_stsc_t *stsc)
 {
 	if(!stsc->total_entries)
 	{
@@ -20,7 +20,7 @@ int quicktime_stsc_init_table(quicktime_
 	}
 }
 
-int quicktime_stsc_init_video(quicktime_t *file, quicktime_stsc_t *stsc)
+void quicktime_stsc_init_video(quicktime_t *file, quicktime_stsc_t *stsc)
 {
 	quicktime_stsc_table_t *table;
 	quicktime_stsc_init_table(file, stsc);
@@ -30,7 +30,7 @@ int quicktime_stsc_init_video(quicktime_
 	table->id = 1;
 }
 
-int quicktime_stsc_init_audio(quicktime_t *file, quicktime_stsc_t *stsc)
+void quicktime_stsc_init_audio(quicktime_t *file, quicktime_stsc_t *stsc)
 {
 	quicktime_stsc_table_t *table;
 	quicktime_stsc_init_table(file, stsc);
@@ -40,27 +40,27 @@ int quicktime_stsc_init_audio(quicktime_
 	table->id = 1;
 }
 
-int quicktime_stsc_delete(quicktime_stsc_t *stsc)
+void quicktime_stsc_delete(quicktime_stsc_t *stsc)
 {
 	if(stsc->total_entries) free(stsc->table);
 	stsc->total_entries = 0;
 }
 
-int quicktime_stsc_dump(quicktime_stsc_t *stsc)
+void quicktime_stsc_dump(quicktime_stsc_t *stsc)
 {
 	int i;
 	printf("     sample to chunk\n");
 	printf("      version %d\n", stsc->version);
-	printf("      flags %d\n", stsc->flags);
-	printf("      total_entries %d\n", stsc->total_entries);
+	printf("      flags %ld\n", stsc->flags);
+	printf("      total_entries %ld\n", stsc->total_entries);
 	for(i = 0; i < stsc->total_entries; i++)
 	{
-		printf("       chunk %d samples %d id %d\n", 
+		printf("       chunk %ld samples %ld id %ld\n", 
 			stsc->table[i].chunk, stsc->table[i].samples, stsc->table[i].id);
 	}
 }
 
-int quicktime_read_stsc(quicktime_t *file, quicktime_stsc_t *stsc)
+void quicktime_read_stsc(quicktime_t *file, quicktime_stsc_t *stsc)
 {
 	int i;
 	stsc->version = quicktime_read_char(file);
@@ -78,7 +78,7 @@ int quicktime_read_stsc(quicktime_t *fil
 }
 
 
-int quicktime_write_stsc(quicktime_t *file, quicktime_stsc_t *stsc)
+void quicktime_write_stsc(quicktime_t *file, quicktime_stsc_t *stsc)
 {
 	int i, last_same;
 	quicktime_atom_t atom;
