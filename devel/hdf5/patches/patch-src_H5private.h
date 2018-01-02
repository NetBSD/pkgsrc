$NetBSD: patch-src_H5private.h,v 1.1 2018/01/02 09:58:47 jperkin Exp $

Avoid existing ERR definition.

--- src/H5private.h.orig	2017-04-25 21:45:02.000000000 +0000
+++ src/H5private.h
@@ -336,6 +336,10 @@
 #define FAIL    (-1)
 #define UFAIL    (unsigned)(-1)
 
+#ifdef ERR
+#undef ERR
+#endif
+
 /* number of members in an array */
 #ifndef NELMTS
 #    define NELMTS(X)    (sizeof(X)/sizeof(X[0]))
