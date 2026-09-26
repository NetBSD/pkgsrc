$NetBSD: patch-src_hotspot_share_runtime_arguments.cpp,v 1.1 2026/09/26 12:54:51 tnn Exp $

WIP try to prevent overflow on 32-bit when running in a chroot
and the host has more than 4 GB of RAM.

--- src/hotspot/share/runtime/arguments.cpp.orig	2026-09-05 22:40:16.647006757 +0000
+++ src/hotspot/share/runtime/arguments.cpp
@@ -1534,6 +1534,8 @@ void Arguments::set_heap_size() {
       reasonable_max = MIN2(reasonable_max, (julong)ErgoHeapSizeLimit);
     }
 
+    reasonable_max = MIN2(reasonable_max, (julong)ULONG_MAX);
+
     reasonable_max = limit_heap_by_allocatable_memory(reasonable_max);
 
     if (!FLAG_IS_DEFAULT(InitialHeapSize)) {
