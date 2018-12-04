$NetBSD: patch-include_fmt_posix.h,v 1.1 2018/12/04 10:05:22 jperkin Exp $

Avoid strtod_l on SunOS.

--- include/fmt/posix.h.orig	2018-09-21 17:18:51.000000000 +0000
+++ include/fmt/posix.h
@@ -267,7 +267,7 @@ long getpagesize();
 
 #if (defined(LC_NUMERIC_MASK) || defined(_MSC_VER)) && \
     !defined(__ANDROID__) && !defined(__CYGWIN__) && !defined(__OpenBSD__) && \
-    !defined(__NEWLIB_H__)
+    !defined(__NEWLIB_H__) && !defined(__sun)
 # define FMT_LOCALE
 #endif
 
