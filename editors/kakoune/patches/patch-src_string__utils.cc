$NetBSD: patch-src_string__utils.cc,v 1.1 2020/05/14 19:06:55 joerg Exp $

--- src/string_utils.cc.orig	2020-05-11 00:59:12.075369477 +0000
+++ src/string_utils.cc
@@ -381,7 +381,7 @@ UnitTest test_string{[]()
 {
     kak_assert(String("youpi ") + "matin" == "youpi matin");
 
-    auto wrapped = "wrap this paragraph\n respecting whitespaces and much_too_long_words" | wrap_at(16) | gather<Vector>();
+    auto wrapped = "wrap this paragraph\n respecting whitespaces and much_too_long_words" | wrap_at(16) | gather<Vector<String>>();
     kak_assert(wrapped.size() == 6);
     kak_assert(wrapped[0] == "wrap this");
     kak_assert(wrapped[1] == "paragraph");
@@ -390,7 +390,7 @@ UnitTest test_string{[]()
     kak_assert(wrapped[4] == "much_too_long_wo");
     kak_assert(wrapped[5] == "rds");
 
-    auto wrapped2 = "error: unknown type" | wrap_at(7) | gather<Vector>();
+    auto wrapped2 = "error: unknown type" | wrap_at(7) | gather<Vector<String>>();
     kak_assert(wrapped2.size() == 3);
     kak_assert(wrapped2[0] == "error:");
     kak_assert(wrapped2[1] == "unknown");
