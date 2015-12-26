$NetBSD: patch-test_ctree-test.m,v 1.1 2015/12/26 23:35:46 dholland Exp $

Use standard headers.

--- test/ctree-test.m~	2002-08-01 16:07:12.000000000 +0000
+++ test/ctree-test.m
@@ -8,4 +8,5 @@
  */
 
+#include <stdio.h>
 #include <coconut/ctree.h>
 #include <coconut/cnode.h>
