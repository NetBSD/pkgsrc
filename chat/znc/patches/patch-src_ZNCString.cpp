$NetBSD: patch-src_ZNCString.cpp,v 1.1 2026/08/28 12:44:14 plunky Exp $

fix ctype(3) failures

--- src/ZNCString.cpp.orig	2025-07-01 21:17:15.000000000 +0000
+++ src/ZNCString.cpp
@@ -220,7 +220,7 @@ CString& CString::MakeUpper() {
 CString& CString::MakeUpper() {
     for (char& c : *this) {
         // TODO use unicode
-        c = (char)toupper(c);
+        c = (char)toupper((unsigned char)c);
     }
 
     return *this;
@@ -229,7 +229,7 @@ CString& CString::MakeLower() {
 CString& CString::MakeLower() {
     for (char& c : *this) {
         // TODO use unicode
-        c = (char)tolower(c);
+        c = (char)tolower((unsigned char)c);
     }
 
     return *this;
