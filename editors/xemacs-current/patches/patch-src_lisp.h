$NetBSD: patch-src_lisp.h,v 1.2 2017/11/15 15:04:25 hauke Exp $

Don't try to define max_align_t in C11 or C++11 mode.

--- src/lisp.h.orig	2013-08-21 17:43:44.000000000 +0000
+++ src/lisp.h
@@ -1156,6 +1156,7 @@ typedef int Boolint;
 
 /* No type has a greater alignment requirement than max_align_t.
    (except perhaps for types we don't use, like long double) */
+#if (__STDC_VERSION__ - 0) < 201112L && (__cplusplus - 0) < 201103L
 typedef union
 {
   struct { long l; } l;
@@ -1163,6 +1164,7 @@ typedef union
   struct { void (*f)(void); } f;
   struct { double d; } d;
 } max_align_t;
+#endif
 
 /* ALIGNOF returns the required alignment of a type -- i.e. a value such
    that data of this type must begin at a memory address which is a
