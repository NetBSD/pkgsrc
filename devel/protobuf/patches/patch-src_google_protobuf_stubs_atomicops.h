$NetBSD: patch-src_google_protobuf_stubs_atomicops.h,v 1.5 2016/10/04 23:16:44 maya Exp $

NetBSD arm and mips uses long for intptr_t, which fails -fpermissive checks.
So explicitly use int32 here instead.

--- src/google/protobuf/stubs/atomicops.h.orig	2016-04-28 21:34:30.000000000 +0000
+++ src/google/protobuf/stubs/atomicops.h
@@ -89,7 +89,11 @@ typedef intptr_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
+#ifdef _LP64
 typedef intptr_t AtomicWord;
+#else
+typedef Atomic32 AtomicWord;
+#endif
 
 // Atomically execute:
 //      result = *ptr;
