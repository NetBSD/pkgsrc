$NetBSD: patch-src_misc_filter-i386.h,v 1.1 2012/12/24 21:13:28 joerg Exp $

--- src/misc/filter-i386.h.orig	2012-12-23 17:57:26.000000000 +0000
+++ src/misc/filter-i386.h
@@ -32,7 +32,7 @@
 
 #include <stdio.h>
 
-extern inline float __mac_g(const float *a, const float *b, unsigned int size)
+__attribute__((gnu_inline)) extern inline float __mac_g(const float *a, const float *b, unsigned int size)
 {
 	float sum = 0;
 	unsigned int i;
@@ -42,7 +42,7 @@ extern inline float __mac_g(const float 
 	return sum;
 }
 
-extern inline float __mac_c(const float *a, const float *b, unsigned int size)
+__attribute__((gnu_inline)) extern inline float __mac_c(const float *a, const float *b, unsigned int size)
 {
 	float f;
 
