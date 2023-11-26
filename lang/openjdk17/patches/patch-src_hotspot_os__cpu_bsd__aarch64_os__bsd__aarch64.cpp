$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_os__bsd__aarch64.cpp,v 1.3 2023/11/26 10:48:46 tnn Exp $

Fix mis-merge.

--- src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp.orig	2023-11-26 10:38:45.728534591 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp
@@ -962,6 +962,7 @@ void os::print_context(outputStream *st,
 #endif
   }
   st->cr();
+}
 
 void os::print_tos_pc(outputStream *st, const void *context) {
   if (context == NULL) return;
