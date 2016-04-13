$NetBSD: patch-src_lisp.h,v 1.5 2016/04/13 13:52:27 hauke Exp $

Don't try to define max_align_t in C11 or C++11 mode.

--- src/lisp.h.orig	2015-01-29 15:04:29.000000000 +0000
+++ src/lisp.h
@@ -195,6 +195,7 @@ void xfree (void *);
 
 /* No type has a greater alignment requirement than max_align_t.
    (except perhaps for types we don't use, like long double) */
+#if (__STDC_VERSION__ - 0) < 201112L && (__cplusplus - 0) < 201103L
 typedef union
 {
   struct { long l; } l;
@@ -202,6 +203,7 @@ typedef union
   struct { void (*f)(void); } f;
   struct { double d; } d;
 } max_align_t;
+#endif
 
 #ifndef ALIGNOF
 # if defined (__GNUC__) && (__GNUC__ >= 2)
