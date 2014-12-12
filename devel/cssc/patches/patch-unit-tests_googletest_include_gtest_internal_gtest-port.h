$NetBSD: patch-unit-tests_googletest_include_gtest_internal_gtest-port.h,v 1.4 2014/12/12 08:32:42 mef Exp $

--- unit-tests/googletest/include/gtest/internal/gtest-port.h.orig	2014-07-01 06:33:31.000000000 +0900
+++ unit-tests/googletest/include/gtest/internal/gtest-port.h	2014-12-12 16:46:31.000000000 +0900
@@ -261,6 +261,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 # include <sys/types.h>
 # include <sys/stat.h>
