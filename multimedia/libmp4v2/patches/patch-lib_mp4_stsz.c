$NetBSD: patch-lib_mp4_stsz.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/stsz.c.orig	2017-09-25 14:55:18.019052073 +0000
+++ lib/mp4/stsz.c
@@ -2,7 +2,7 @@
 
 
 
-int quicktime_stsz_init(quicktime_stsz_t *stsz)
+void quicktime_stsz_init(quicktime_stsz_t *stsz)
 {
 	stsz->version = 0;
 	stsz->flags = 0;
@@ -11,7 +11,7 @@ int quicktime_stsz_init(quicktime_stsz_t
 	stsz->entries_allocated = 0;
 }
 
-int quicktime_stsz_init_video(quicktime_t *file, quicktime_stsz_t *stsz)
+void quicktime_stsz_init_video(quicktime_t *file, quicktime_stsz_t *stsz)
 {
 	stsz->sample_size = 0;
 	if(!stsz->entries_allocated)
@@ -22,14 +22,14 @@ int quicktime_stsz_init_video(quicktime_
 	}
 }
 
-int quicktime_stsz_init_audio(quicktime_t *file, quicktime_stsz_t *stsz, int sample_size)
+void quicktime_stsz_init_audio(quicktime_t *file, quicktime_stsz_t *stsz, int sample_size)
 {
 	stsz->sample_size = sample_size;	/* if == 0, then use table */
 	stsz->total_entries = 0;   /* set this when closing */
 	stsz->entries_allocated = 0;
 }
 
-int quicktime_stsz_delete(quicktime_stsz_t *stsz)
+void quicktime_stsz_delete(quicktime_stsz_t *stsz)
 {
 	if(!stsz->sample_size && stsz->total_entries) 
 		free(stsz->table);
@@ -37,25 +37,25 @@ int quicktime_stsz_delete(quicktime_stsz
 	stsz->entries_allocated = 0;
 }
 
-int quicktime_stsz_dump(quicktime_stsz_t *stsz)
+void quicktime_stsz_dump(quicktime_stsz_t *stsz)
 {
 	int i;
 	printf("     sample size\n");
 	printf("      version %d\n", stsz->version);
-	printf("      flags %d\n", stsz->flags);
-	printf("      sample_size %d\n", stsz->sample_size);
-	printf("      total_entries %d\n", stsz->total_entries);
+	printf("      flags %ld\n", stsz->flags);
+	printf("      sample_size %ld\n", stsz->sample_size);
+	printf("      total_entries %ld\n", stsz->total_entries);
 	
 	if(!stsz->sample_size)
 	{
 		for(i = 0; i < stsz->total_entries; i++)
 		{
-			printf("       sample_size %d\n", stsz->table[i].size);
+			printf("       sample_size %ld\n", stsz->table[i].size);
 		}
 	}
 }
 
-int quicktime_read_stsz(quicktime_t *file, quicktime_stsz_t *stsz)
+void quicktime_read_stsz(quicktime_t *file, quicktime_stsz_t *stsz)
 {
 	int i;
 	stsz->version = quicktime_read_char(file);
@@ -73,7 +73,7 @@ int quicktime_read_stsz(quicktime_t *fil
 	}
 }
 
-int quicktime_write_stsz(quicktime_t *file, quicktime_stsz_t *stsz)
+void quicktime_write_stsz(quicktime_t *file, quicktime_stsz_t *stsz)
 {
 	int i, result;
 	quicktime_atom_t atom;
@@ -116,7 +116,7 @@ int quicktime_write_stsz(quicktime_t *fi
 	quicktime_atom_write_footer(file, &atom);
 }
 
-int quicktime_update_stsz(quicktime_stsz_t *stsz, long sample, long sample_size)
+void quicktime_update_stsz(quicktime_stsz_t *stsz, long sample, long sample_size)
 {
 	quicktime_stsz_table_t *new_table;
 	int i;
