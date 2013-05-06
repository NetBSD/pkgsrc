$NetBSD: patch-sql_sql__base.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_base.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_base.cc
@@ -1612,7 +1612,7 @@ bool close_temporary_tables(THD *thd)
 
   /* We always quote db,table names though it is slight overkill */
   if (found_user_tables &&
-      !(was_quote_show= test(thd->variables.option_bits & OPTION_QUOTE_SHOW_CREATE)))
+      !(was_quote_show= my_test(thd->variables.option_bits & OPTION_QUOTE_SHOW_CREATE)))
   {
     thd->variables.option_bits |= OPTION_QUOTE_SHOW_CREATE;
   }
@@ -8211,7 +8211,7 @@ bool setup_fields(THD *thd, Ref_ptr_arra
   thd->lex->allow_sum_func= save_allow_sum_func;
   thd->mark_used_columns= save_mark_used_columns;
   DBUG_PRINT("info", ("thd->mark_used_columns: %d", thd->mark_used_columns));
-  DBUG_RETURN(test(thd->is_error()));
+  DBUG_RETURN(my_test(thd->is_error()));
 }
 
 
@@ -8775,7 +8775,7 @@ int setup_conds(THD *thd, TABLE_LIST *ta
   }
 
   thd->lex->current_select->is_item_list_lookup= save_is_item_list_lookup;
-  DBUG_RETURN(test(thd->is_error()));
+  DBUG_RETURN(my_test(thd->is_error()));
 
 err_no_arena:
   select_lex->is_item_list_lookup= save_is_item_list_lookup;
