$NetBSD: patch-test_ccmdexit-test.m,v 1.1 2015/12/26 23:35:46 dholland Exp $

Use standard headers.

--- test/ccmdexit-test.m~	2002-08-04 12:17:00.000000000 +0000
+++ test/ccmdexit-test.m
@@ -8,4 +8,5 @@
  */
 
+#include <stdio.h>
 #include <coconut/ccmdexit.h>
 #include <coconut/cint.h>
