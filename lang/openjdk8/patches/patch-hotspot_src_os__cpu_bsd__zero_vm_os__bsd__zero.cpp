$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_os__bsd__zero.cpp,v 1.6 2023/02/27 11:09:40 jperkin Exp $

Fix building with GCC < 10.

--- hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp.orig	2022-07-31 16:21:00.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp
@@ -450,7 +450,8 @@ extern "C" {
 // Implementations of atomic operations not supported by processors.
 //  -- http://gcc.gnu.org/onlinedocs/gcc-4.2.1/gcc/Atomic-Builtins.html
 
-#if !defined(_LP64) && !__has_builtin(__sync_val_compare_and_swap_8)
+#if !defined(_LP64) && defined(__has_builtin)
+#if !__has_builtin(__sync_val_compare_and_swap_8)
 extern "C" {
   long long unsigned int __sync_val_compare_and_swap_8(
     volatile void *ptr,
@@ -460,6 +461,7 @@ extern "C" {
     return 0; // silence compiler warnings
   }
 };
+#endif
 #endif // !_LP64
 
 #ifndef PRODUCT
