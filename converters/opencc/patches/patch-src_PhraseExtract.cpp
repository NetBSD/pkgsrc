$NetBSD: patch-src_PhraseExtract.cpp,v 1.1 2021/10/21 20:10:24 jperkin Exp $

Explicitly use std::log.

--- src/PhraseExtract.cpp.orig	2020-05-22 09:43:04.000000000 +0000
+++ src/PhraseExtract.cpp
@@ -28,6 +28,8 @@
 #pragma execution_character_set("utf-8")
 #endif
 
+using std::log;
+
 namespace opencc {
 
 namespace internal {
