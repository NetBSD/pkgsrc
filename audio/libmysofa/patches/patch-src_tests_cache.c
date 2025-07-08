$NetBSD: patch-src_tests_cache.c,v 1.1 2025/07/08 13:04:21 jperkin Exp $

Include strings.h for bzero().

--- src/tests/cache.c.orig	2025-07-08 13:02:49.377679083 +0000
+++ src/tests/cache.c
@@ -6,6 +6,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <string.h>
+#include <strings.h>
 
 void test_cache() {
   char *filename1 = "build/sofacoustics.org/data/sofa_api_mo_test/Pulse.sofa";
