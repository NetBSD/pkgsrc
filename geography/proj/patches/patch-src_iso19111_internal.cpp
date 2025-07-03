$NetBSD: patch-src_iso19111_internal.cpp,v 1.2 2025/07/03 17:55:04 gdt Exp $

Fix ctype abuse, which causes test failures on NetBSD-current (11).

https://github.com/OSGeo/PROJ/issues/4537

--- src/iso19111/internal.cpp.orig	2025-07-03 13:10:59.122964425 +0000
+++ src/iso19111/internal.cpp
@@ -130,7 +130,7 @@ std::string tolower(const std::string &s
 {
     std::string ret(str);
     for (size_t i = 0; i < ret.size(); i++)
-        ret[i] = static_cast<char>(::tolower(ret[i]));
+        ret[i] = static_cast<char>(::tolower((unsigned char) ret[i]));
     return ret;
 }
 
@@ -145,7 +145,7 @@ std::string toupper(const std::string &s
 {
     std::string ret(str);
     for (size_t i = 0; i < ret.size(); i++)
-        ret[i] = static_cast<char>(::toupper(ret[i]));
+        ret[i] = static_cast<char>(::toupper((unsigned char) ret[i]));
     return ret;
 }
 
