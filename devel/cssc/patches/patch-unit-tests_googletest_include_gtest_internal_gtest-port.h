$NetBSD: patch-unit-tests_googletest_include_gtest_internal_gtest-port.h,v 1.2 2012/11/24 08:43:18 marino Exp $

--- unit-tests/googletest/include/gtest/internal/gtest-port.h.orig	2010-05-15 22:30:14.000000000 +0000
+++ unit-tests/googletest/include/gtest/internal/gtest-port.h
@@ -173,6 +173,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
 #endif  // !_WIN32_WCE
