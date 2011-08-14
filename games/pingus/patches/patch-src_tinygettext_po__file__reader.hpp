$NetBSD: patch-src_tinygettext_po__file__reader.hpp,v 1.1 2011/08/14 19:13:03 wiz Exp $

Fix build with gcc-4.5.

--- src/tinygettext/po_file_reader.hpp.orig	2007-08-17 15:39:18.000000000 +0000
+++ src/tinygettext/po_file_reader.hpp
@@ -52,7 +52,7 @@ public:
   void add_token(const Token& token);  
   void tokenize_po(std::istream& in);
 
-  inline int getchar(std::istream& in) 
+  inline int pgetchar(std::istream& in) 
   {
     int c = in.get();
     if (c == '\n')
