$NetBSD: patch-sql_sql__lex.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_lex.h.orig	2013-05-05 20:52:49.000000000 +0000
+++ sql/sql_lex.h
@@ -1201,7 +1201,7 @@ public:
   }
   bool requires_prelocking()
   {
-    return test(query_tables_own_last);
+    return my_test(query_tables_own_last);
   }
   void mark_as_requiring_prelocking(TABLE_LIST **tables_own_last)
   {
