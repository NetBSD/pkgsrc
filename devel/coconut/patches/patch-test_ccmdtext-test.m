$NetBSD: patch-test_ccmdtext-test.m,v 1.1 2015/12/26 23:35:46 dholland Exp $

Use standard headers.

--- test/ccmdtext-test.m~	2002-08-15 02:23:46.000000000 +0000
+++ test/ccmdtext-test.m
@@ -8,4 +8,5 @@
  */
 
+#include <stdio.h>
 #include <coconut/ccmdtext.h>
 #include <coconut/cstring.h>
