$NetBSD: patch-contrib_googletest_googletest_src_gtest.cc,v 1.1 2024/12/22 11:24:23 nia Exp $

Include <signal.h> for raise().

--- contrib/googletest/googletest/src/gtest.cc.orig	2024-12-22 11:22:09.419145646 +0000
+++ contrib/googletest/googletest/src/gtest.cc
@@ -76,6 +76,7 @@
 #include <sys/mman.h>  // NOLINT
 #include <sys/time.h>  // NOLINT
 #include <unistd.h>    // NOLINT
+#include <signal.h>    // NOLINT
 
 #include <string>
 
