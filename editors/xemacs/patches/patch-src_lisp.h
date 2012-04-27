$NetBSD: patch-src_lisp.h,v 1.1 2012/04/27 13:53:46 hauke Exp $

Fix CVE-2009-2688, via <https://bugzilla.redhat.com/show_bug.cgi?id=511994>

--- src/lisp.h.orig	2005-02-01 03:55:02.000000000 +0000
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
