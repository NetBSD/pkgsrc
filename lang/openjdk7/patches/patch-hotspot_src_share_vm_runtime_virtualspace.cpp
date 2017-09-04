$NetBSD: patch-hotspot_src_share_vm_runtime_virtualspace.cpp,v 1.1 2017/09/04 16:00:19 joerg Exp $

Pointers are not ordered relative to 0.

--- hotspot/src/share/vm/runtime/virtualspace.cpp.orig	2017-09-04 13:40:41.223301418 +0000
+++ hotspot/src/share/vm/runtime/virtualspace.cpp
@@ -527,7 +527,7 @@ ReservedHeapSpace::ReservedHeapSpace(siz
                 (UseCompressedOops && (Universe::narrow_oop_base() != NULL) &&
                  Universe::narrow_oop_use_implicit_null_checks()) ?
                   lcm(os::vm_page_size(), alignment) : 0) {
-  if (base() > 0) {
+  if (base()) {
     MemTracker::record_virtual_memory_type((address)base(), mtJavaHeap);
   }
 
@@ -546,7 +546,7 @@ ReservedHeapSpace::ReservedHeapSpace(con
                 (UseCompressedOops && (Universe::narrow_oop_base() != NULL) &&
                  Universe::narrow_oop_use_implicit_null_checks()) ?
                   lcm(os::vm_page_size(), prefix_align) : 0) {
-  if (base() > 0) {
+  if (base()) {
     MemTracker::record_virtual_memory_type((address)base(), mtJavaHeap);
   }
 
