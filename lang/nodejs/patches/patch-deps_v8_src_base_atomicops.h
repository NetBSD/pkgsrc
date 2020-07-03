$NetBSD: patch-deps_v8_src_base_atomicops.h,v 1.4 2020/07/03 19:00:15 adam Exp $

--- deps/v8/src/base/atomicops.h.orig	2020-07-03 17:37:00.000000000 +0000
+++ deps/v8/src/base/atomicops.h
@@ -52,9 +52,13 @@ using Atomic64 = intptr_t;
 #endif  // defined(__ILP32__)
 #endif  // defined(V8_HOST_ARCH_64_BIT)
 
+#if defined(__NetBSD__) && defined(__arm__)
+using AtomicWord = int32_t;
+#else
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
 using AtomicWord = intptr_t;
+#endif
 
 // Atomically execute:
 //   result = *ptr;
