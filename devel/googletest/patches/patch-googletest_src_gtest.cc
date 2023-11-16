$NetBSD: patch-googletest_src_gtest.cc,v 1.1 2023/11/16 10:11:18 nia Exp $

Missing include for raise(3), needed on NetBSD/aarch64.

--- googletest/src/gtest.cc.orig	2023-08-02 15:24:53.000000000 +0000
+++ googletest/src/gtest.cc
@@ -114,6 +114,7 @@
 // silence it.
 #include <sys/time.h>  // NOLINT
 #include <unistd.h>    // NOLINT
+#include <signal.h>    // NOLINT
 
 #endif  // GTEST_OS_LINUX
 
