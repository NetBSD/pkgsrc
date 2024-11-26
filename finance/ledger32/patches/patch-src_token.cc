$NetBSD: patch-src_token.cc,v 1.1 2024/11/26 23:07:02 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/token.cc.orig	2020-05-18 05:30:10.000000000 +0000
+++ src/token.cc
@@ -45,7 +45,7 @@ int expr_t::token_t::parse_reserved_word
     length = 0;
 
     char buf[6];
-    READ_INTO_(in, buf, 5, c, length, std::isalpha(c));
+    READ_INTO_(in, buf, 5, c, length, std::isalpha(static_cast<unsigned char>(c)));
 
     switch (buf[0]) {
     case 'a':
@@ -132,7 +132,7 @@ void expr_t::token_t::parse_ident(std::i
   length = 0;
 
   char c, buf[256];
-  READ_INTO_(in, buf, 255, c, length, std::isalnum(c) || c == '_');
+  READ_INTO_(in, buf, 255, c, length, std::isalnum(static_cast<unsigned char>(c)) || c == '_');
 
   value.set_string(buf);
 }
@@ -384,7 +384,7 @@ void expr_t::token_t::next(std::istream&
 
     // First, check to see if it's a reserved word, such as: and or not
     int result = parse_reserved_word(in);
-    if (std::isalpha(c) && result == 1)
+    if (std::isalpha(static_cast<unsigned char>(c)) && result == 1)
       break;
 
     // If not, rewind back to the beginning of the word to scan it
@@ -422,7 +422,7 @@ void expr_t::token_t::next(std::istream&
 
         c = static_cast<char>(in.peek());
         if (c != -1) {
-          if (! std::isalpha(c) && c != '_')
+          if (! std::isalpha(static_cast<unsigned char>(c)) && c != '_')
             expected('\0', c);
 
           parse_ident(in);
