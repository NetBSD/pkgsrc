$NetBSD: patch-lib_mp4_ctts.c,v 1.2 2017/09/25 22:30:06 joerg Exp $

Fix return type. we're not returning anything.

--- lib/mp4/ctts.c.orig	2001-08-01 00:34:00.000000000 +0000
+++ lib/mp4/ctts.c
@@ -22,7 +22,7 @@
 #include "quicktime.h"
 
 
-int quicktime_ctts_init(quicktime_ctts_t *ctts)
+void quicktime_ctts_init(quicktime_ctts_t *ctts)
 {
 	ctts->version = 0;
 	ctts->flags = 0;
@@ -30,7 +30,7 @@ int quicktime_ctts_init(quicktime_ctts_t
 	ctts->entries_allocated = 0;
 }
 
-int quicktime_ctts_init_table(quicktime_ctts_t *ctts)
+void quicktime_ctts_init_table(quicktime_ctts_t *ctts)
 {
 	if (!ctts->entries_allocated) {
 		ctts->entries_allocated = 1;
@@ -40,7 +40,7 @@ int quicktime_ctts_init_table(quicktime_
 	}
 }
 
-int quicktime_ctts_init_common(quicktime_t *file, quicktime_ctts_t *ctts)
+void quicktime_ctts_init_common(quicktime_t *file, quicktime_ctts_t *ctts)
 {
 	quicktime_ctts_table_t *table;
 	quicktime_ctts_init_table(ctts);
@@ -50,7 +50,7 @@ int quicktime_ctts_init_common(quicktime
 	table->sample_offset = 0;
 }
 
-int quicktime_ctts_delete(quicktime_ctts_t *ctts)
+void quicktime_ctts_delete(quicktime_ctts_t *ctts)
 {
 	if (ctts->total_entries) {
 		free(ctts->table);
@@ -58,13 +58,13 @@ int quicktime_ctts_delete(quicktime_ctts
 	ctts->total_entries = 0;
 }
 
-int quicktime_ctts_dump(quicktime_ctts_t *ctts)
+void quicktime_ctts_dump(quicktime_ctts_t *ctts)
 {
 	int i;
 	printf("     composition time to sample\n");
 	printf("      version %d\n", ctts->version);
-	printf("      flags %d\n", ctts->flags);
-	printf("      total_entries %d\n", ctts->total_entries);
+	printf("      flags %ld\n", ctts->flags);
+	printf("      total_entries %ld\n", ctts->total_entries);
 	for(i = 0; i < ctts->total_entries; i++) {
 		printf("       count %ld offset %ld\n", 
 			ctts->table[i].sample_count,
@@ -72,7 +72,7 @@ int quicktime_ctts_dump(quicktime_ctts_t
 	}
 }
 
-int quicktime_read_ctts(quicktime_t *file, quicktime_ctts_t *ctts)
+void quicktime_read_ctts(quicktime_t *file, quicktime_ctts_t *ctts)
 {
 	int i;
 	ctts->version = quicktime_read_char(file);
@@ -88,7 +88,7 @@ int quicktime_read_ctts(quicktime_t *fil
 	}
 }
 
-int quicktime_write_ctts(quicktime_t *file, quicktime_ctts_t *ctts)
+void quicktime_write_ctts(quicktime_t *file, quicktime_ctts_t *ctts)
 {
 	int i;
 	quicktime_atom_t atom;
@@ -113,7 +113,7 @@ int quicktime_write_ctts(quicktime_t *fi
 	quicktime_atom_write_footer(file, &atom);
 }
 
-int quicktime_update_ctts(quicktime_ctts_t *ctts, long sample_offset)
+void quicktime_update_ctts(quicktime_ctts_t *ctts, long sample_offset)
 {
 	if (sample_offset == ctts->table[ctts->total_entries-1].sample_offset) {
 		ctts->table[ctts->total_entries-1].sample_count++;
