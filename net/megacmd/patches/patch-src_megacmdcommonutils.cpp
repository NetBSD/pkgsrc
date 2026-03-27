$NetBSD: patch-src_megacmdcommonutils.cpp,v 1.3 2026/03/27 11:06:04 kikadf Exp $

* BSDs use the functions of linux
* Fix ctype(3) tolower usage

--- src/megacmdcommonutils.cpp.orig	2026-03-21 08:58:56.000000000 +0000
+++ src/megacmdcommonutils.cpp
@@ -556,7 +556,7 @@ string toLower(const std::string& str)
     std::string lower = str;
     for (char& c : lower)
     {
-        c = std::tolower(c);
+        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
     }
     return lower;
 }
@@ -1089,7 +1089,8 @@ bool isValidEmail(const string &email)
     return true;
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 std::string getCurrentExecPath()
 {
     std::string path = ".";
