$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_os__bsd__zero.cpp,v 1.3 2018/09/14 15:53:46 tnn Exp $

SpinPause() needs to return a proper value, or we can apparently crash.
Already fixed in upstream openjdk8, but not in openjdk7.
Fix for JDK-8087120 stack frame pointer issue.

--- hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp.orig	2017-08-13 05:55:27.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp
@@ -60,8 +60,8 @@
 #include "utilities/vmError.hpp"
 
 address os::current_stack_pointer() {
-  address dummy = (address) &dummy;
-  return dummy;
+  // return the address of the current function
+  return (address)__builtin_frame_address(0);
 }
 
 frame os::get_sender_for_C_frame(frame* fr) {
@@ -464,6 +464,7 @@ void os::print_register_info(outputStrea
 
 extern "C" {
   int SpinPause() {
+    return 1;
   }
 
   int SafeFetch32(int *adr, int errValue) {
@@ -542,21 +543,6 @@ extern "C" {
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
