$NetBSD: patch-sql_sql__optimizer.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_optimizer.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_optimizer.cc
@@ -739,13 +739,13 @@ JOIN::optimize()
   need_tmp= ((!plan_is_const() &&
 	     ((select_distinct || !simple_order || !simple_group) ||
 	      (group_list && order) ||
-	      test(select_options & OPTION_BUFFER_RESULT))) ||
+	      my_test(select_options & OPTION_BUFFER_RESULT))) ||
              (rollup.state != ROLLUP::STATE_NONE && select_distinct));
 
   /* Perform FULLTEXT search before all regular searches */
   if (!(select_options & SELECT_DESCRIBE))
   {
-    init_ftfuncs(thd, select_lex, test(order));
+    init_ftfuncs(thd, select_lex, my_test(order));
     optimize_fts_query();
   }
 
@@ -2504,7 +2504,7 @@ simplify_joins(JOIN *join, List<TABLE_LI
   NESTED_JOIN *nested_join;
   TABLE_LIST *prev_table= 0;
   List_iterator<TABLE_LIST> li(*join_list);
-  bool straight_join= test(join->select_options & SELECT_STRAIGHT_JOIN);
+  bool straight_join= my_test(join->select_options & SELECT_STRAIGHT_JOIN);
   DBUG_ENTER("simplify_joins");
 
   /* 
@@ -5416,8 +5416,8 @@ static int sort_keyuse(Key_use *a, Key_u
   if (a->keypart != b->keypart)
     return (int) (a->keypart - b->keypart);
   // Place const values before other ones
-  if ((res= test((a->used_tables & ~OUTER_REF_TABLE_BIT)) -
-       test((b->used_tables & ~OUTER_REF_TABLE_BIT))))
+  if ((res= my_test((a->used_tables & ~OUTER_REF_TABLE_BIT)) -
+       my_test((b->used_tables & ~OUTER_REF_TABLE_BIT))))
     return res;
   /* Place rows that are not 'OPTIMIZE_REF_OR_NULL' first */
   return (int) ((a->optimize & KEY_OPTIMIZE_REF_OR_NULL) -
