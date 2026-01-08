$NetBSD: patch-src_megacmdcommonutils.cpp,v 1.2 2026/01/08 17:52:20 kikadf Exp $

* BSDs use the functions of linux
* Fix ctype(3) tolower usage

--- src/megacmdcommonutils.cpp.orig	2025-04-04 10:39:49.000000000 +0000
+++ src/megacmdcommonutils.cpp
@@ -660,7 +660,7 @@ string toLower(const std::string& str)
     std::string lower = str;
     for (char& c : lower)
     {
-        c = std::tolower(c);
+        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
     }
     return lower;
 }
@@ -1153,7 +1153,8 @@ bool isValidEmail(string email)
                     || (email.find("@") > email.find_last_of(".")));
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 std::string getCurrentExecPath()
 {
     std::string path = ".";
