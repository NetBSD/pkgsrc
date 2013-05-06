$NetBSD: patch-sql_field__conv.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/field_conv.cc.orig	2013-05-05 20:55:14.000000000 +0000
+++ sql/field_conv.cc
@@ -330,7 +330,7 @@ static void do_field_int(Copy_field *cop
 {
   longlong value= copy->from_field->val_int();
   copy->to_field->store(value,
-                        test(copy->from_field->flags & UNSIGNED_FLAG));
+                        my_test(copy->from_field->flags & UNSIGNED_FLAG));
 }
 
 static void do_field_real(Copy_field *copy)
@@ -898,5 +898,5 @@ type_conversion_status field_conv(Field 
     return to->store_decimal(from->val_decimal(&buff));
   }
   else
-    return to->store(from->val_int(), test(from->flags & UNSIGNED_FLAG));
+    return to->store(from->val_int(), my_test(from->flags & UNSIGNED_FLAG));
 }
