$NetBSD: patch-include_iatomic.h,v 1.2 2016/02/18 15:15:57 wiz Exp $

Use __asm__ and __volatile__

--- include/iatomic.h.orig	2015-11-09 07:39:18.000000000 +0000
+++ include/iatomic.h
@@ -9,9 +9,9 @@
 #endif 
 
 #ifdef __x86_64__
-#define mb() 	asm volatile("mfence":::"memory")
-#define rmb()	asm volatile("lfence":::"memory")
-#define wmb()	asm volatile("sfence":::"memory")
+#define mb() 	__asm__ __volatile__ ("mfence":::"memory")
+#define rmb()	__asm__ __volatile__ ("lfence":::"memory")
+#define wmb()	__asm__ __volatile__ ("sfence":::"memory")
 #define IATOMIC_DEFINED		1
 #endif
 
