$NetBSD: patch-src_util_string__converter.cc,v 1.5 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/util/string_converter.cc.orig	2026-06-25 08:04:46.598053683 +0000
+++ src/util/string_converter.cc
@@ -144,7 +144,7 @@ std::pair<std::string, std::string> StringConverter::_
 #endif
 
     if (ret == -1) {
-        std::string err = fmt::format("iconv: {}", std::strerror(errno));
+        std::string err = fmt::format("iconv: {}", strerror(errno));
         switch (errno) {
         case EILSEQ:
         case EINVAL: {
