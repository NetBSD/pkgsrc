$NetBSD: patch-tests_src_unit-regression2.cpp,v 1.1 2025/04/27 20:07:25 wiz Exp $

https://github.com/nlohmann/json/pull/4763

--- tests/src/unit-regression2.cpp.orig	2025-04-11 08:42:28.000000000 +0000
+++ tests/src/unit-regression2.cpp
@@ -388,7 +388,7 @@ struct Example_3810
     Example_3810() = default;
 };
 
-NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Example_3810, bla); // NOLINT(misc-use-internal-linkage)
+NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Example_3810, bla) // NOLINT(misc-use-internal-linkage)
 
 TEST_CASE("regression tests 2")
 {
