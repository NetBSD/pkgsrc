$NetBSD: patch-src___imsg__compat.h,v 1.3 2025/07/27 14:37:38 vins Exp $

* Define PATH_MAX on NetBSD.
* Do not warn about unused parameters.

--- src/_imsg_compat.h.orig	2024-09-04 22:07:27.000000000 +0000
+++ src/_imsg_compat.h
@@ -27,13 +27,21 @@
 #include <string.h>
 #include <unistd.h>
 
-#ifdef __linux__
+#if defined(__linux__)
 # include <linux/limits.h>
+#elif defined(__NetBSD__)
+# include <sys/syslimits.h>
+#endif
+
+#ifdef __GNUC__
+#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
+#else
+#  define UNUSED(x) UNUSED_ ## x
 #endif
 
 #ifndef HAVE_EXPLICIT_BZERO
 static void
-__explicit_bzero_hook(void *buf, size_t len)
+__explicit_bzero_hook(void *UNUSED(buf), size_t UNUSED(len))
 {
 }
 
