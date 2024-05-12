$NetBSD: patch-cbits_cycles.c,v 1.2 2024/05/12 05:48:30 pho Exp $

Add support for non-Darwin, non-Linux, aarch64 platforms.

https://github.com/haskell/criterion/pull/282

--- cbits/cycles.c.orig	2024-05-02 05:12:32.848662895 +0000
+++ cbits/cycles.c
@@ -9,6 +9,15 @@ StgWord64 criterion_rdtsc(void)
   return mach_absolute_time();
 }
 
+#elif aarch64_HOST_ARCH
+
+StgWord64 criterion_rdtsc(void)
+{
+  StgWord64 ret;
+  __asm__ __volatile__ ("mrs %0, cntvct_el0" : "=r"(ret));
+  return ret;
+}
+
 #elif x86_64_HOST_ARCH || i386_HOST_ARCH
 
 StgWord64 criterion_rdtsc(void)
