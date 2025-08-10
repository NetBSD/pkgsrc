$NetBSD: patch-src_fcftint.h,v 1.2 2025/08/10 13:58:35 ryoon Exp $

--- src/fcftint.h.orig	2025-07-02 04:46:34.000000000 +0000
+++ src/fcftint.h
@@ -25,7 +25,13 @@
 
 #include <fontconfig/fcfreetype.h>
 
-#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3)) && defined(__ELF__) && !defined(__sun)
+/* Bug of GCC 4.2 (visibility and -fPIC)
+   http://gcc.gnu.org/bugzilla/show_bug.cgi?id=46861 */
+#if (__GNUC__ == 4 && __GNUC_MINOR__ == 2) && defined(__ELF__) && !defined(__sun)
+#define FcPrivate
+#define HAVE_GNUC_ATTRIBUTE 1
+#include "fcftalias.h"
+#elif (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3)) && defined(__ELF__) && !defined(__sun)
 #  define FcPrivate           __attribute__ ((__visibility__ ("hidden")))
 #  define HAVE_GNUC_ATTRIBUTE 1
 #  include "fcftalias.h"
