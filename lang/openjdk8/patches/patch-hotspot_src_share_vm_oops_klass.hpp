$NetBSD: patch-hotspot_src_share_vm_oops_klass.hpp,v 1.1 2015/09/12 16:56:48 joerg Exp $

Left shift of negative values is UB.

--- hotspot/src/share/vm/oops/klass.hpp.orig	2015-09-03 15:25:36.000000000 +0000
+++ hotspot/src/share/vm/oops/klass.hpp
@@ -352,11 +352,11 @@ protected:
   }
   static bool layout_helper_is_typeArray(jint lh) {
     // _lh_array_tag_type_value == (lh >> _lh_array_tag_shift);
-    return (juint)lh >= (juint)(_lh_array_tag_type_value << _lh_array_tag_shift);
+    return (juint)lh >= ((juint)_lh_array_tag_type_value << _lh_array_tag_shift);
   }
   static bool layout_helper_is_objArray(jint lh) {
     // _lh_array_tag_obj_value == (lh >> _lh_array_tag_shift);
-    return (jint)lh < (jint)(_lh_array_tag_type_value << _lh_array_tag_shift);
+    return (jint)lh < (jint)((juint)_lh_array_tag_type_value << _lh_array_tag_shift);
   }
   static int layout_helper_header_size(jint lh) {
     assert(lh < (jint)_lh_neutral_value, "must be array");
