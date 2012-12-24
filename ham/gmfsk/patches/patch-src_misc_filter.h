$NetBSD: patch-src_misc_filter.h,v 1.1 2012/12/24 21:13:28 joerg Exp $

--- src/misc/filter.h.orig	2012-12-23 17:57:04.000000000 +0000
+++ src/misc/filter.h
@@ -39,7 +39,7 @@
 
 
 #ifndef __HAVE_ARCH_MAC
-extern __inline__ float mac(const float *a, const float *b, unsigned int size)
+__attribute__((gnu_inline)) extern __inline__ float mac(const float *a, const float *b, unsigned int size)
 {
 	float sum = 0;
 	unsigned int i;
