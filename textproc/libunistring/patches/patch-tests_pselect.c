$NetBSD: patch-tests_pselect.c,v 1.1 2025/10/05 14:51:09 js Exp $

Fix compiling on QNX.

--- tests/pselect.c.orig	2024-01-29 00:58:12.000000000 +0000
+++ tests/pselect.c
@@ -21,6 +21,7 @@
 
 #include <config.h>
 
+#include <time.h>
 #include <sys/select.h>
 
 #include <errno.h>
