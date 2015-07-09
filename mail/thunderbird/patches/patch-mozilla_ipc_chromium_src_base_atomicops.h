$NetBSD: patch-mozilla_ipc_chromium_src_base_atomicops.h,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/ipc/chromium/src/base/atomicops.h.orig	2015-06-08 17:49:21.000000000 +0000
+++ mozilla/ipc/chromium/src/base/atomicops.h
@@ -45,7 +45,7 @@ typedef int64_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
-#ifdef OS_OPENBSD
+#if defined(OS_OPENBSD) || (defined(OS_NETBSD) && defined(ARCH_CPU_ARM_FAMILY))
 #ifdef ARCH_CPU_64_BITS
 typedef Atomic64 AtomicWord;
 #else
