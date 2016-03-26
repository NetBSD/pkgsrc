$NetBSD: patch-src_lisp.h,v 1.1 2016/03/26 23:26:14 joerg Exp $

--- src/lisp.h.orig	2016-03-26 13:47:05.129185443 +0000
+++ src/lisp.h
@@ -957,6 +957,7 @@ typedef int Boolint;
 
 /* No type has a greater alignment requirement than max_align_t.
    (except perhaps for types we don't use, like long double) */
+#if (__STDC_VERSION__ - 0) < 201112L && (__cplusplus - 0) < 201103L
 typedef union
 {
   struct { long l; } l;
@@ -964,6 +965,7 @@ typedef union
   struct { void (*f)(void); } f;
   struct { double d; } d;
 } max_align_t;
+#endif
 
 /* ALIGNOF returns the required alignment of a type -- i.e. a value such
    that data of this type must begin at a memory address which is a
