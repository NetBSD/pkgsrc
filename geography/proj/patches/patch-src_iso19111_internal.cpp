$NetBSD: patch-src_iso19111_internal.cpp,v 1.3 2025/07/03 23:40:38 gdt Exp $

Fix ctype usage.

From https://github.com/OSGeo/PROJ/pull/4539

--- src/iso19111/internal.cpp.orig	2025-04-01 21:34:48.000000000 +0000
+++ src/iso19111/internal.cpp
@@ -129,8 +129,9 @@ std::string tolower(const std::string &s
 
 {
     std::string ret(str);
-    for (size_t i = 0; i < ret.size(); i++)
-        ret[i] = static_cast<char>(::tolower(ret[i]));
+    for (char &ch : ret)
+        ch =
+            (ch >= 'A' && ch <= 'Z') ? static_cast<char>(ch + ('a' - 'A')) : ch;
     return ret;
 }
 
@@ -144,8 +145,9 @@ std::string toupper(const std::string &s
 
 {
     std::string ret(str);
-    for (size_t i = 0; i < ret.size(); i++)
-        ret[i] = static_cast<char>(::toupper(ret[i]));
+    for (char &ch : ret)
+        ch =
+            (ch >= 'a' && ch <= 'z') ? static_cast<char>(ch - ('a' - 'A')) : ch;
     return ret;
 }
 
