$NetBSD: patch-hotspot_src_share_vm_opto_library__call.cpp,v 1.1 2015/09/12 16:56:48 joerg Exp $

Left shift of negative values is UB.

--- hotspot/src/share/vm/opto/library_call.cpp.orig	2015-06-09 13:47:01.000000000 +0000
+++ hotspot/src/share/vm/opto/library_call.cpp
@@ -3454,8 +3454,8 @@ Node* LibraryCallKit::generate_array_gua
   }
   // Now test the correct condition.
   jint  nval = (obj_array
-                ? ((jint)Klass::_lh_array_tag_type_value
-                   <<    Klass::_lh_array_tag_shift)
+                ? (jint)((juint)Klass::_lh_array_tag_type_value
+                         <<    Klass::_lh_array_tag_shift)
                 : Klass::_lh_neutral_value);
   Node* cmp = _gvn.transform( new(C) CmpINode(layout_val, intcon(nval)) );
   BoolTest::mask btest = BoolTest::lt;  // correct for testing is_[obj]array
