$NetBSD: patch-tests_src_unit-deserialization.cpp,v 1.1 2025/04/27 20:07:25 wiz Exp $

https://github.com/nlohmann/json/pull/4736

--- tests/src/unit-deserialization.cpp.orig	2025-04-11 08:42:28.000000000 +0000
+++ tests/src/unit-deserialization.cpp
@@ -1134,9 +1134,10 @@ TEST_CASE("deserialization")
     }
 }
 
-// select the types to test - char8_t is only available in C++20
+// select the types to test - char8_t is only available since C++20 if and only
+// if __cpp_char8_t is defined.
 #define TYPE_LIST(...) __VA_ARGS__
-#ifdef JSON_HAS_CPP_20
+#if defined(__cpp_char8_t) && (__cpp_char8_t >= 201811L)
     #define ASCII_TYPES TYPE_LIST(char, wchar_t, char16_t, char32_t, char8_t)
 #else
     #define ASCII_TYPES TYPE_LIST(char, wchar_t, char16_t, char32_t)
