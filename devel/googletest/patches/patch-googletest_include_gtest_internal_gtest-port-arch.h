$NetBSD: patch-googletest_include_gtest_internal_gtest-port-arch.h,v 1.1 2017/07/04 20:51:07 kamil Exp $

--- googletest/include/gtest/internal/gtest-port-arch.h.orig	2016-07-14 17:15:38.000000000 +0000
+++ googletest/include/gtest/internal/gtest-port-arch.h
@@ -84,6 +84,8 @@
 # define GTEST_OS_HPUX 1
 #elif defined __native_client__
 # define GTEST_OS_NACL 1
+#elif defined __NetBSD__
+# define GTEST_OS_NETBSD 1
 #elif defined __OpenBSD__
 # define GTEST_OS_OPENBSD 1
 #elif defined __QNX__
