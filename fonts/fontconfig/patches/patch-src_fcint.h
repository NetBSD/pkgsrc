$NetBSD: patch-src_fcint.h,v 1.3 2018/03/11 17:54:03 wiz Exp $

--- src/fcint.h.orig	2018-02-04 10:20:56.000000000 +0000
+++ src/fcint.h
@@ -76,6 +76,17 @@ extern pfnSHGetFolderPathA pSHGetFolderP
 #define FC_PATH_MAX	128
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
@@ -103,7 +114,13 @@ extern pfnSHGetFolderPathA pSHGetFolderP
 #define FC_MAX(a,b) ((a) > (b) ? (a) : (b))
 
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
