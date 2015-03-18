$NetBSD: patch-parser__keywords.cpp,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- parser_keywords.cpp.orig	2015-03-17 22:07:00.000000000 +0000
+++ parser_keywords.cpp
@@ -32,7 +32,7 @@ bool parser_keywords_is_switch(const wcs
 
 bool parser_keywords_skip_arguments(const wcstring &cmd)
 {
-    return contains(cmd,
+    return contains(&cmd,
                     L"else",
                     L"begin");
 }
@@ -42,7 +42,7 @@ bool parser_keywords_is_subcommand(const
 {
 
     return parser_keywords_skip_arguments(cmd) ||
-           contains(cmd,
+           contains(&cmd,
                     L"command",
                     L"builtin",
                     L"while",
@@ -56,7 +56,7 @@ bool parser_keywords_is_subcommand(const
 
 bool parser_keywords_is_block(const wcstring &word)
 {
-    return contains(word,
+    return contains(&word,
                     L"for",
                     L"while",
                     L"if",
@@ -69,7 +69,7 @@ bool parser_keywords_is_reserved(const w
 {
     return parser_keywords_is_block(word) ||
            parser_keywords_is_subcommand(word) ||
-           contains(word,
+           contains(&word,
                     L"end",
                     L"case",
                     L"else",
