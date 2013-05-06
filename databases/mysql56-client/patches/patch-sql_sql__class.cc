$NetBSD: patch-sql_sql__class.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_class.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_class.cc
@@ -553,14 +553,14 @@ extern "C" int mysql_tmpfile(const char 
 extern "C"
 int thd_in_lock_tables(const THD *thd)
 {
-  return test(thd->in_lock_tables);
+  return my_test(thd->in_lock_tables);
 }
 
 
 extern "C"
 int thd_tablespace_op(const THD *thd)
 {
-  return test(thd->tablespace_op);
+  return my_test(thd->tablespace_op);
 }
 
 
@@ -2535,7 +2535,7 @@ void select_to_file::send_error(uint err
 
 bool select_to_file::send_eof()
 {
-  int error= test(end_io_cache(&cache));
+  int error= my_test(end_io_cache(&cache));
   if (mysql_file_close(file, MYF(MY_WME)) || thd->is_error())
     error= true;
 
@@ -2716,8 +2716,8 @@ select_export::prepare(List<Item> &list,
     escape_char= (int) (uchar) (*exchange->escaped)[0];
   else
     escape_char= -1;
-  is_ambiguous_field_sep= test(strchr(ESCAPE_CHARS, field_sep_char));
-  is_unsafe_field_sep= test(strchr(NUMERIC_CHARS, field_sep_char));
+  is_ambiguous_field_sep= my_test(strchr(ESCAPE_CHARS, field_sep_char));
+  is_unsafe_field_sep= my_test(strchr(NUMERIC_CHARS, field_sep_char));
   line_sep_char= (exchange->line_term->length() ?
                  (int) (uchar) (*exchange->line_term)[0] : INT_MAX);
   if (!field_term_length)
