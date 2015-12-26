$NetBSD: patch-test_cnode-test.m,v 1.1 2015/12/26 23:35:46 dholland Exp $

Use standard headers.

--- test/cnode-test.m~	2002-08-06 15:14:58.000000000 +0000
+++ test/cnode-test.m
@@ -8,4 +8,5 @@
  */
 
+#include <stdio.h>
 #include <coconut/cnode.h>
 #include <coconut/cstring.h>
