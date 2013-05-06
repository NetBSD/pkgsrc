$NetBSD: patch-sql_sql__class.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_class.h.orig	2013-05-05 20:51:58.000000000 +0000
+++ sql/sql_class.h
@@ -3156,7 +3156,7 @@ public:
   }
   inline bool is_strict_mode() const
   {
-    return test(variables.sql_mode & (MODE_STRICT_TRANS_TABLES |
+    return my_test(variables.sql_mode & (MODE_STRICT_TRANS_TABLES |
                                       MODE_STRICT_ALL_TABLES));
   }
   inline Time_zone *time_zone()
@@ -4608,7 +4608,7 @@ public:
     table.str= internal_table_name;
     table.length=1;
   }
-  bool is_derived_table() const { return test(sel); }
+  bool is_derived_table() const { return my_test(sel); }
   inline void change_db(char *db_name)
   {
     db.str= db_name; db.length= (uint) strlen(db_name);
