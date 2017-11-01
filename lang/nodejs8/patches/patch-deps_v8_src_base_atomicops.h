$NetBSD: patch-deps_v8_src_base_atomicops.h,v 1.1 2017/11/01 12:07:31 fhajny Exp $

--- deps/v8/src/base/atomicops.h.orig	2016-10-25 13:26:03.000000000 +0000
+++ deps/v8/src/base/atomicops.h
@@ -52,9 +52,13 @@ typedef intptr_t Atomic64;
 #endif  // defined(__ILP32__)
 #endif  // defined(V8_HOST_ARCH_64_BIT)
 
+#if defined(__NetBSD__) && defined(__arm__)
+typedef int32_t AtomicWord;
+#else
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
 typedef intptr_t AtomicWord;
+#endif
 
 // Atomically execute:
 //      result = *ptr;
