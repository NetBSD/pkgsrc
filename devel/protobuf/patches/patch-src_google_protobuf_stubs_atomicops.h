$NetBSD: patch-src_google_protobuf_stubs_atomicops.h,v 1.1 2015/02/19 14:12:33 joerg Exp $

--- src/google/protobuf/stubs/atomicops.h.orig	2015-02-09 22:44:41.000000000 +0000
+++ src/google/protobuf/stubs/atomicops.h
@@ -77,7 +77,11 @@ typedef intptr_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
+#ifdef __arm__
+typedef Atomic32 AtomicWord;
+#else
 typedef intptr_t AtomicWord;
+#endif
 
 // Atomically execute:
 //      result = *ptr;
