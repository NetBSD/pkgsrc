$NetBSD: patch-lib_vasnprintf.c,v 1.1 2020/11/29 22:06:54 dbj Exp $

Fix build on MacOS High Sierra and later
https://lists.gnu.org/archive/html/bug-gnulib/2017-07/msg00057.html

--- lib/vasnprintf.c.orig	2012-01-28 16:26:05.000000000 +0000
+++ lib/vasnprintf.c
@@ -4871,7 +4871,7 @@ VASNPRINTF (DCHAR_T *resultbuf, size_t *
 #endif
                   *fbp = dp->conversion;
 #if USE_SNPRINTF
-# if !(((__GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3)) && !defined __UCLIBC__) || ((defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__))
+# if !(((__GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3)) && !defined __UCLIBC__) || (defined __APPLE__ && defined __MACH__) || ((defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__))
                 fbp[1] = '%';
                 fbp[2] = 'n';
                 fbp[3] = '\0';
