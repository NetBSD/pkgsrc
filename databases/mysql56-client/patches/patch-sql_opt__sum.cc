$NetBSD: patch-sql_opt__sum.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/opt_sum.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/opt_sum.cc
@@ -304,7 +304,7 @@ int opt_sum_query(THD *thd,
     }
     else
     {
-      maybe_exact_count&= test(table_filled &&
+      maybe_exact_count&= my_test(table_filled &&
                                (tl->table->file->ha_table_flags() &
                                 HA_HAS_RECORDS));
       is_exact_count= FALSE;
@@ -379,7 +379,7 @@ int opt_sum_query(THD *thd,
       case Item_sum::MIN_FUNC:
       case Item_sum::MAX_FUNC:
       {
-        int is_max= test(item_sum->sum_func() == Item_sum::MAX_FUNC);
+        int is_max= my_test(item_sum->sum_func() == Item_sum::MAX_FUNC);
         /*
           If MIN/MAX(expr) is the first part of a key or if all previous
           parts of the key is found in the COND, then we can use
@@ -811,7 +811,7 @@ static bool matching_cond(bool max_fl, T
       Item *value= args[between && max_fl ? 2 : 1];
       value->save_in_field_no_warnings(part->field, true);
       if (part->null_bit) 
-        *key_ptr++= (uchar) test(part->field->is_null());
+        *key_ptr++= (uchar) my_test(part->field->is_null());
       part->field->get_key_image(key_ptr, part->length, Field::itRAW);
     }
     if (is_field_part)
@@ -831,7 +831,7 @@ static bool matching_cond(bool max_fl, T
   else if (eq_type)
   {
     if ((!is_null && !cond->val_int()) ||
-        (is_null && !test(part->field->is_null())))
+        (is_null && !my_test(part->field->is_null())))
      DBUG_RETURN(FALSE);                       // Impossible test
   }
   else if (is_field_part)
