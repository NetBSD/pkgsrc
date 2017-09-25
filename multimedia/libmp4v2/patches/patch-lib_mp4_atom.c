$NetBSD: patch-lib_mp4_atom.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/atom.c.orig	2017-09-25 14:43:07.119068459 +0000
+++ lib/mp4/atom.c
@@ -1,5 +1,7 @@
 #include "quicktime.h"
 
+int quicktime_atom_read_type(char *data, char *type);
+
 
 int quicktime_atom_reset(quicktime_atom_t *atom)
 {
@@ -60,14 +62,14 @@ int quicktime_atom_read_header(quicktime
 	return result;
 }
 
-int quicktime_atom_write_header(quicktime_t *file, quicktime_atom_t *atom, char *text)
+void quicktime_atom_write_header(quicktime_t *file, quicktime_atom_t *atom, char *text)
 {
 	atom->start = quicktime_position(file);
 	quicktime_write_int32(file, 0);
 	quicktime_write_char32(file, text);
 }
 
-int quicktime_atom_write_footer(quicktime_t *file, quicktime_atom_t *atom)
+void quicktime_atom_write_footer(quicktime_t *file, quicktime_atom_t *atom)
 {
 	atom->end = quicktime_position(file);
 	quicktime_set_position(file, atom->start);
