$NetBSD: patch-lib_mp4_elst.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/elst.c.orig	2017-09-25 14:52:32.921623727 +0000
+++ lib/mp4/elst.c
@@ -1,25 +1,25 @@
 #include "quicktime.h"
 
 
-int quicktime_elst_table_init(quicktime_elst_table_t *table)
+void quicktime_elst_table_init(quicktime_elst_table_t *table)
 {
 	table->duration = 0;
 	table->time = 0;
 	table->rate = 1;
 }
 
-int quicktime_elst_table_delete(quicktime_elst_table_t *table)
+void quicktime_elst_table_delete(quicktime_elst_table_t *table)
 {
 }
 
-int quicktime_read_elst_table(quicktime_t *file, quicktime_elst_table_t *table)
+void quicktime_read_elst_table(quicktime_t *file, quicktime_elst_table_t *table)
 {
 	table->duration = quicktime_read_int32(file);
 	table->time = quicktime_read_int32(file);
 	table->rate = quicktime_read_fixed32(file);
 }
 
-int quicktime_write_elst_table(quicktime_t *file, quicktime_elst_table_t *table, long duration)
+void quicktime_write_elst_table(quicktime_t *file, quicktime_elst_table_t *table, long duration)
 {
 	table->duration = duration;
 	quicktime_write_int32(file, table->duration);
@@ -27,7 +27,7 @@ int quicktime_write_elst_table(quicktime
 	quicktime_write_fixed32(file, table->rate);
 }
 
-int quicktime_elst_table_dump(quicktime_elst_table_t *table)
+void quicktime_elst_table_dump(quicktime_elst_table_t *table)
 {
 	printf("    edit list table\n");
 	printf("     duration %ld\n", table->duration);
@@ -35,7 +35,7 @@ int quicktime_elst_table_dump(quicktime_
 	printf("     rate %f\n", table->rate);
 }
 
-int quicktime_elst_init(quicktime_elst_t *elst)
+void quicktime_elst_init(quicktime_elst_t *elst)
 {
 	elst->version = 0;
 	elst->flags = 0;
@@ -43,7 +43,7 @@ int quicktime_elst_init(quicktime_elst_t
 	elst->table = 0;
 }
 
-int quicktime_elst_init_all(quicktime_elst_t *elst)
+void quicktime_elst_init_all(quicktime_elst_t *elst)
 {
 	if(!elst->total_entries)
 	{
@@ -53,7 +53,7 @@ int quicktime_elst_init_all(quicktime_el
 	}
 }
 
-int quicktime_elst_delete(quicktime_elst_t *elst)
+void quicktime_elst_delete(quicktime_elst_t *elst)
 {
 	int i;
 	if(elst->total_entries)
@@ -65,13 +65,13 @@ int quicktime_elst_delete(quicktime_elst
 	elst->total_entries = 0;
 }
 
-int quicktime_elst_dump(quicktime_elst_t *elst)
+void quicktime_elst_dump(quicktime_elst_t *elst)
 {
 	int i;
 	printf("   edit list (elst)\n");
 	printf("    version %d\n", elst->version);
-	printf("    flags %d\n", elst->flags);
-	printf("    total_entries %d\n", elst->total_entries);
+	printf("    flags %ld\n", elst->flags);
+	printf("    total_entries %ld\n", elst->total_entries);
 
 	for(i = 0; i < elst->total_entries; i++)
 	{
@@ -79,7 +79,7 @@ int quicktime_elst_dump(quicktime_elst_t
 	}
 }
 
-int quicktime_read_elst(quicktime_t *file, quicktime_elst_t *elst)
+void quicktime_read_elst(quicktime_t *file, quicktime_elst_t *elst)
 {
 	int i;
 	quicktime_atom_t leaf_atom;
@@ -95,7 +95,7 @@ int quicktime_read_elst(quicktime_t *fil
 	}
 }
 
-int quicktime_write_elst(quicktime_t *file, quicktime_elst_t *elst, long duration)
+void quicktime_write_elst(quicktime_t *file, quicktime_elst_t *elst, long duration)
 {
 	quicktime_atom_t atom;
 	int i;
