$NetBSD: patch-test_cdir-test.m,v 1.1 2015/12/26 23:35:46 dholland Exp $

Use standard headers.

--- test/cdir-test.m~	2002-06-20 17:24:29.000000000 +0000
+++ test/cdir-test.m
@@ -8,4 +8,5 @@
  */
 
+#include <stdio.h>
 #include <coconut/cdir.h>
 #include <coconut/cconststr.h>
