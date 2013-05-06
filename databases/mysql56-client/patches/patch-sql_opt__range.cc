$NetBSD: patch-sql_opt__range.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/opt_range.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/opt_range.cc
@@ -468,7 +468,7 @@ public:
       new_max=arg->max_value; flag_max=arg->max_flag;
     }
     return new SEL_ARG(field, part, new_min, new_max, flag_min, flag_max,
-		       test(maybe_flag && arg->maybe_flag));
+		       my_test(maybe_flag && arg->maybe_flag));
   }
   SEL_ARG *clone_first(SEL_ARG *arg)
   {						// min <= X < arg->min
@@ -2938,7 +2938,7 @@ free_mem:
     Assume that if the user is using 'limit' we will only need to scan
     limit rows if we are using a key
   */
-  DBUG_RETURN(records ? test(quick) : -1);
+  DBUG_RETURN(records ? my_test(quick) : -1);
 }
 
 /****************************************************************************
@@ -3068,7 +3068,7 @@ typedef struct st_part_prune_param
   int last_subpart_partno; /* Same as above for supartitioning */
 
   /*
-    is_part_keypart[i] == test(keypart #i in partitioning index is a member
+    is_part_keypart[i] == my_test(keypart #i in partitioning index is a member
                                used in partitioning)
     Used to maintain current values of cur_part_fields and cur_subpart_fields
   */
@@ -3951,7 +3951,7 @@ process_next_key_part:
         ppar->mark_full_partition_used(ppar->part_info, part_id);
         found= TRUE;
       }
-      res= test(found);
+      res= my_test(found);
     }
     /*
       Restore the "used partitions iterator" to the default setting that
@@ -4979,7 +4979,7 @@ static double ror_scan_selectivity(const
   SEL_ARG *sel_arg, *tuple_arg= NULL;
   key_part_map keypart_map= 0;
   bool cur_covered;
-  bool prev_covered= test(bitmap_is_set(&info->covered_fields,
+  bool prev_covered= my_test(bitmap_is_set(&info->covered_fields,
                                         key_part->fieldnr-1));
   key_range min_range;
   key_range max_range;
@@ -4994,7 +4994,7 @@ static double ror_scan_selectivity(const
        sel_arg= sel_arg->next_key_part)
   {
     DBUG_PRINT("info",("sel_arg step"));
-    cur_covered= test(bitmap_is_set(&info->covered_fields,
+    cur_covered= my_test(bitmap_is_set(&info->covered_fields,
                                     key_part[sel_arg->part].fieldnr-1));
     if (cur_covered != prev_covered)
     {
@@ -9550,12 +9550,12 @@ get_quick_select(PARAM *param,uint idx,S
   if (param->table->key_info[param->real_keynr[idx]].flags & HA_SPATIAL)
     quick=new QUICK_RANGE_SELECT_GEOM(param->thd, param->table,
                                       param->real_keynr[idx],
-                                      test(parent_alloc),
+                                      my_test(parent_alloc),
                                       parent_alloc, &create_err);
   else
     quick=new QUICK_RANGE_SELECT(param->thd, param->table,
                                  param->real_keynr[idx],
-                                 test(parent_alloc), NULL, &create_err);
+                                 my_test(parent_alloc), NULL, &create_err);
 
   if (quick)
   {
@@ -10607,7 +10607,7 @@ int QUICK_RANGE_SELECT::get_next_prefix(
     const bool sorted= (mrr_flags & HA_MRR_SORTED);
     result= file->read_range_first(last_range->min_keypart_map ? &start_key : 0,
 				   last_range->max_keypart_map ? &end_key : 0,
-                                   test(last_range->flag & EQ_RANGE),
+                                   my_test(last_range->flag & EQ_RANGE),
 				   sorted);
     if (last_range->flag == (UNIQUE_RANGE | EQ_RANGE))
       last_range= 0;			// Stop searching
