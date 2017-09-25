$NetBSD: patch-lib_mp4_stco.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/stco.c.orig	2017-09-25 14:55:29.637953605 +0000
+++ lib/mp4/stco.c
@@ -2,7 +2,7 @@
 
 
 
-int quicktime_stco_init(quicktime_stco_t *stco)
+void quicktime_stco_init(quicktime_stco_t *stco)
 {
 	stco->version = 0;
 	stco->flags = 0;
@@ -10,14 +10,14 @@ int quicktime_stco_init(quicktime_stco_t
 	stco->entries_allocated = 0;
 }
 
-int quicktime_stco_delete(quicktime_stco_t *stco)
+void quicktime_stco_delete(quicktime_stco_t *stco)
 {
 	if(stco->total_entries) free(stco->table);
 	stco->total_entries = 0;
 	stco->entries_allocated = 0;
 }
 
-int quicktime_stco_init_common(quicktime_t *file, quicktime_stco_t *stco)
+void quicktime_stco_init_common(quicktime_t *file, quicktime_stco_t *stco)
 {
 	if(!stco->entries_allocated)
 	{
@@ -28,20 +28,20 @@ int quicktime_stco_init_common(quicktime
 	}
 }
 
-int quicktime_stco_dump(quicktime_stco_t *stco)
+void quicktime_stco_dump(quicktime_stco_t *stco)
 {
 	int i;
 	printf("     chunk offset\n");
 	printf("      version %d\n", stco->version);
-	printf("      flags %d\n", stco->flags);
-	printf("      total_entries %d\n", stco->total_entries);
+	printf("      flags %ld\n", stco->flags);
+	printf("      total_entries %ld\n", stco->total_entries);
 	for(i = 0; i < stco->total_entries; i++)
 	{
-		printf("       offset %d %x\n", i, stco->table[i].offset);
+		printf("       offset %d %lx\n", i, stco->table[i].offset);
 	}
 }
 
-int quicktime_read_stco(quicktime_t *file, quicktime_stco_t *stco)
+void quicktime_read_stco(quicktime_t *file, quicktime_stco_t *stco)
 {
 	int i;
 	stco->version = quicktime_read_char(file);
@@ -56,7 +56,7 @@ int quicktime_read_stco(quicktime_t *fil
 	}
 }
 
-int quicktime_write_stco(quicktime_t *file, quicktime_stco_t *stco)
+void quicktime_write_stco(quicktime_t *file, quicktime_stco_t *stco)
 {
 	int i;
 	quicktime_atom_t atom;
@@ -73,7 +73,7 @@ int quicktime_write_stco(quicktime_t *fi
 	quicktime_atom_write_footer(file, &atom);
 }
 
-int quicktime_update_stco(quicktime_stco_t *stco, long chunk, long offset)
+void quicktime_update_stco(quicktime_stco_t *stco, long chunk, long offset)
 {
 	quicktime_stco_table_t *new_table;
 	long i;
