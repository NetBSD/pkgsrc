$NetBSD: patch-lib_mp4_stss.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/stss.c.orig	2017-09-25 14:55:20.105351068 +0000
+++ lib/mp4/stss.c
@@ -1,7 +1,7 @@
 #include "quicktime.h"
 
 
-int quicktime_stss_init(quicktime_stss_t *stss)
+void quicktime_stss_init(quicktime_stss_t *stss)
 {
 	stss->version = 0;
 	stss->flags = 0;
@@ -9,7 +9,7 @@ int quicktime_stss_init(quicktime_stss_t
 	stss->entries_allocated = 0;
 }
 
-int quicktime_stss_init_common(quicktime_t *file, quicktime_stss_t *stss)
+void quicktime_stss_init_common(quicktime_t *file, quicktime_stss_t *stss)
 {
 	if (stss->entries_allocated == 0) {
 		stss->entries_allocated = 100;
@@ -18,27 +18,27 @@ int quicktime_stss_init_common(quicktime
 	}
 }
 
-int quicktime_stss_delete(quicktime_stss_t *stss)
+void quicktime_stss_delete(quicktime_stss_t *stss)
 {
 	if(stss->total_entries) 
 		free(stss->table);
 	stss->total_entries = 0;
 }
 
-int quicktime_stss_dump(quicktime_stss_t *stss)
+void quicktime_stss_dump(quicktime_stss_t *stss)
 {
 	int i;
 	printf("     sync sample\n");
 	printf("      version %d\n", stss->version);
-	printf("      flags %d\n", stss->flags);
-	printf("      total_entries %d\n", stss->total_entries);
+	printf("      flags %ld\n", stss->flags);
+	printf("      total_entries %ld\n", stss->total_entries);
 	for(i = 0; i < stss->total_entries; i++)
 	{
-		printf("       sample %u\n", stss->table[i].sample);
+		printf("       sample %ld\n", stss->table[i].sample);
 	}
 }
 
-int quicktime_read_stss(quicktime_t *file, quicktime_stss_t *stss)
+void quicktime_read_stss(quicktime_t *file, quicktime_stss_t *stss)
 {
 	int i;
 	stss->version = quicktime_read_char(file);
@@ -53,7 +53,7 @@ int quicktime_read_stss(quicktime_t *fil
 }
 
 
-int quicktime_write_stss(quicktime_t *file, quicktime_stss_t *stss)
+void quicktime_write_stss(quicktime_t *file, quicktime_stss_t *stss)
 {
 	int i;
 	quicktime_atom_t atom;
@@ -74,7 +74,7 @@ int quicktime_write_stss(quicktime_t *fi
 	}
 }
 
-int quicktime_update_stss(quicktime_stss_t *stss, long sample)
+void quicktime_update_stss(quicktime_stss_t *stss, long sample)
 {
 	if (stss->total_entries >= stss->entries_allocated) {
 		stss->entries_allocated *= 2;
