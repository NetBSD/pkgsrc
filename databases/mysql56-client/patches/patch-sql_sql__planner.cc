$NetBSD: patch-sql_sql__planner.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_planner.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_planner.cc
@@ -193,7 +193,7 @@ public:
     }
   }
 
-  bool have_a_case() { return test(handled_sj_equalities); }
+  bool have_a_case() { return my_test(handled_sj_equalities); }
 
   /**
     Check if an index can be used for LooseScan, part 1
@@ -571,7 +571,7 @@ void Optimize_table_order::best_access_p
       }
       else
       {
-        found_constraint= test(found_part);
+        found_constraint= my_test(found_part);
         loose_scan_opt.check_ref_access_part1(s, key, start_key, found_part);
 
         /* Check if we found full key */
@@ -711,7 +711,7 @@ void Optimize_table_order::best_access_p
             */
             if (table->quick_keys.is_set(key) && !found_ref &&          //(C1)
                 table->quick_key_parts[key] == max_key_part &&          //(C2)
-                table->quick_n_ranges[key] == 1+test(ref_or_null_part)) //(C3)
+                table->quick_n_ranges[key] == 1+my_test(ref_or_null_part)) //(C3)
             {
               tmp= records= (double) table->quick_rows[key];
             }
@@ -813,7 +813,7 @@ void Optimize_table_order::best_access_p
                   table->quick_key_parts[key] <= max_key_part &&
                   const_part &
                     ((key_part_map)1 << table->quick_key_parts[key]) &&
-                  table->quick_n_ranges[key] == 1 + test(ref_or_null_part &
+                  table->quick_n_ranges[key] == 1 + my_test(ref_or_null_part &
                                                          const_part) &&
                   records > (double) table->quick_rows[key])
               {
@@ -1037,7 +1037,7 @@ void Optimize_table_order::best_access_p
       best_key= 0;
       /* range/index_merge/ALL/index access method are "independent", so: */
       best_ref_depends_map= 0;
-      best_uses_jbuf= test(!disable_jbuf);
+      best_uses_jbuf= my_test(!disable_jbuf);
     }
   }
 
@@ -1101,7 +1101,7 @@ bool Optimize_table_order::choose_table_
 
   reset_nj_counters(join->join_list);
 
-  const bool straight_join= test(join->select_options & SELECT_STRAIGHT_JOIN);
+  const bool straight_join= my_test(join->select_options & SELECT_STRAIGHT_JOIN);
   table_map join_tables;      ///< The tables involved in order selection
 
   if (emb_sjm_nest)
