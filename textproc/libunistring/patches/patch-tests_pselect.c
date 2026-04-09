$NetBSD: patch-tests_pselect.c,v 1.2 2026/04/09 05:59:30 wiz Exp $

Fix compiling on QNX.
https://savannah.gnu.org/bugs/index.php?68222

--- tests/pselect.c.orig	2024-01-29 00:58:12.000000000 +0000
+++ tests/pselect.c
@@ -21,6 +21,7 @@
 
 #include <config.h>
 
+#include <time.h>
 #include <sys/select.h>
 
 #include <errno.h>
