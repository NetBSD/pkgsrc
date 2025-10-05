$NetBSD: patch-gnulib-tests_pselect.c,v 1.1 2025/10/05 11:59:43 js Exp $

--- gnulib-tests/pselect.c.orig	2022-07-02 18:22:03.000000000 +0000
+++ gnulib-tests/pselect.c
@@ -21,6 +21,7 @@
 
 #include <config.h>
 
+#include <time.h>
 #include <sys/select.h>
 
 #include <errno.h>
