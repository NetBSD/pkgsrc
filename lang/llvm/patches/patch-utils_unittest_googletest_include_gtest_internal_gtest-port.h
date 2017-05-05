$NetBSD: patch-utils_unittest_googletest_include_gtest_internal_gtest-port.h,v 1.1 2017/05/05 18:12:24 joerg Exp $

SVN r302264

--- utils/unittest/googletest/include/gtest/internal/gtest-port.h.orig	2017-05-04 15:26:03.505703113 +0000
+++ utils/unittest/googletest/include/gtest/internal/gtest-port.h
@@ -793,7 +793,7 @@ using ::std::tuple_size;
      (GTEST_OS_MAC && !GTEST_OS_IOS) || \
      (GTEST_OS_WINDOWS_DESKTOP && _MSC_VER >= 1400) || \
      GTEST_OS_WINDOWS_MINGW || GTEST_OS_AIX || GTEST_OS_HPUX || \
-     GTEST_OS_OPENBSD || GTEST_OS_QNX || GTEST_OS_FREEBSD)
+     GTEST_OS_OPENBSD || GTEST_OS_QNX || GTEST_OS_FREEBSD || GTEST_OS_NETBSD)
 # define GTEST_HAS_DEATH_TEST 1
 #endif
 
