$NetBSD: patch-hotspot_src_share_vm_runtime_virtualspace.cpp,v 1.1 2016/12/15 23:56:53 joerg Exp $

Pointers are not ordered relative to 0.

--- hotspot/src/share/vm/runtime/virtualspace.cpp.orig	2016-12-10 16:09:08.597267563 +0000
+++ hotspot/src/share/vm/runtime/virtualspace.cpp
@@ -342,7 +342,7 @@ ReservedHeapSpace::ReservedHeapSpace(siz
                 (UseCompressedOops && (Universe::narrow_oop_base() != NULL) &&
                  Universe::narrow_oop_use_implicit_null_checks()) ?
                   lcm(os::vm_page_size(), alignment) : 0) {
-  if (base() > 0) {
+  if (base()) {
     MemTracker::record_virtual_memory_type((address)base(), mtJavaHeap);
   }
 
