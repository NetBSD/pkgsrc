$NetBSD: patch-include_u.h,v 1.1 2017/10/19 14:29:01 jperkin Exp $

Don't set broken _XOPEN_SOURCE on SunOS.

--- include/u.h.orig	2015-09-23 04:37:36.000000000 +0000
+++ include/u.h
@@ -42,7 +42,7 @@ extern "C" {
 #define _NETBSD_SOURCE 1	/* NetBSD */
 #define _DEFAULT_SOURCE 1	/* glibc > 2.19 */
 #define _SVID_SOURCE 1
-#if !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__sun)
 #	define _XOPEN_SOURCE 1000
 #	define _XOPEN_SOURCE_EXTENDED 1
 #endif
