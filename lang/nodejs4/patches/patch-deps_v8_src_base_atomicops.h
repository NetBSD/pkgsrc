$NetBSD: patch-deps_v8_src_base_atomicops.h,v 1.1 2015/11/09 20:21:51 fhajny Exp $

--- deps/v8/src/base/atomicops.h.orig	2015-10-13 17:20:07.000000000 +0000
+++ deps/v8/src/base/atomicops.h
@@ -54,9 +54,13 @@ typedef intptr_t Atomic64;
 #endif  // defined(V8_HOST_ARCH_64_BIT)
 #endif  // defined(__native_client__)
 
+#if defined(__NetBSD__) && defined(__arm__)
+typedef int32_t AtomicWord;
+#else
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
 typedef intptr_t AtomicWord;
+#endif
 
 // Atomically execute:
 //      result = *ptr;
