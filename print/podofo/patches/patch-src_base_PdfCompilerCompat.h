--- src/base/PdfCompilerCompat.h.orig	2011-09-30 13:20:59.000000000 +0200
+++ src/base/PdfCompilerCompat.h	2014-08-26 14:58:16.000000000 +0200
@@ -72,6 +72,9 @@
 #if defined(_WIN32)
 #include <malloc.h>
 #endif
+#ifdef __NetBSD__
+#define	alloca	__builtin_alloca
+#endif
 
 // Disable usage of min() and max() macros 
 #if defined(_WIN32) && !defined(__MINGW32__)
