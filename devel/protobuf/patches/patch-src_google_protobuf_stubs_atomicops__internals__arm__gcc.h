$NetBSD: patch-src_google_protobuf_stubs_atomicops__internals__arm__gcc.h,v 1.3 2017/02/07 13:50:31 wiz Exp $

Add ARM support.

--- src/google/protobuf/stubs/atomicops_internals_arm_gcc.h.orig	2017-01-27 23:49:29.000000000 +0000
+++ src/google/protobuf/stubs/atomicops_internals_arm_gcc.h
@@ -39,44 +39,19 @@ namespace google {
 namespace protobuf {
 namespace internal {
 
-// 0xffff0fc0 is the hard coded address of a function provided by
-// the kernel which implements an atomic compare-exchange. On older
-// ARM architecture revisions (pre-v6) this may be implemented using
-// a syscall. This address is stable, and in active use (hard coded)
-// by at least glibc-2.7 and the Android C library.
-typedef Atomic32 (*LinuxKernelCmpxchgFunc)(Atomic32 old_value,
-                                           Atomic32 new_value,
-                                           volatile Atomic32* ptr);
-LinuxKernelCmpxchgFunc pLinuxKernelCmpxchg __attribute__((weak)) =
-    (LinuxKernelCmpxchgFunc) 0xffff0fc0;
-
-typedef void (*LinuxKernelMemoryBarrierFunc)(void);
-LinuxKernelMemoryBarrierFunc pLinuxKernelMemoryBarrier __attribute__((weak)) =
-    (LinuxKernelMemoryBarrierFunc) 0xffff0fa0;
-
-
 inline Atomic32 NoBarrier_CompareAndSwap(volatile Atomic32* ptr,
                                          Atomic32 old_value,
                                          Atomic32 new_value) {
-  Atomic32 prev_value = *ptr;
-  do {
-    if (!pLinuxKernelCmpxchg(old_value, new_value,
-                             const_cast<Atomic32*>(ptr))) {
-      return old_value;
-    }
-    prev_value = *ptr;
-  } while (prev_value == old_value);
-  return prev_value;
+  return __sync_val_compare_and_swap(ptr, old_value, new_value);
 }
 
 inline Atomic32 NoBarrier_AtomicExchange(volatile Atomic32* ptr,
                                          Atomic32 new_value) {
-  Atomic32 old_value;
+  Atomic32 prev_value;
   do {
-    old_value = *ptr;
-  } while (pLinuxKernelCmpxchg(old_value, new_value,
-                               const_cast<Atomic32*>(ptr)));
-  return old_value;
+    prev_value = *ptr;
+  } while (!__sync_bool_compare_and_swap(ptr, prev_value, new_value));
+  return prev_value;
 }
 
 inline Atomic32 NoBarrier_AtomicIncrement(volatile Atomic32* ptr,
@@ -86,17 +61,15 @@ inline Atomic32 NoBarrier_AtomicIncremen
 
 inline Atomic32 Barrier_AtomicIncrement(volatile Atomic32* ptr,
                                         Atomic32 increment) {
-  for (;;) {
+  Atomic32 old_value;
+  Atomic32 new_value;
+
+  do {
     // Atomic exchange the old value with an incremented one.
-    Atomic32 old_value = *ptr;
-    Atomic32 new_value = old_value + increment;
-    if (pLinuxKernelCmpxchg(old_value, new_value,
-                            const_cast<Atomic32*>(ptr)) == 0) {
-      // The exchange took place as expected.
-      return new_value;
-    }
-    // Otherwise, *ptr changed mid-loop and we need to retry.
-  }
+    old_value = *ptr;
+    new_value = old_value + increment;
+  } while (!__sync_bool_compare_and_swap(ptr, old_value, new_value));
+  return new_value;
 }
 
 inline Atomic32 Acquire_CompareAndSwap(volatile Atomic32* ptr,
@@ -116,7 +89,7 @@ inline void NoBarrier_Store(volatile Ato
 }
 
 inline void MemoryBarrierInternal() {
-  pLinuxKernelMemoryBarrier();
+  __sync_synchronize();
 }
 
 inline void Acquire_Store(volatile Atomic32* ptr, Atomic32 value) {
