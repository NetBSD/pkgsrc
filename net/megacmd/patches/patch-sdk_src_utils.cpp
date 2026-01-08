$NetBSD: patch-sdk_src_utils.cpp,v 1.1 2026/01/08 17:52:19 kikadf Exp $

* Fix ctype(3) tolower usage

--- sdk/src/utils.cpp.orig	2026-01-03 22:27:50.415280578 +0000
+++ sdk/src/utils.cpp
@@ -2190,7 +2190,7 @@ string webdavnameescape(const string &va
 
 void tolower_string(std::string& str)
 {
-    std::transform(str.begin(), str.end(), str.begin(), [](char c) {return static_cast<char>(::tolower(c)); });
+    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return static_cast<char>(::tolower(c)); });
 }
 
 #ifdef __APPLE__
