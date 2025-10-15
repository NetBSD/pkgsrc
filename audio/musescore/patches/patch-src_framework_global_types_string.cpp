$NetBSD: patch-src_framework_global_types_string.cpp,v 1.1 2025/10/15 03:32:58 gutteridge Exp $

Use ctype(3) correctly.

--- src/framework/global/types/string.cpp.orig	2025-10-10 09:21:06.000000000 +0000
+++ src/framework/global/types/string.cpp
@@ -88,14 +88,14 @@ static double toDouble_helper(const char
 static void ltrim_helper(std::u16string& s)
 {
     s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char16_t ch) {
-        return !std::isspace(ch);
+        return !std::isspace(static_cast<unsigned char>(ch));
     }));
 }
 
 static void rtrim_helper(std::u16string& s)
 {
     s.erase(std::find_if(s.rbegin(), s.rend(), [](char16_t ch) {
-        return !std::isspace(ch);
+        return !std::isspace(static_cast<unsigned char>(ch));
     }).base(), s.end());
 }
 
