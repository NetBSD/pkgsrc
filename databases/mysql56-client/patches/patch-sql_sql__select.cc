$NetBSD: patch-sql_sql__select.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_select.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_select.cc
@@ -789,7 +789,7 @@ void JOIN::reset()
   }
 
   if (!(select_options & SELECT_DESCRIBE))
-    init_ftfuncs(thd, select_lex, test(order));
+    init_ftfuncs(thd, select_lex, my_test(order));
 
   DBUG_VOID_RETURN;
 }
@@ -931,7 +931,7 @@ bool JOIN::destroy()
   sjm_exec_list.empty();
 
   keyuse.clear();
-  DBUG_RETURN(test(error));
+  DBUG_RETURN(my_test(error));
 }
 
 
@@ -1687,7 +1687,7 @@ bool create_ref_for_key(JOIN *join, JOIN
     for (uint part_no= 0 ; part_no < keyparts ; part_no++)
     {
       keyuse= chosen_keyuses[part_no];
-      uint maybe_null= test(keyinfo->key_part[part_no].null_bit);
+      uint maybe_null= my_test(keyinfo->key_part[part_no].null_bit);
 
       if (keyuse->val->type() == Item::FIELD_ITEM)
       {
@@ -1925,7 +1925,7 @@ static Item *make_cond_for_index(Item *c
 	  new_cond->argument_list()->push_back(fix);
           used_tables|= fix->used_tables();
         }
-        n_marked += test(item->marker == ICP_COND_USES_INDEX_ONLY);
+        n_marked += my_test(item->marker == ICP_COND_USES_INDEX_ONLY);
       }
       if (n_marked ==((Item_cond*)cond)->argument_list()->elements)
         cond->marker= ICP_COND_USES_INDEX_ONLY;
@@ -1954,7 +1954,7 @@ static Item *make_cond_for_index(Item *c
 	if (!fix)
 	  return NULL;
 	new_cond->argument_list()->push_back(fix);
-        n_marked += test(item->marker == ICP_COND_USES_INDEX_ONLY);
+        n_marked += my_test(item->marker == ICP_COND_USES_INDEX_ONLY);
       }
       if (n_marked ==((Item_cond*)cond)->argument_list()->elements)
         cond->marker= ICP_COND_USES_INDEX_ONLY;
@@ -2759,7 +2759,7 @@ bool JOIN::setup_materialized_table(JOIN
 bool
 make_join_readinfo(JOIN *join, ulonglong options, uint no_jbuf_after)
 {
-  const bool statistics= test(!(join->select_options & SELECT_DESCRIBE));
+  const bool statistics= my_test(!(join->select_options & SELECT_DESCRIBE));
 
   DBUG_ENTER("make_join_readinfo");
 
@@ -4397,7 +4397,7 @@ test_if_subpart(ORDER *a,ORDER *b)
     else
       return 0;
   }
-  return test(!b);
+  return my_test(!b);
 }
 
 /**
@@ -5147,7 +5147,7 @@ bool JOIN::make_tmp_tables_info()
         or end_write_group()) if JOIN::group is set to false.
       */
       // the temporary table was explicitly requested
-      DBUG_ASSERT(test(select_options & OPTION_BUFFER_RESULT));
+      DBUG_ASSERT(my_test(select_options & OPTION_BUFFER_RESULT));
       // the temporary table does not have a grouping expression
       DBUG_ASSERT(!join_tab[curr_tmp_table].table->group); 
     }
