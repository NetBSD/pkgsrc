$NetBSD: patch-test_ccmdprint-test.m,v 1.1 2015/12/26 23:35:46 dholland Exp $

Use standard headers.

--- test/ccmdprint-test.m~	2002-08-15 02:06:18.000000000 +0000
+++ test/ccmdprint-test.m
@@ -8,4 +8,5 @@
  */
 
+#include <stdio.h>
 #include <coconut/ccmdprint.h>
 #include <coconut/ccmdtext.h>
