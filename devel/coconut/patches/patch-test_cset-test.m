$NetBSD: patch-test_cset-test.m,v 1.1 2015/12/26 23:35:46 dholland Exp $

Use standard headers.

--- test/cset-test.m~	2002-06-16 04:46:42.000000000 +0000
+++ test/cset-test.m
@@ -8,4 +8,5 @@
  */
 
+#include <stdio.h>
 #include <coconut/cset.h>
 #include <coconut/cindtstream.h>
