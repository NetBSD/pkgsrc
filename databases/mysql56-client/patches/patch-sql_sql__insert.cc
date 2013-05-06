$NetBSD: patch-sql_sql__insert.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_insert.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_insert.cc
@@ -759,7 +759,7 @@ bool mysql_insert(THD *thd,TABLE_LIST *t
                                            update,
                                            update_fields,
                                            fields,
-                                           !test(values->elements),
+                                           !my_test(values->elements),
                                            &can_prune_partitions,
                                            &prune_needs_default_values,
                                            &used_partitions))
@@ -1906,7 +1906,7 @@ int check_that_all_fields_are_given_valu
       if (table_list)
       {
         table_list= table_list->top_table();
-        view= test(table_list->view);
+        view= my_test(table_list->view);
       }
       if (view)
       {
@@ -3895,7 +3895,7 @@ static TABLE *create_table_from_items(TH
 
   tmp_table.s->db_create_options=0;
   tmp_table.s->db_low_byte_first= 
-        test(create_info->db_type == myisam_hton ||
+        my_test(create_info->db_type == myisam_hton ||
              create_info->db_type == heap_hton);
   tmp_table.null_row=tmp_table.maybe_null=0;
 
