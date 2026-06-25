$NetBSD: patch-src_util_tools.cc,v 1.1 2026/06/25 08:16:54 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/util/tools.cc.orig	2026-06-25 08:01:45.989715123 +0000
+++ src/util/tools.cc
@@ -270,8 +270,8 @@ std::string hexDecodeString(std::string_view encoded)
 
     auto buf = std::string(len / 2, '\0');
     for (std::size_t i = 0; i < len; i += 2) {
-        auto chi = std::strchr(hexChars, ptr[i]);
-        auto clo = std::strchr(hexChars, ptr[i + 1]);
+        auto chi = strchr(hexChars, ptr[i]);
+        auto clo = strchr(hexChars, ptr[i + 1]);
         std::size_t hi = chi ? chi - hexChars : 0;
         std::size_t lo = clo ? clo - hexChars : 0;
 
