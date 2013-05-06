$NetBSD: patch-sql_sql__partition.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_partition.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_partition.cc
@@ -3294,7 +3294,7 @@ uint32 get_partition_id_cols_list_for_en
     }
     else 
     {
-      DBUG_RETURN(list_index + test(!tailf));
+      DBUG_RETURN(list_index + my_test(!tailf));
     }
   } while (max_list_index >= min_list_index);
   if (cmp > 0)
@@ -3370,7 +3370,7 @@ uint32 get_list_array_idx_for_endpoint(p
     }
     else 
     {
-      DBUG_RETURN(list_index + test(left_endpoint ^ include_endpoint));
+      DBUG_RETURN(list_index + my_test(left_endpoint ^ include_endpoint));
     }
   } while (max_list_index >= min_list_index);
 notfound:
@@ -5846,7 +5846,7 @@ static bool mysql_change_partitions(ALTE
   if (mysql_trans_commit_alter_copy_data(thd))
     error= 1;                                /* The error has been reported */
 
-  DBUG_RETURN(test(error));
+  DBUG_RETURN(my_test(error));
 }
 
 
@@ -7720,7 +7720,7 @@ uint32 get_partition_id_cols_range_for_e
                                        loc_part_id * num_columns,
                                        nparts, tailf);
       if (!res)
-        loc_part_id += test(include_endpoint);
+        loc_part_id += my_test(include_endpoint);
       else if (res > 0)
         loc_part_id++;
     }
@@ -7902,7 +7902,7 @@ int get_part_iter_for_interval_via_mappi
         index-in-ordered-array-of-list-constants (for LIST) space.
       */
       store_key_image_to_rec(field, min_value, field_len);
-      bool include_endp= !test(flags & NEAR_MIN);
+      bool include_endp= !my_test(flags & NEAR_MIN);
       part_iter->part_nums.start= get_endpoint(part_info, 1, include_endp);
       if (!can_match_multiple_values && part_info->part_expr->null_value)
       {
@@ -7937,7 +7937,7 @@ int get_part_iter_for_interval_via_mappi
   else
   {
     store_key_image_to_rec(field, max_value, field_len);
-    bool include_endp= !test(flags & NEAR_MAX);
+    bool include_endp= !my_test(flags & NEAR_MAX);
     part_iter->part_nums.end= get_endpoint(part_info, 0, include_endp);
     if (check_zero_dates &&
         !zero_in_start_date &&
@@ -8104,8 +8104,8 @@ int get_part_iter_for_interval_via_walki
   if ((ulonglong)b - (ulonglong)a == ~0ULL)
     DBUG_RETURN(-1);
 
-  a += test(flags & NEAR_MIN);
-  b += test(!(flags & NEAR_MAX));
+  a += my_test(flags & NEAR_MIN);
+  b += my_test(!(flags & NEAR_MAX));
   ulonglong n_values= b - a;
 
   /*
