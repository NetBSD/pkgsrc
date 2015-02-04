$NetBSD: patch-src_lisp.h,v 1.2 2015/02/04 09:19:20 hauke Exp $

--- src/lisp.h.orig	2015-01-29 15:04:29.000000000 +0000
+++ src/lisp.h
@@ -265,6 +265,11 @@ void assert_failed (const char *, int, c
 /*#define REGISTER register*/
 /*#endif*/
 
+#if SIZEOF_LONG == 8
+#define UINT_64_BIT unsigned long
+#elif SIZEOF_LONG_LONG == 8
+#define UINT_64_BIT unsigned long long
+#endif
 
 /* EMACS_INT is the underlying integral type into which a Lisp_Object must fit.
    In particular, it must be large enough to contain a pointer.
