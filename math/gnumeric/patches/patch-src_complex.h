$NetBSD: patch-src_complex.h,v 1.1 2012/11/23 12:09:58 joerg Exp $

--- src/complex.h.orig	2012-11-19 17:27:32.000000000 +0000
+++ src/complex.h
@@ -22,7 +22,7 @@ typedef struct {
 #ifdef __GNUC__
 
 /* Have gcc -- inline functions.  */
-#define GNUMERIC_COMPLEX_PROTO(p) p; extern __inline__ p
+#define GNUMERIC_COMPLEX_PROTO(p) p; extern __attribute__((__gnu_inline__)) __inline__ p
 #define GNUMERIC_COMPLEX_BODY
 
 #else
