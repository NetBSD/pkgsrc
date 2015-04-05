$NetBSD: patch-src_mesa_drivers_dri_intel_intel__context.h,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/intel/intel_context.h.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/drivers/dri/intel/intel_context.h
@@ -304,8 +304,12 @@ struct intel_context
    driOptionCache optionCache;
 };
 
+#if defined(__sun)
+#include <stdlib.h>
+#define __progname getexecname()
+#else
 extern char *__progname;
-
+#endif
 
 #define SUBPIXEL_X 0.125
 #define SUBPIXEL_Y 0.125
@@ -364,7 +368,7 @@ do {						\
  * than COPY_DWORDS would:
  * XXX Put this in src/mesa/main/imports.h ???
  */
-#if defined(i386) || defined(__i386__)
+#if (defined(i386) || defined(__i386__)) && !(defined(__SOLARIS__) || defined(sun))
 static INLINE void * __memcpy(void * to, const void * from, size_t n)
 {
    int d0, d1, d2;
