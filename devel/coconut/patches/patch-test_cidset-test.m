$NetBSD: patch-test_cidset-test.m,v 1.1 2015/12/26 23:35:46 dholland Exp $

Use standard headers.

--- test/cidset-test.m~	2002-08-01 14:45:19.000000000 +0000
+++ test/cidset-test.m
@@ -8,4 +8,5 @@
  */
 
+#include <stdio.h>
 #include <coconut/cidset.h>
 #include <coconut/cindtstream.h>
