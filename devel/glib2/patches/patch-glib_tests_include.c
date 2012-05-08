$NetBSD: patch-glib_tests_include.c,v 1.1 2012/05/08 16:07:23 hans Exp $

SunOS requires _XOPEN_SOURCE etc. to be set correctly when compiling C99.

--- glib/tests/include.c.orig	2012-04-13 01:39:20.000000000 +0200
+++ glib/tests/include.c	2012-05-08 15:05:36.027464330 +0200
@@ -1,8 +1,10 @@
 /* Test case for bug 659866 */
 
+#ifndef __sun
 #define _POSIX_C_SOURCE 199309L
 #undef _GNU_SOURCE
 #undef _XOPEN_SOURCE
+#endif
 #include <pthread.h>
 #include <glib.h>
 
