$NetBSD: patch-src_lisp.h,v 1.3 2016/03/26 23:26:14 joerg Exp $

--- src/lisp.h.orig	2016-03-26 15:03:47.482901440 +0000
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
