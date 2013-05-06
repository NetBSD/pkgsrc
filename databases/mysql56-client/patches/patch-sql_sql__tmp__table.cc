$NetBSD: patch-sql_sql__tmp__table.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_tmp_table.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_tmp_table.cc
@@ -1006,7 +1006,7 @@ update_hidden:
     table->group=group;				/* Table is grouped by key */
     param->group_buff=group_buff;
     share->keys=1;
-    share->uniques= test(using_unique_constraint);
+    share->uniques= my_test(using_unique_constraint);
     table->key_info= share->key_info= keyinfo;
     keyinfo->key_part= key_part_info;
     keyinfo->flags=HA_NOSAME;
@@ -1028,7 +1028,7 @@ update_hidden:
       {
 	cur_group->buff=(char*) group_buff;
 	cur_group->field= field->new_key_field(thd->mem_root, table,
-                                               group_buff + test(maybe_null));
+                                               group_buff + my_test(maybe_null));
 
 	if (!cur_group->field)
 	  goto err; /* purecov: inspected */
@@ -1076,7 +1076,7 @@ update_hidden:
     null_pack_length-=hidden_null_pack_length;
     keyinfo->user_defined_key_parts= 
       ((field_count-param->hidden_field_count) +
-       (share->uniques ? test(null_pack_length) : 0));
+       (share->uniques ? my_test(null_pack_length) : 0));
     keyinfo->actual_key_parts= keyinfo->user_defined_key_parts;
     table->distinct= 1;
     share->keys= 1;
@@ -1400,7 +1400,7 @@ TABLE *create_duplicate_weedout_tmp_tabl
   {
     DBUG_PRINT("info",("Creating group key in temporary table"));
     share->keys=1;
-    share->uniques= test(using_unique_constraint);
+    share->uniques= my_test(using_unique_constraint);
     table->key_info= table->s->key_info= keyinfo;
     keyinfo->key_part=key_part_info;
     keyinfo->actual_flags= keyinfo->flags= HA_NOSAME;
