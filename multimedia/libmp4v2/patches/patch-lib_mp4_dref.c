$NetBSD: patch-lib_mp4_dref.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/dref.c.orig	2017-09-25 14:52:00.003467817 +0000
+++ lib/mp4/dref.c
@@ -1,6 +1,6 @@
 #include "quicktime.h"
 
-int quicktime_dref_table_init(quicktime_dref_table_t *table)
+void quicktime_dref_table_init(quicktime_dref_table_t *table)
 {
 	table->size = 0;
 	table->type[0] = 'a';
@@ -13,13 +13,13 @@ int quicktime_dref_table_init(quicktime_
 	table->data_reference[0] = 0;
 }
 
-int quicktime_dref_table_delete(quicktime_dref_table_t *table)
+void quicktime_dref_table_delete(quicktime_dref_table_t *table)
 {
 	if(table->data_reference) free(table->data_reference);
 	table->data_reference = 0;
 }
 
-int quicktime_read_dref_table(quicktime_t *file, quicktime_dref_table_t *table)
+void quicktime_read_dref_table(quicktime_t *file, quicktime_dref_table_t *table)
 {
 	table->size = quicktime_read_int32(file);
 	quicktime_read_char32(file, table->type);
@@ -33,7 +33,7 @@ int quicktime_read_dref_table(quicktime_
 	table->data_reference[table->size - 12] = 0;
 }
 
-int quicktime_write_dref_table(quicktime_t *file, quicktime_dref_table_t *table)
+void quicktime_write_dref_table(quicktime_t *file, quicktime_dref_table_t *table)
 {
 	int len = strlen(table->data_reference);
 	quicktime_write_int32(file, 12 + len);
@@ -44,17 +44,17 @@ int quicktime_write_dref_table(quicktime
 		quicktime_write_data(file, table->data_reference, len);
 }
 
-int quicktime_dref_table_dump(quicktime_dref_table_t *table)
+void quicktime_dref_table_dump(quicktime_dref_table_t *table)
 {
 	printf("      data reference table (dref)\n");
 	printf("       type %c%c%c%c\n", table->type[0], table->type[1], table->type[2], table->type[3]);
 	printf("       version %d\n", table->version);
-	printf("       flags %d\n", table->flags);
+	printf("       flags %ld\n", table->flags);
 	printf("       data %s\n", table->data_reference);
 }
 
 
-int quicktime_dref_init(quicktime_dref_t *dref)
+void quicktime_dref_init(quicktime_dref_t *dref)
 {
 	dref->version = 0;
 	dref->flags = 0;
@@ -62,7 +62,7 @@ int quicktime_dref_init(quicktime_dref_t
 	dref->table = 0;
 }
 
-int quicktime_dref_init_all(quicktime_dref_t *dref)
+void quicktime_dref_init_all(quicktime_dref_t *dref)
 {
 	if(!dref->total_entries)
 	{
@@ -72,7 +72,7 @@ int quicktime_dref_init_all(quicktime_dr
 	}
 }
 
-int quicktime_dref_delete(quicktime_dref_t *dref)
+void quicktime_dref_delete(quicktime_dref_t *dref)
 {
 	if(dref->table)
 	{
@@ -84,20 +84,20 @@ int quicktime_dref_delete(quicktime_dref
 	dref->total_entries = 0;
 }
 
-int quicktime_dref_dump(quicktime_dref_t *dref)
+void quicktime_dref_dump(quicktime_dref_t *dref)
 {
 	int i;
 	
 	printf("     data reference (dref)\n");
 	printf("      version %d\n", dref->version);
-	printf("      flags %d\n", dref->flags);
+	printf("      flags %ld\n", dref->flags);
 	for(i = 0; i < dref->total_entries; i++)
 	{
 		quicktime_dref_table_dump(&(dref->table[i]));
 	}
 }
 
-int quicktime_read_dref(quicktime_t *file, quicktime_dref_t *dref)
+void quicktime_read_dref(quicktime_t *file, quicktime_dref_t *dref)
 {
 	int i;
 
@@ -112,7 +112,7 @@ int quicktime_read_dref(quicktime_t *fil
 	}
 }
 
-int quicktime_write_dref(quicktime_t *file, quicktime_dref_t *dref)
+void quicktime_write_dref(quicktime_t *file, quicktime_dref_t *dref)
 {
 	int i;
 	quicktime_atom_t atom;
