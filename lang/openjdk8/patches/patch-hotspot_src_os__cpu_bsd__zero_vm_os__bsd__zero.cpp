$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_os__bsd__zero.cpp,v 1.4 2022/09/24 09:51:54 nia Exp $

delay evaluation of __has_builtin after the !_LP64 case, this is an attempted
workaround for the following compiler error on aarch64:

os_bsd_zero.cpp:453:38: error: missing binary operator before token "("
 #if !defined(_LP64) && !__has_builtin(__sync_val_compare_and_swap_8)
                                      ^
--- hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp.orig	2022-07-31 16:21:00.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp
@@ -450,7 +450,8 @@ extern "C" {
 // Implementations of atomic operations not supported by processors.
 //  -- http://gcc.gnu.org/onlinedocs/gcc-4.2.1/gcc/Atomic-Builtins.html
 
-#if !defined(_LP64) && !__has_builtin(__sync_val_compare_and_swap_8)
+#if !defined(_LP64)
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
