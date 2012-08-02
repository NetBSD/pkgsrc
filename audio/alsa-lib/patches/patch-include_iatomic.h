$NetBSD: patch-include_iatomic.h,v 1.1 2012/08/02 12:52:33 jperkin Exp $

Use __asm__ and __volatile__

--- include/iatomic.h.orig	Thu Aug  2 12:47:59 2012
+++ include/iatomic.h	Thu Aug  2 12:49:53 2012
@@ -211,9 +211,9 @@
 #define rmb()	mb()
 #define wmb()	__asm__ __volatile__ ("": : :"memory")
 #else
-#define mb() 	asm volatile("mfence":::"memory")
-#define rmb()	asm volatile("lfence":::"memory")
-#define wmb()	asm volatile("sfence":::"memory")
+#define mb() 	__asm__ __volatile__ ("mfence":::"memory")
+#define rmb()	__asm__ __volatile__ ("lfence":::"memory")
+#define wmb()	__asm__ __volatile__ ("sfence":::"memory")
 #endif
 
 #undef ATOMIC_SMP_LOCK
