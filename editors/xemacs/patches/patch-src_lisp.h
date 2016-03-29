$NetBSD: patch-src_lisp.h,v 1.4 2016/03/29 19:32:53 hauke Exp $

Don't try to define max_align_t in C11 or C++11 mode.

Fix CVE-2009-2688, via <https://bugzilla.redhat.com/show_bug.cgi?id=511994>

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
@@ -265,6 +267,8 @@ void assert_failed (const char *, int, c
 /*#define REGISTER register*/
 /*#endif*/
 
+/* Mitigating CVE-2009-2688, see glyphs-eimage.c */
+#define UINT_64_BIT uint64_t
 
 /* EMACS_INT is the underlying integral type into which a Lisp_Object must fit.
    In particular, it must be large enough to contain a pointer.
