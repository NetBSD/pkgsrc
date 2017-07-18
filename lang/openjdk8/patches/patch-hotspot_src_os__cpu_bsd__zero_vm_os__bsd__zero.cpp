$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_os__bsd__zero.cpp,v 1.2 2017/07/18 19:53:11 jmcneill Exp $

Fix -Werror=return-local-addr with gcc.

clang objects to redefining builtins.

--- hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp.orig	2017-04-27 09:45:07.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp
@@ -60,8 +60,7 @@
 #include "utilities/vmError.hpp"
 
 address os::current_stack_pointer() {
-  address dummy = (address) &dummy;
-  return dummy;
+  return (address) __builtin_frame_address(0);
 }
 
 frame os::get_sender_for_C_frame(frame* fr) {
@@ -446,21 +445,6 @@ extern "C" {
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
