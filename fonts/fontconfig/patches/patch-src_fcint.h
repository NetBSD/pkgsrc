$NetBSD: patch-src_fcint.h,v 1.1 2014/07/15 14:48:34 ryoon Exp $

--- src/fcint.h.orig	2014-01-20 08:14:20.000000000 +0000
+++ src/fcint.h
@@ -68,6 +68,17 @@ extern pfnSHGetFolderPathA pSHGetFolderP
 #  define FC_DIR_SEPARATOR_S       "/"
 #endif
 
+/*
+ * SCO OpenServer 5.0.7/3.2 has no MAXPATHLEN, but it has PATH_MAX (256).
+ * in limits.h. PATH_MAX is defined alternatively under non-OpenServer OS,
+ * and it is used in dirname.c of bmake.
+ */
+#if !defined(PATH_MAX)
+#if defined(_SCO_DS)
+#define PATH_MAX	1024
+#endif
+#endif
+
 #if __GNUC__ >= 4
 #define FC_UNUSED	__attribute__((unused))
 #else
@@ -95,7 +106,13 @@ extern pfnSHGetFolderPathA pSHGetFolderP
 #define FC_ABS(a)   ((a) < 0 ? -(a) : (a))
 
 /* slim_internal.h */
-#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3)) && defined(__ELF__) && !defined(__sun)
+/* Bug of GCC 4.2 (visibility and -fPIC)
+   http://gcc.gnu.org/bugzilla/show_bug.cgi?id=46861 */
+#if (__GNUC__ == 4 && __GNUC_MINOR__ == 2) && defined(__ELF__) && !defined(__sun)
+#define FcPrivate
+#define HAVE_GNUC_ATTRIBUTE 1
+#include "fcalias.h"
+#elif (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3)) && defined(__ELF__) && !defined(__sun) && !(__GNUC__ == 4 && __GNUC_MINOR__ == 2)
 #define FcPrivate		__attribute__((__visibility__("hidden")))
 #define HAVE_GNUC_ATTRIBUTE 1
 #include "fcalias.h"
