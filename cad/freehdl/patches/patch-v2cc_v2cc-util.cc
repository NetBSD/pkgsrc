$NetBSD: patch-v2cc_v2cc-util.cc,v 1.1 2013/04/30 22:13:57 joerg Exp $

--- v2cc/v2cc-util.cc.orig	2013-04-30 20:26:59.000000000 +0000
+++ v2cc/v2cc-util.cc
@@ -137,7 +137,7 @@ to_string(pIIR_ScalarType type, const St
     }
   else if (base_type->is (IR_FLOATING_TYPE))
     {
-      str = to_string (v.double_value ());
+      str = ::to_string (v.double_value ());
     }
 
   return str;
@@ -536,7 +536,7 @@ emit_folded_value(StaticDataType &data, 
   if (base_type->is(IR_ENUMERATION_TYPE))
     str += "enumeration(" + to_string(data.long_value()) + ")";
   else if (base_type->is(IR_FLOATING_TYPE))
-    str += to_string(data.double_value());
+    str += ::to_string(data.double_value());
   else if (base_type->is(IR_PHYSICAL_TYPE))
     str += to_string(data.long_value()) + "LL";
   else if (base_type->is(IR_ARRAY_TYPE)) 
@@ -568,7 +568,7 @@ cdfg_emit_folded_value(StaticDataType &d
   else if (base_type->is(IR_FLOATING_TYPE)) {
     // Replace 'e' ein the floating point number by 'l' in order to
     // match the definition of doubles in lisp.
-    string result = to_string(data.double_value());
+    string result = ::to_string(data.double_value());
     for (unsigned int i = 0; i < result.length(); i++)
       if (result[i] == 'e' ||
 	  result[i] == 'E')
@@ -1772,8 +1772,8 @@ check_scalar_against_bounds(pIIR_Root n,
   StaticRangeDescriptor<double, IR_Direction> range = 
     range_des_vec[0].rangedes_to_double(rstack);
 
-  string left_str = to_string(range.left);
-  string right_str = to_string(range.right);
+  string left_str = ::to_string(range.left);
+  string right_str = ::to_string(range.right);
   if (!range.valid[1]) {
     // If the range is not static then do not perform any furhter
     // checks. All checks will be done at runtime.
