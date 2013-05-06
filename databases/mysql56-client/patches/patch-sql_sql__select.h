$NetBSD: patch-sql_sql__select.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_select.h.orig	2013-05-05 20:54:55.000000000 +0000
+++ sql/sql_select.h
@@ -789,7 +789,7 @@ public:
       used_rowid_fields= 1;
       used_fieldlength+= table->file->ref_length;
     }
-    return test(used_rowid_fields);
+    return my_test(used_rowid_fields);
   }
   bool is_inner_table_of_outer_join()
   {
