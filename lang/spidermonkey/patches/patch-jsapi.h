$NetBSD: patch-jsapi.h,v 1.1 2015/09/08 18:53:46 joerg Exp $

Multiplication is safe, even if the input is negative. Left shift is not.

--- jsapi.h.orig	2015-09-03 12:07:45.000000000 +0000
+++ jsapi.h
@@ -103,7 +103,7 @@ JS_BEGIN_EXTERN_C
 #define JSVAL_INT_MAX           (JSVAL_INT_POW2(30) - 1)
 #define INT_FITS_IN_JSVAL(i)    ((jsuint)((i)+JSVAL_INT_MAX) <= 2*JSVAL_INT_MAX)
 #define JSVAL_TO_INT(v)         ((jsint)(v) >> 1)
-#define INT_TO_JSVAL(i)         (((jsval)(i) << 1) | JSVAL_INT)
+#define INT_TO_JSVAL(i)         (((jsval)(i) * 2) | JSVAL_INT)
 
 /* Convert between boolean and jsval. */
 #define JSVAL_TO_BOOLEAN(v)     ((JSBool)((v) >> JSVAL_TAGBITS))
