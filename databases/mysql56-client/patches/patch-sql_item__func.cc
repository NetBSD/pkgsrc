$NetBSD: patch-sql_item__func.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item_func.cc.orig	2013-05-05 20:55:24.000000000 +0000
+++ sql/item_func.cc
@@ -2474,7 +2474,7 @@ void Item_func_round::fix_length_and_dec
   case INT_RESULT:
     if ((!decimals_to_set && truncate) || (args[0]->decimal_precision() < DECIMAL_LONGLONG_DIGITS))
     {
-      int length_can_increase= test(!truncate && (val1 < 0) && !val1_unsigned);
+      int length_can_increase= my_test(!truncate && (val1 < 0) && !val1_unsigned);
       max_length= args[0]->max_length + length_can_increase;
       /* Here we can keep INT_RESULT */
       hybrid_type= INT_RESULT;
@@ -4555,7 +4555,7 @@ longlong Item_func_sleep::val_int()
 
   mysql_cond_destroy(&cond);
 
-  return test(!error); 		// Return 1 killed
+  return my_test(!error); 		// Return 1 killed
 }
 
 
@@ -4726,7 +4726,7 @@ bool user_var_entry::realloc(uint length
 bool user_var_entry::store(void *from, uint length, Item_result type)
 {
   // Store strings with end \0
-  if (realloc(length + test(type == STRING_RESULT)))
+  if (realloc(length + my_test(type == STRING_RESULT)))
     return true;
   if (type == STRING_RESULT)
     m_ptr[length]= 0;     // Store end \0
@@ -6694,7 +6694,7 @@ void Item_func_sp::fix_length_and_dec()
   max_length= sp_result_field->field_length;
   collation.set(sp_result_field->charset());
   maybe_null= 1;
-  unsigned_flag= test(sp_result_field->flags & UNSIGNED_FLAG);
+  unsigned_flag= my_test(sp_result_field->flags & UNSIGNED_FLAG);
 
   DBUG_VOID_RETURN;
 }
