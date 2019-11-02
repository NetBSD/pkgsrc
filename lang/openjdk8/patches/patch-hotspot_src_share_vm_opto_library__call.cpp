$NetBSD: patch-hotspot_src_share_vm_opto_library__call.cpp,v 1.2 2019/11/02 21:31:14 tnn Exp $

Left shift of negative values is UB.

--- hotspot/src/share/vm/opto/library_call.cpp.orig	2019-10-16 01:41:55.000000000 +0000
+++ hotspot/src/share/vm/opto/library_call.cpp
@@ -3803,7 +3803,7 @@ Node* LibraryCallKit::generate_array_gua
   }
   // Now test the correct condition.
   jint  nval = (obj_array
-                ? (jint)(Klass::_lh_array_tag_type_value
+                ? (jint)((juint)Klass::_lh_array_tag_type_value
                    <<    Klass::_lh_array_tag_shift)
                 : Klass::_lh_neutral_value);
   Node* cmp = _gvn.transform(new(C) CmpINode(layout_val, intcon(nval)));
