$NetBSD: patch-src_mongo_db_fts_unicode_string.cpp,v 1.1 2019/06/28 16:30:56 gdt Exp $

* Fix build with boost 1.62.0

--- src/mongo/db/fts/unicode/string.cpp.orig	2016-09-26 12:10:04.000000000 +0000
+++ src/mongo/db/fts/unicode/string.cpp
@@ -274,7 +274,7 @@ bool String::substrMatch(const std::stri
 
     // Case sensitive and diacritic sensitive.
     return boost::algorithm::boyer_moore_search(
-               haystack.begin(), haystack.end(), needle.begin(), needle.end()) != haystack.end();
+               haystack.begin(), haystack.end(), needle.begin(), needle.end()) != std::make_pair(haystack.end(), haystack.end());
 }
 
 }  // namespace unicode
