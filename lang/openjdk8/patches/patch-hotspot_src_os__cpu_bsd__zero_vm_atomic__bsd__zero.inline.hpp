$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_atomic__bsd__zero.inline.hpp,v 1.1 2015/02/20 09:38:00 tnn Exp $

ARM: Substitute Linux atomic ops with NetBSD atomic ops

--- hotspot/src/os_cpu/bsd_zero/vm/atomic_bsd_zero.inline.hpp.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/atomic_bsd_zero.inline.hpp
@@ -112,8 +112,13 @@ static inline int m68k_lock_test_and_set
  *
  */
 
+#ifdef __NetBSD__
+#include <sys/atomic.h>
+#define __kernel_cmpxchg(oldval, newval, ptr) ((unsigned int)(oldval) != atomic_cas_uint((volatile unsigned int*)(ptr), (unsigned int)(oldval), (unsigned int)(newval)))
+#else
 typedef int (__kernel_cmpxchg_t)(int oldval, int newval, volatile int *ptr);
 #define __kernel_cmpxchg (*(__kernel_cmpxchg_t *) 0xffff0fc0)
+#endif
 
 
 
@@ -189,7 +194,7 @@
 
 inline intptr_t Atomic::add_ptr(intptr_t add_value, volatile intptr_t* dest) {
 #ifdef ARM
-  return arm_add_and_fetch(dest, add_value);
+  return arm_add_and_fetch((volatile int*)dest, add_value);
 #else
 #ifdef M68K
   return m68k_add_and_fetch(dest, add_value);
@@ -246,7 +251,7 @@
 inline intptr_t Atomic::xchg_ptr(intptr_t exchange_value,
                                  volatile intptr_t* dest) {
 #ifdef ARM
-  return arm_lock_test_and_set(dest, exchange_value);
+  return arm_lock_test_and_set((volatile int*)dest, exchange_value);
 #else
 #ifdef M68K
   return m68k_lock_test_and_set(dest, exchange_value);
@@ -286,7 +291,7 @@
                                     volatile intptr_t* dest,
                                     intptr_t compare_value) {
 #ifdef ARM
-  return arm_compare_and_swap(dest, compare_value, exchange_value);
+  return arm_compare_and_swap((volatile int*)dest, compare_value, exchange_value);
 #else
 #ifdef M68K
   return m68k_compare_and_swap(dest, compare_value, exchange_value);
