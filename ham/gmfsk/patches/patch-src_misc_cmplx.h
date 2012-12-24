$NetBSD: patch-src_misc_cmplx.h,v 1.1 2012/12/24 21:13:28 joerg Exp $

--- src/misc/cmplx.h.orig	2012-12-23 17:55:27.000000000 +0000
+++ src/misc/cmplx.h
@@ -43,7 +43,7 @@ typedef fftw_complex complex;
 /*
  * Complex multiplication.
  */
-extern __inline__ complex cmul(complex x, complex y)
+__attribute__((gnu_inline)) extern __inline__ complex cmul(complex x, complex y)
 {
 	complex z;
 
@@ -56,7 +56,7 @@ extern __inline__ complex cmul(complex x
 /*
  * Complex addition.
  */
-extern __inline__ complex cadd(complex x, complex y)
+__attribute__((gnu_inline)) extern __inline__ complex cadd(complex x, complex y)
 {
 	complex z;
 
@@ -69,7 +69,7 @@ extern __inline__ complex cadd(complex x
 /*
  * Complex subtraction.
  */
-extern __inline__ complex csub(complex x, complex y)
+__attribute__((gnu_inline)) extern __inline__ complex csub(complex x, complex y)
 {
 	complex z;
 
@@ -82,7 +82,7 @@ extern __inline__ complex csub(complex x
 /*
  * Complex multiply-accumulate.
  */
-extern __inline__ complex cmac(complex *a, complex *b, int ptr, int len)
+__attribute__((gnu_inline)) extern __inline__ complex cmac(complex *a, complex *b, int ptr, int len)
 {
 	complex z;
 	int i;
@@ -104,7 +104,7 @@ extern __inline__ complex cmac(complex *
  * Complex ... yeah, what??? Returns a complex number that has the
  * properties: |z| = |x| * |y|  and  arg(z) = arg(y) - arg(x)
  */
-extern __inline__ complex ccor(complex x, complex y)
+__attribute__((gnu_inline)) extern __inline__ complex ccor(complex x, complex y)
 {
 	complex z;
 
@@ -117,7 +117,7 @@ extern __inline__ complex ccor(complex x
 /*
  * Real part of the complex ???
  */
-extern __inline__ double ccorI(complex x, complex y)
+__attribute__((gnu_inline)) extern __inline__ double ccorI(complex x, complex y)
 {
 	return c_re(x) * c_re(y) + c_im(x) * c_im(y);
 }
@@ -125,7 +125,7 @@ extern __inline__ double ccorI(complex x
 /*
  * Imaginary part of the complex ???
  */
-extern __inline__ double ccorQ(complex x, complex y)
+__attribute__((gnu_inline)) extern __inline__ double ccorQ(complex x, complex y)
 {
 	return c_re(x) * c_im(y) - c_im(x) * c_re(y);
 }
@@ -133,7 +133,7 @@ extern __inline__ double ccorQ(complex x
 /*
  * Modulo (absolute value) of a complex number.
  */
-extern __inline__ double cmod(complex x)
+__attribute__((gnu_inline)) extern __inline__ double cmod(complex x)
 {
 	return sqrt(c_re(x) * c_re(x) + c_im(x) * c_im(x));
 }
@@ -141,7 +141,7 @@ extern __inline__ double cmod(complex x)
 /*
  * Square of the absolute value (power).
  */
-extern __inline__ double cpwr(complex x)
+__attribute__((gnu_inline)) extern __inline__ double cpwr(complex x)
 {
 	return (c_re(x) * c_re(x) + c_im(x) * c_im(x));
 }
@@ -149,7 +149,7 @@ extern __inline__ double cpwr(complex x)
 /*
  * Argument of a complex number.
  */
-extern __inline__ double carg(complex x)
+__attribute__((gnu_inline)) extern __inline__ double carg(complex x)
 {
 	return atan2(c_im(x), c_re(x));
 }
@@ -157,7 +157,7 @@ extern __inline__ double carg(complex x)
 /*
  * Complex square root.
  */
-extern __inline__ complex csqrt(complex x)
+__attribute__((gnu_inline)) extern __inline__ complex csqrt(complex x)
 {
 	complex z;
 
