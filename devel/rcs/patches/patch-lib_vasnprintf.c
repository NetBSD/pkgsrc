$NetBSD: patch-lib_vasnprintf.c,v 1.1 2018/09/06 09:29:57 jperkin Exp $

Don't use %n on Darwin.

--- lib/vasnprintf.c.orig	2015-01-08 01:12:58.000000000 +0000
+++ lib/vasnprintf.c
@@ -4858,7 +4858,7 @@ VASNPRINTF (DCHAR_T *resultbuf, size_t *
 #endif
                   *fbp = dp->conversion;
 #if USE_SNPRINTF
-# if !(((__GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3)) && !defined __UCLIBC__) || ((defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__))
+# if !defined(__APPLE__) && !(((__GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3)) && !defined __UCLIBC__) || ((defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__))
                 fbp[1] = '%';
                 fbp[2] = 'n';
                 fbp[3] = '\0';
