$NetBSD: patch-mozilla_ipc_chromium_src_base_atomicops.h,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/ipc/chromium/src/base/atomicops.h.orig	2016-04-07 21:33:19.000000000 +0000
+++ mozilla/ipc/chromium/src/base/atomicops.h
@@ -45,7 +45,7 @@ typedef int64_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
-#ifdef OS_OPENBSD
+#if defined(OS_OPENBSD) || (defined(OS_NETBSD) && defined(ARCH_CPU_ARM_FAMILY))
 #ifdef ARCH_CPU_64_BITS
 typedef Atomic64 AtomicWord;
 #else
