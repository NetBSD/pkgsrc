$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_os__bsd__zero.cpp,v 1.1 2015/02/22 14:46:40 tnn Exp $

SpinPause() needs to return a proper value, or we can apparently crash.
Already fixed in upstream openjdk8, but not in openjdk7.

--- hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp.orig	2015-02-22 14:33:30.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp
@@ -464,6 +464,7 @@ void os::print_register_info(outputStrea
 
 extern "C" {
   int SpinPause() {
+    return 1;
   }
 
   int SafeFetch32(int *adr, int errValue) {
