$NetBSD: patch-sql_sql__executor.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_executor.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_executor.cc
@@ -1455,7 +1455,7 @@ evaluate_join_record(JOIN *join, JOIN_TA
 
   if (condition)
   {
-    found= test(condition->val_int());
+    found= my_test(condition->val_int());
 
     if (join->thd->killed)
     {
@@ -1863,7 +1863,7 @@ join_read_const_table(JOIN_TAB *tab, POS
   {
     // We cannot handle outer-joined tables with expensive join conditions here:
     DBUG_ASSERT(!(*tab->on_expr_ref)->is_expensive());
-    if ((table->null_row= test((*tab->on_expr_ref)->val_int() == 0)))
+    if ((table->null_row= my_test((*tab->on_expr_ref)->val_int() == 0)))
       mark_as_null_row(table);  
   }
   if (!table->null_row)
