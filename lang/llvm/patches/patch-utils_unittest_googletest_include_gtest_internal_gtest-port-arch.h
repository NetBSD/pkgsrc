$NetBSD: patch-utils_unittest_googletest_include_gtest_internal_gtest-port-arch.h,v 1.1 2017/05/05 18:12:24 joerg Exp $

SVN r302264

--- utils/unittest/googletest/include/gtest/internal/gtest-port-arch.h.orig	2017-05-04 15:28:58.046689762 +0000
+++ utils/unittest/googletest/include/gtest/internal/gtest-port-arch.h
@@ -84,6 +84,8 @@
 # define GTEST_OS_HPUX 1
 #elif defined __native_client__
 # define GTEST_OS_NACL 1
+#elif defined __NetBSD__
+# define GTEST_OS_NETBSD 1
 #elif defined __OpenBSD__
 # define GTEST_OS_OPENBSD 1
 #elif defined __QNX__
