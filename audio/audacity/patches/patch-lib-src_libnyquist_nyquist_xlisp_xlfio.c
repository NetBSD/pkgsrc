$NetBSD: patch-lib-src_libnyquist_nyquist_xlisp_xlfio.c,v 1.1 2015/04/21 01:33:39 rodent Exp $

Fix #error directive.

--- lib-src/libnyquist/nyquist/xlisp/xlfio.c.orig	2015-03-02 01:07:22.000000000 +0000
+++ lib-src/libnyquist/nyquist/xlisp/xlfio.c
@@ -19,8 +19,7 @@
 /* do some sanity checking: */
 #ifndef XL_BIG_ENDIAN
 #ifndef XL_LITTLE_ENDIAN
-configuration error -- either XL_BIG_ or XL_LITTLE_ENDIAN must be defined
-in xlisp.h
+#error configuration error -- either XL_BIG_ or XL_LITTLE_ENDIAN must be defined in xlisp.h
 #endif
 #endif
 #ifdef XL_BIG_ENDIAN
