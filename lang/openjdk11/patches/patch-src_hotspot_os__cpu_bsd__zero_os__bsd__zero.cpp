$NetBSD: patch-src_hotspot_os__cpu_bsd__zero_os__bsd__zero.cpp,v 1.1 2022/05/25 06:05:34 tnn Exp $

#if 0 functions already defined in os_bsd.cpp

--- src/hotspot/os_cpu/bsd_zero/os_bsd_zero.cpp.orig	2022-05-03 03:11:37.000000000 +0000
+++ src/hotspot/os_cpu/bsd_zero/os_bsd_zero.cpp
@@ -340,13 +340,16 @@ static void current_stack_region(address
   *size = stack_top - stack_bottom;
 }
 
+#if 0
 address os::current_stack_base() {
   address bottom;
   size_t size;
   current_stack_region(&bottom, &size);
   return bottom + size;
 }
+#endif
 
+#if 0
 size_t os::current_stack_size() {
   // stack size includes normal stack and HotSpot guard pages
   address bottom;
@@ -354,6 +357,7 @@ size_t os::current_stack_size() {
   current_stack_region(&bottom, &size);
   return size;
 }
+#endif
 
 /////////////////////////////////////////////////////////////////////////////
 // helper functions for fatal error handler
