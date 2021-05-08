$NetBSD: patch-include_my__global.h,v 1.1 2021/05/08 19:47:16 jdolecek Exp $

NetBSD guards C99 printf format macros, needs to be triggered
here for early includes.

--- include/my_global.h.orig	2015-02-25 15:40:54.000000000 +0000
+++ include/my_global.h
@@ -50,6 +50,12 @@
 #define _POSIX_THREAD_CPUTIME
 #endif /* __CYGWIN__ */
 
+/* NetBSD guards C99 printf format macros, needs to be triggered
+   here for early includes */
+#if defined(__NetBSD__)
+#define __STDC_FORMAT_MACROS
+#endif
+
 #if defined(__OpenBSD__) && (OpenBSD >= 200411)
 #define HAVE_ERRNO_AS_DEFINE
 #endif
