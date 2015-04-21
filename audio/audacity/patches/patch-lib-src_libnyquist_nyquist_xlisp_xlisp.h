$NetBSD: patch-lib-src_libnyquist_nyquist_xlisp_xlisp.h,v 1.1 2015/04/21 01:33:39 rodent Exp $

Define endianness for {Free,Open,Net}BSD and Bitrig.

--- lib-src/libnyquist/nyquist/xlisp/xlisp.h.orig	2015-03-02 01:07:22.000000000 +0000
+++ lib-src/libnyquist/nyquist/xlisp/xlisp.h
@@ -166,6 +166,20 @@ extern long ptrtoabs();
 #else
 #define XL_BIG_ENDIAN
 #endif
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
+ #include <sys/endian.h>
+ #if _BYTE_ORDER == _LITTLE_ENDIAN
+  #define XL_LITTLE_ENDIAN
+ #else
+  #define XL_BIG_ENDIAN
+ #endif
+#elif defined(__OpenBSD__) || defined(__Bitrig__)
+ #include <endian.h>
+ #if BYTE_ORDER == _LITTLE_ENDIAN
+  #define XL_LITTLE_ENDIAN
+ #else
+  #define XL_BIG_ENDIAN
+ #endif
 #endif
 
 /* Apple CC */
