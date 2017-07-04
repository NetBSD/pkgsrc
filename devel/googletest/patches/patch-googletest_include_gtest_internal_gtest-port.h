$NetBSD: patch-googletest_include_gtest_internal_gtest-port.h,v 1.1 2017/07/04 20:51:07 kamil Exp $

--- googletest/include/gtest/internal/gtest-port.h.orig	2016-07-14 17:15:38.000000000 +0000
+++ googletest/include/gtest/internal/gtest-port.h
@@ -128,6 +128,7 @@
 //   GTEST_OS_MAC      - Mac OS X
 //     GTEST_OS_IOS    - iOS
 //   GTEST_OS_NACL     - Google Native Client (NaCl)
+//   GTEST_OS_NETBSD   - NetBSD
 //   GTEST_OS_OPENBSD  - OpenBSD
 //   GTEST_OS_QNX      - QNX
 //   GTEST_OS_SOLARIS  - Sun Solaris
@@ -601,7 +602,7 @@ struct _RTL_CRITICAL_SECTION;
 // To disable threading support in Google Test, add -DGTEST_HAS_PTHREAD=0
 // to your compiler flags.
 # define GTEST_HAS_PTHREAD (GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_HPUX \
-    || GTEST_OS_QNX || GTEST_OS_FREEBSD || GTEST_OS_NACL)
+    || GTEST_OS_QNX || GTEST_OS_FREEBSD || GTEST_OS_NACL || GTEST_OS_NETBSD)
 #endif  // GTEST_HAS_PTHREAD
 
 #if GTEST_HAS_PTHREAD
@@ -790,7 +791,8 @@ using ::std::tuple_size;
      (GTEST_OS_MAC && !GTEST_OS_IOS) || \
      (GTEST_OS_WINDOWS_DESKTOP && _MSC_VER >= 1400) || \
      GTEST_OS_WINDOWS_MINGW || GTEST_OS_AIX || GTEST_OS_HPUX || \
-     GTEST_OS_OPENBSD || GTEST_OS_QNX || GTEST_OS_FREEBSD)
+     GTEST_OS_OPENBSD || GTEST_OS_QNX || GTEST_OS_FREEBSD || \
+     GTEST_OS_NETBSD)
 # define GTEST_HAS_DEATH_TEST 1
 #endif
 
