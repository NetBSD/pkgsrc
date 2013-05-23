$NetBSD: patch-src_parse.cpp,v 1.1 2013/05/23 18:41:21 joerg Exp $

--- src/parse.cpp.orig	2013-05-23 17:24:24.000000000 +0000
+++ src/parse.cpp
@@ -96,7 +96,7 @@ void ParseSemantics::exampleParse()
     }
 }
 
-void ParseSemantics::readline(char * buf, int& char_read, int max_size)
+void ParseSemantics::readline(char * buf, size_t& char_read, int max_size)
 {
     if (exampleInput) {
         int length = strlen(*exampleInput);
