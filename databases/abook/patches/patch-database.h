$NetBSD: patch-database.h,v 1.1 2011/08/20 15:27:09 joerg Exp $

--- database.h.orig	2011-08-20 13:47:08.000000000 +0000
+++ database.h
@@ -60,7 +60,7 @@ struct db_enumerator {
 /*
  * Field operations
  */
-inline int field_id(int i);
+int field_id(int i);
 abook_field *find_standard_field(char *key, int do_declare);
 abook_field *real_find_field(char *key, abook_field_list *list, int *nb);
 #define find_field(key, list)		real_find_field(key, list, NULL)
