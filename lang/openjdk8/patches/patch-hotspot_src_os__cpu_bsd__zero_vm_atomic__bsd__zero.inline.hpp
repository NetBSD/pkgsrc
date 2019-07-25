$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_atomic__bsd__zero.inline.hpp,v 1.2 2019/07/25 12:00:08 tnn Exp $

match atomic op prototype

--- hotspot/src/os_cpu/bsd_zero/vm/atomic_bsd_zero.inline.hpp.orig	2019-07-18 21:55:16.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/atomic_bsd_zero.inline.hpp
@@ -260,7 +260,7 @@ inline jint Atomic::xchg(jint exchange_v
 inline intptr_t Atomic::xchg_ptr(intptr_t exchange_value,
                                  volatile intptr_t* dest) {
 #ifdef ARM
-  return arm_lock_test_and_set(dest, exchange_value);
+  return arm_lock_test_and_set((volatile int*)dest, exchange_value);
 #else
 #ifdef M68K
   return m68k_lock_test_and_set(dest, exchange_value);
