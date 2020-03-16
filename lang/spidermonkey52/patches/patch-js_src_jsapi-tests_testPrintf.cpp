$NetBSD: patch-js_src_jsapi-tests_testPrintf.cpp,v 1.1 2020/03/16 13:30:57 tnn Exp $

testPrintf.cpp:58:20: error: '%s' directive argument is null [-Werror=format-overflow=]

--- js/src/jsapi-tests/testPrintf.cpp.orig	2018-04-28 01:04:03.000000000 +0000
+++ js/src/jsapi-tests/testPrintf.cpp
@@ -55,7 +55,6 @@ BEGIN_TEST(testPrintf)
     CHECK(print_one("27270", "%zu", (size_t) 27270));
     CHECK(print_one("27270", "%" PRIuSIZE, (size_t) 27270));
     CHECK(print_one("hello", "he%so", "ll"));
-    CHECK(print_one("(null)", "%s", zero()));
     CHECK(print_one("0", "%p", (char *) 0));
     CHECK(print_one("h", "%c", 'h'));
     CHECK(print_one("1.500000", "%f", 1.5f));
