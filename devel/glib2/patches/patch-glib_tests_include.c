$NetBSD: patch-glib_tests_include.c,v 1.3 2019/11/26 10:27:09 jperkin Exp $

Fix SunOS build.

--- glib/tests/include.c.orig	2019-10-21 17:18:40.000000000 +0000
+++ glib/tests/include.c
@@ -1,8 +1,10 @@
 /* Test case for bug 659866 */
 
+#ifndef __sun
 #define _POSIX_C_SOURCE 199309L
 #undef _GNU_SOURCE
 #undef _XOPEN_SOURCE
+#endif
 #include <pthread.h>
 #include <glib.h>
 
