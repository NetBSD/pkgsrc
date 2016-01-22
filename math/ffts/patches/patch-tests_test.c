$NetBSD: patch-tests_test.c,v 1.1 2016/01/22 14:57:41 gson Exp $

NetBSD lacks sinl(), cosl(), and sqrtl().

--- tests/test.c.orig	2014-01-05 22:32:16.000000000 +0000
+++ tests/test.c
@@ -44,7 +44,7 @@
 #define PI 3.1415926535897932384626433832795028841971693993751058209
 
 float impulse_error(int N, int sign, float *data) {
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 	double delta_sum = 0.0f;
 	double sum = 0.0f;
 #else
@@ -54,7 +54,7 @@ float impulse_error(int N, int sign, flo
 
 	int i;
 	for(i=0;i<N;i++) {
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 		double re, im;
 		if(sign < 0) {
 			re = cos(2 * PI * (double)i / (double)N); 
@@ -81,7 +81,7 @@ float impulse_error(int N, int sign, flo
 		delta_sum += re * re + im * im;
 
 	}
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 	return sqrt(delta_sum) / sqrt(sum);
 #else
 	return sqrtl(delta_sum) / sqrtl(sum);
