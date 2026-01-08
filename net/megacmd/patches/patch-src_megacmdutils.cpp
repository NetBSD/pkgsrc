$NetBSD: patch-src_megacmdutils.cpp,v 1.1 2026/01/08 17:52:20 kikadf Exp $

* Fix ctype(3) tolower usage

--- src/megacmdutils.cpp.orig	2026-01-03 22:04:27.842177008 +0000
+++ src/megacmdutils.cpp
@@ -546,7 +546,7 @@ string secondsToText(m_time_t seconds, b
 const char *getTimeFormatFromSTR(string formatName)
 {
     string lformatName = formatName;
-    transform(lformatName.begin(), lformatName.end(), lformatName.begin(), [](char c) { return (char)::tolower(c); });
+    transform(lformatName.begin(), lformatName.end(), lformatName.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
 
     if (lformatName == "rfc2822")
     {
