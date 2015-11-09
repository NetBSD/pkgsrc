$NetBSD: patch-deps_v8_src_base_atomicops__internals__arm__gcc.h,v 1.1 2015/11/09 20:21:51 fhajny Exp $

--- deps/v8/src/base/atomicops_internals_arm_gcc.h.orig	2015-10-13 17:20:07.000000000 +0000
+++ deps/v8/src/base/atomicops_internals_arm_gcc.h
@@ -13,6 +13,11 @@
 #include <sys/cpuinline.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/sysarch.h>
+#endif
+
 namespace v8 {
 namespace base {
 
@@ -50,6 +55,8 @@ inline void MemoryBarrier() {
   ((KernelMemoryBarrierFunc)0xffff0fa0)();
 #elif defined(__QNXNTO__)
   __cpu_membarrier();
+#elif defined(__NetBSD__)
+  sysarch(ARM_DRAIN_WRITEBUF, (void *)0);
 #else
 #error MemoryBarrier() is not implemented on this platform.
 #endif
