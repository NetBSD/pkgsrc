$NetBSD: patch-ncurses_tinfo_comp__hash.c,v 1.1 2020/01/11 01:39:19 kim Exp $

Fix for CVE-2019-17594 cherry-picked from upstream patchlevel 20191012.
Check for invalid hashcode in _nc_find_type_entry and nc_find_entry.

https://bugs.debian.org/942401

--- ncurses/tinfo/comp_hash.c
+++ ncurses/tinfo/comp_hash.c
@@ -63,7 +63,9 @@ _nc_find_entry(const char *string,
 
     hashvalue = data->hash_of(string);
 
-    if (data->table_data[hashvalue] >= 0) {
+    if (hashvalue >= 0
+	&& (unsigned) hashvalue < data->table_size
+	&& data->table_data[hashvalue] >= 0) {
 
 	real_table = _nc_get_table(termcap);
 	ptr = real_table + data->table_data[hashvalue];
@@ -96,7 +98,9 @@ _nc_find_type_entry(const char *string,
     const HashData *data = _nc_get_hash_info(termcap);
     int hashvalue = data->hash_of(string);
 
-    if (data->table_data[hashvalue] >= 0) {
+    if (hashvalue >= 0
+	&& (unsigned) hashvalue < data->table_size
+	&& data->table_data[hashvalue] >= 0) {
 	const struct name_table_entry *const table = _nc_get_table(termcap);
 
 	ptr = table + data->table_data[hashvalue];
