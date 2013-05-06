$NetBSD: patch-sql_item__cmpfunc.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item_cmpfunc.cc.orig	2013-05-05 20:55:22.000000000 +0000
+++ sql/item_cmpfunc.cc
@@ -497,7 +497,7 @@ static bool convert_constant_item(THD *t
                                      *item) :
 #endif
           new Item_int_with_ref(field->val_int(), *item,
-                                test(field->flags & UNSIGNED_FLAG));
+                                my_test(field->flags & UNSIGNED_FLAG));
         if (tmp)
           thd->change_item_tree(item, tmp);
         result= 1;                              // Item was replaced
@@ -1425,8 +1425,8 @@ int Arg_comparator::compare_e_string()
   res1= (*a)->val_str(&value1);
   res2= (*b)->val_str(&value2);
   if (!res1 || !res2)
-    return test(res1 == res2);
-  return test(sortcmp(res1, res2, cmp_collation.collation) == 0);
+    return my_test(res1 == res2);
+  return my_test(sortcmp(res1, res2, cmp_collation.collation) == 0);
 }
 
 
@@ -1436,8 +1436,8 @@ int Arg_comparator::compare_e_binary_str
   res1= (*a)->val_str(&value1);
   res2= (*b)->val_str(&value2);
   if (!res1 || !res2)
-    return test(res1 == res2);
-  return test(stringcmp(res1, res2) == 0);
+    return my_test(res1 == res2);
+  return my_test(stringcmp(res1, res2) == 0);
 }
 
 
@@ -1492,8 +1492,8 @@ int Arg_comparator::compare_e_real()
   double val1= (*a)->val_real();
   double val2= (*b)->val_real();
   if ((*a)->null_value || (*b)->null_value)
-    return test((*a)->null_value && (*b)->null_value);
-  return test(val1 == val2);
+    return my_test((*a)->null_value && (*b)->null_value);
+  return my_test(val1 == val2);
 }
 
 int Arg_comparator::compare_e_decimal()
@@ -1502,8 +1502,8 @@ int Arg_comparator::compare_e_decimal()
   my_decimal *val1= (*a)->val_decimal(&decimal1);
   my_decimal *val2= (*b)->val_decimal(&decimal2);
   if ((*a)->null_value || (*b)->null_value)
-    return test((*a)->null_value && (*b)->null_value);
-  return test(my_decimal_cmp(val1, val2) == 0);
+    return my_test((*a)->null_value && (*b)->null_value);
+  return my_test(my_decimal_cmp(val1, val2) == 0);
 }
 
 
@@ -1541,8 +1541,8 @@ int Arg_comparator::compare_e_real_fixed
   double val1= (*a)->val_real();
   double val2= (*b)->val_real();
   if ((*a)->null_value || (*b)->null_value)
-    return test((*a)->null_value && (*b)->null_value);
-  return test(val1 == val2 || fabs(val1 - val2) < precision);
+    return my_test((*a)->null_value && (*b)->null_value);
+  return my_test(val1 == val2 || fabs(val1 - val2) < precision);
 }
 
 
@@ -1616,8 +1616,8 @@ int Arg_comparator::compare_e_time_packe
   longlong val1= (*a)->val_time_temporal();
   longlong val2= (*b)->val_time_temporal();
   if ((*a)->null_value || (*b)->null_value)
-    return test((*a)->null_value && (*b)->null_value);
-  return test(val1 == val2);
+    return my_test((*a)->null_value && (*b)->null_value);
+  return my_test(val1 == val2);
 }
 
 
@@ -1708,8 +1708,8 @@ int Arg_comparator::compare_e_int()
   longlong val1= (*a)->val_int();
   longlong val2= (*b)->val_int();
   if ((*a)->null_value || (*b)->null_value)
-    return test((*a)->null_value && (*b)->null_value);
-  return test(val1 == val2);
+    return my_test((*a)->null_value && (*b)->null_value);
+  return my_test(val1 == val2);
 }
 
 /**
@@ -1720,8 +1720,8 @@ int Arg_comparator::compare_e_int_diff_s
   longlong val1= (*a)->val_int();
   longlong val2= (*b)->val_int();
   if ((*a)->null_value || (*b)->null_value)
-    return test((*a)->null_value && (*b)->null_value);
-  return (val1 >= 0) && test(val1 == val2);
+    return my_test((*a)->null_value && (*b)->null_value);
+  return (val1 >= 0) && my_test(val1 == val2);
 }
 
 int Arg_comparator::compare_row()
