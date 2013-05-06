$NetBSD: patch-sql_sql__union.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_union.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_union.cc
@@ -271,7 +271,7 @@ bool st_select_lex_unit::prepare(THD *th
   bool is_union_select;
   DBUG_ENTER("st_select_lex_unit::prepare");
 
-  describe= test(additional_options & SELECT_DESCRIBE);
+  describe= my_test(additional_options & SELECT_DESCRIBE);
 
   /*
     result object should be reassigned even if preparing already done for
@@ -462,7 +462,7 @@ bool st_select_lex_unit::prepare(THD *th
     if (global_parameters->ftfunc_list->elements)
       create_options= create_options | TMP_TABLE_FORCE_MYISAM;
 
-    if (union_result->create_result_table(thd, &types, test(union_distinct),
+    if (union_result->create_result_table(thd, &types, my_test(union_distinct),
                                           create_options, "", FALSE, TRUE))
       goto err;
     memset(&result_table_list, 0, sizeof(result_table_list));
