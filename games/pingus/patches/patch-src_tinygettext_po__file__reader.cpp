$NetBSD: patch-src_tinygettext_po__file__reader.cpp,v 1.1 2011/08/14 19:13:03 wiz Exp $

Fix build with gcc-4.5.

--- src/tinygettext/po_file_reader.cpp.orig	2010-03-18 11:52:00.000000000 +0000
+++ src/tinygettext/po_file_reader.cpp
@@ -169,7 +169,7 @@ POFileReader::tokenize_po(std::istream& 
   int c;
   Token token;
 
-  while((c = getchar(in)) != EOF)
+  while((c = pgetchar(in)) != EOF)
     {
       //std::cout << "Lexing char: '" << char(c) << "' " << c << " state: " << state << std::endl;
       switch(state)
@@ -190,7 +190,7 @@ POFileReader::tokenize_po(std::istream& 
                 
               do { // Read keyword 
                 token.keyword += c;
-              } while((c = getchar(in)) != EOF && !isspace(c));
+              } while((c = pgetchar(in)) != EOF && !isspace(c));
               in.unget();
 
               state = READ_CONTENT;
@@ -198,7 +198,7 @@ POFileReader::tokenize_po(std::istream& 
           break;
 
         case READ_CONTENT:
-          while((c = getchar(in)) != EOF)
+          while((c = pgetchar(in)) != EOF)
             {
               if (c == '"') { 
                 // Found start of content
@@ -217,7 +217,7 @@ POFileReader::tokenize_po(std::istream& 
 
         case READ_CONTENT_IN_STRING:
           if (c == '\\') {
-            c = getchar(in);
+            c = pgetchar(in);
             if (c != EOF)
               {
                 if (c == 'n') token.content += '\n';
