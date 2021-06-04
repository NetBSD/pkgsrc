$NetBSD: patch-lib_isc_include_isc_util.h,v 1.1 2021/06/04 21:56:50 otis Exp $

Fix build on SmartOS where priorities are not
supported with gcc 7.5

--- lib/isc/include/isc/util.h.orig	2021-05-12 09:53:16.000000000 +0000
+++ lib/isc/include/isc/util.h
@@ -48,9 +48,12 @@
 #define ISC_NONSTRING
 #endif /* __GNUC__ */
 
-#if HAVE_FUNC_ATTRIBUTE_CONSTRUCTOR && HAVE_FUNC_ATTRIBUTE_DESTRUCTOR
+#if HAVE_FUNC_ATTRIBUTE_CONSTRUCTOR && HAVE_FUNC_ATTRIBUTE_DESTRUCTOR && !defined(__sun)
 #define ISC_CONSTRUCTOR(priority) __attribute__((constructor(priority)))
 #define ISC_DESTRUCTOR(priority)  __attribute__((destructor(priority)))
+#elif defined(__sun)
+#define ISC_CONSTRUCTOR(priority) __attribute__((constructor))
+#define ISC_DESTRUCTOR(priority)  __attribute__((destructor))
 #elif WIN32
 #define ISC_CONSTRUCTOR(priority)
 #define ISC_DESTRUCTOR(priority)
