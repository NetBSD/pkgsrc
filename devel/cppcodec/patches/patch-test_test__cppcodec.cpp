$NetBSD: patch-test_test__cppcodec.cpp,v 1.1 2024/01/15 09:40:27 nros Exp $

Adapt for catch2 version 3

--- test/test_cppcodec.cpp.orig	2018-08-20 14:56:28.000000000 +0000
+++ test/test_cppcodec.cpp
@@ -21,8 +21,7 @@
  *  IN THE SOFTWARE.
  */
 
-#define CATCH_CONFIG_MAIN
-#include <catch2/catch.hpp>
+#include <catch2/catch_all.hpp>
 
 #include <cppcodec/base32_crockford.hpp>
 #include <cppcodec/base32_hex.hpp>
