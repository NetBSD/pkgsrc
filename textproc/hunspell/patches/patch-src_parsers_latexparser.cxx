$NetBSD: patch-src_parsers_latexparser.cxx,v 1.1 2025/11/22 20:25:05 leot Exp $

Avoid ctype(3) abuses.

--- src/parsers/latexparser.cxx.orig	2025-11-22 19:50:34.936082555 +0000
+++ src/parsers/latexparser.cxx
@@ -157,7 +157,7 @@ int LaTeXParser::look_pattern(int col) {
     const char* k = PATTERN[i].pat[col];
     if (!k)
       continue;
-    while ((*k != '\0') && (tolower(*j) == *k)) {
+    while ((*k != '\0') && (tolower((unsigned char)*j) == *k)) {
       j++;
       k++;
     }
