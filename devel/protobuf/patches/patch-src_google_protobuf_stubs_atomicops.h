$NetBSD: patch-src_google_protobuf_stubs_atomicops.h,v 1.2 2015/06/10 01:31:51 wiedi Exp $

--- src/google/protobuf/stubs/atomicops.h.orig	2014-10-21 00:01:40.000000000 +0000
+++ src/google/protobuf/stubs/atomicops.h
@@ -78,7 +78,11 @@ typedef intptr_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
+#ifdef __arm__
+typedef Atomic32 AtomicWord;
+#else
 typedef intptr_t AtomicWord;
+#endif
 
 // Atomically execute:
 //      result = *ptr;
