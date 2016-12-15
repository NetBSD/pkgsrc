$NetBSD: patch-hotspot_src_share_vm_opto_lcm.cpp,v 1.1 2016/12/15 23:56:53 joerg Exp $

Pointers are not ordered relative to 0.

--- hotspot/src/share/vm/opto/lcm.cpp.orig	2016-12-10 16:03:32.851968675 +0000
+++ hotspot/src/share/vm/opto/lcm.cpp
@@ -49,7 +49,7 @@
 // Check whether val is not-null-decoded compressed oop,
 // i.e. will grab into the base of the heap if it represents NULL.
 static bool accesses_heap_base_zone(Node *val) {
-  if (Universe::narrow_oop_base() > 0) { // Implies UseCompressedOops.
+  if (Universe::narrow_oop_base()) { // Implies UseCompressedOops.
     if (val && val->is_Mach()) {
       if (val->as_Mach()->ideal_Opcode() == Op_DecodeN) {
         // This assumes all Decodes with TypePtr::NotNull are matched to nodes that
