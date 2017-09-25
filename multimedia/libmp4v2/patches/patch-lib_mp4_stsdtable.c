$NetBSD: patch-lib_mp4_stsdtable.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/stsdtable.c.orig	2017-09-25 14:55:22.063579799 +0000
+++ lib/mp4/stsdtable.c
@@ -1,7 +1,7 @@
 #include "quicktime.h"
 
 
-int quicktime_stsd_table_init(quicktime_stsd_table_t *table)
+void quicktime_stsd_table_init(quicktime_stsd_table_t *table)
 {
 	int i;
 	table->format[0] = 'y';
@@ -49,7 +49,7 @@ int quicktime_stsd_table_init(quicktime_
 	quicktime_esds_init(&(table->esds));
 }
 
-int quicktime_stsd_table_delete(quicktime_stsd_table_t *table)
+void quicktime_stsd_table_delete(quicktime_stsd_table_t *table)
 {
 	quicktime_ctab_delete(&(table->ctab));
 	quicktime_mjqt_delete(&(table->mjqt));
@@ -57,7 +57,7 @@ int quicktime_stsd_table_delete(quicktim
 	quicktime_esds_delete(&(table->esds));
 }
 
-int quicktime_stsd_table_dump(void *minf_ptr, quicktime_stsd_table_t *table)
+void quicktime_stsd_table_dump(void *minf_ptr, quicktime_stsd_table_t *table)
 {
 	quicktime_minf_t *minf = minf_ptr;
 	printf("       format %c%c%c%c\n", table->format[0], table->format[1], table->format[2], table->format[3]);
@@ -69,7 +69,7 @@ int quicktime_stsd_table_dump(void *minf
 	if(minf->is_hint)  quicktime_stsd_hint_dump(table);
 }
 
-int quicktime_stsd_audio_dump(quicktime_stsd_table_t *table)
+void quicktime_stsd_audio_dump(quicktime_stsd_table_t *table)
 {
 	printf("       version %d\n", table->version);
 	printf("       revision %d\n", table->revision);
@@ -83,7 +83,7 @@ int quicktime_stsd_audio_dump(quicktime_
 	quicktime_esds_dump(&(table->esds));
 }
 
-int quicktime_stsd_video_dump(quicktime_stsd_table_t *table)
+void quicktime_stsd_video_dump(quicktime_stsd_table_t *table)
 {
 	printf("       version %d\n", table->version);
 	printf("       revision %d\n", table->revision);
@@ -111,7 +111,7 @@ int quicktime_stsd_video_dump(quicktime_
 	quicktime_esds_dump(&(table->esds));
 }
 
-int quicktime_stsd_hint_dump(quicktime_stsd_table_t *table)
+void quicktime_stsd_hint_dump(quicktime_stsd_table_t *table)
 {
 	printf("       version %d\n", table->version);
 	printf("       revision %d\n", table->revision);
@@ -119,7 +119,7 @@ int quicktime_stsd_hint_dump(quicktime_s
 	/* TBD dump adtab */
 }
 
-int quicktime_read_stsd_table(quicktime_t *file, quicktime_minf_t *minf, quicktime_stsd_table_t *table)
+void quicktime_read_stsd_table(quicktime_t *file, quicktime_minf_t *minf, quicktime_stsd_table_t *table)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -137,7 +137,7 @@ int quicktime_read_stsd_table(quicktime_
 	if(minf->is_hint) quicktime_read_stsd_hint(file, table, &leaf_atom);
 }
 
-int quicktime_write_stsd_table(quicktime_t *file, quicktime_minf_t *minf, quicktime_stsd_table_t *table)
+void quicktime_write_stsd_table(quicktime_t *file, quicktime_minf_t *minf, quicktime_stsd_table_t *table)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, table->format);
@@ -152,7 +152,7 @@ int quicktime_write_stsd_table(quicktime
 	quicktime_atom_write_footer(file, &atom);
 }
 
-int quicktime_read_stsd_audio(quicktime_t *file, quicktime_stsd_table_t *table, quicktime_atom_t *parent_atom)
+void quicktime_read_stsd_audio(quicktime_t *file, quicktime_stsd_table_t *table, quicktime_atom_t *parent_atom)
 {
 	table->version = quicktime_read_int16(file);
 	table->revision = quicktime_read_int16(file);
@@ -177,7 +177,7 @@ int quicktime_read_stsd_audio(quicktime_
 	}
 }
 
-int quicktime_write_stsd_audio(quicktime_t *file, quicktime_stsd_table_t *table)
+void quicktime_write_stsd_audio(quicktime_t *file, quicktime_stsd_table_t *table)
 {
 	if (file->use_mp4) {
 		quicktime_write_int32(file, 0);
@@ -201,7 +201,7 @@ int quicktime_write_stsd_audio(quicktime
 	}
 }
 
-int quicktime_read_stsd_video(quicktime_t *file, quicktime_stsd_table_t *table, quicktime_atom_t *parent_atom)
+void quicktime_read_stsd_video(quicktime_t *file, quicktime_stsd_table_t *table, quicktime_atom_t *parent_atom)
 {
 	quicktime_atom_t leaf_atom;
 	int len;
@@ -264,7 +264,7 @@ int quicktime_read_stsd_video(quicktime_
 	}
 }
 
-int quicktime_write_stsd_video(quicktime_t *file, quicktime_stsd_table_t *table)
+void quicktime_write_stsd_video(quicktime_t *file, quicktime_stsd_table_t *table)
 {
 	if (file->use_mp4) {
 		int i;
@@ -314,32 +314,32 @@ int quicktime_write_stsd_video(quicktime
 	}
 }
 
-int quicktime_mjqt_init(quicktime_mjqt_t *mjqt)
+void quicktime_mjqt_init(quicktime_mjqt_t *mjqt)
 {
 }
 
-int quicktime_mjqt_delete(quicktime_mjqt_t *mjqt)
+void quicktime_mjqt_delete(quicktime_mjqt_t *mjqt)
 {
 }
 
-int quicktime_mjqt_dump(quicktime_mjqt_t *mjqt)
+void quicktime_mjqt_dump(quicktime_mjqt_t *mjqt)
 {
 }
 
 
-int quicktime_mjht_init(quicktime_mjht_t *mjht)
+void quicktime_mjht_init(quicktime_mjht_t *mjht)
 {
 }
 
-int quicktime_mjht_delete(quicktime_mjht_t *mjht)
+void quicktime_mjht_delete(quicktime_mjht_t *mjht)
 {
 }
 
-int quicktime_mjht_dump(quicktime_mjht_t *mjht)
+void quicktime_mjht_dump(quicktime_mjht_t *mjht)
 {
 }
 
-int quicktime_read_stsd_hint(quicktime_t *file, quicktime_stsd_table_t *table, quicktime_atom_t *parent_atom)
+void quicktime_read_stsd_hint(quicktime_t *file, quicktime_stsd_table_t *table, quicktime_atom_t *parent_atom)
 {
 	quicktime_atom_t leaf_atom;
 
@@ -357,7 +357,7 @@ int quicktime_read_stsd_hint(quicktime_t
 	}
 }
 
-int quicktime_write_stsd_hint(quicktime_t *file, quicktime_stsd_table_t *table)
+void quicktime_write_stsd_hint(quicktime_t *file, quicktime_stsd_table_t *table)
 {
 	quicktime_write_int16(file, table->version);
 	quicktime_write_int16(file, table->revision);
@@ -365,17 +365,17 @@ int quicktime_write_stsd_hint(quicktime_
 	quicktime_write_tims(file, &(table->tims));
 }
 
-int quicktime_tims_init(quicktime_tims_t *tims)
+void quicktime_tims_init(quicktime_tims_t *tims)
 {
 	tims->timeScale = 0;
 }
 
-int quicktime_read_tims(quicktime_t *file, quicktime_tims_t *tims)
+void quicktime_read_tims(quicktime_t *file, quicktime_tims_t *tims)
 {
 	tims->timeScale = quicktime_read_int32(file);
 }
 
-int quicktime_write_tims(quicktime_t *file, quicktime_tims_t *tims)
+void quicktime_write_tims(quicktime_t *file, quicktime_tims_t *tims)
 {
 	quicktime_atom_t atom;
 
