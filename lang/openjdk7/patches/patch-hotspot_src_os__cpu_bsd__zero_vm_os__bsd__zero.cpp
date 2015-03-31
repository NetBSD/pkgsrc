$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_os__bsd__zero.cpp,v 1.2 2015/03/31 15:45:40 joerg Exp $

SpinPause() needs to return a proper value, or we can apparently crash.
Already fixed in upstream openjdk8, but not in openjdk7.

--- hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp.orig	2015-03-25 16:27:54.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp
@@ -464,6 +464,7 @@ void os::print_register_info(outputStrea
 
 extern "C" {
   int SpinPause() {
+    return 1;
   }
 
   int SafeFetch32(int *adr, int errValue) {
@@ -543,21 +544,6 @@ extern "C" {
   }
 };
 
-/////////////////////////////////////////////////////////////////////////////
-// Implementations of atomic operations not supported by processors.
-//  -- http://gcc.gnu.org/onlinedocs/gcc-4.2.1/gcc/Atomic-Builtins.html
-
-#ifndef _LP64
-extern "C" {
-  long long unsigned int __sync_val_compare_and_swap_8(
-    volatile void *ptr,
-    long long unsigned int oldval,
-    long long unsigned int newval) {
-    ShouldNotCallThis();
-  }
-};
-#endif // !_LP64
-
 #ifndef PRODUCT
 void os::verify_stack_alignment() {
 }
