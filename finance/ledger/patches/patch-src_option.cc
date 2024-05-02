$NetBSD: patch-src_option.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/option.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/option.cc
@@ -132,7 +132,8 @@ void process_environment(const char ** e
         if (*q == '_')
           *r++ = '-';
         else
-          *r++ = static_cast<char>(std::tolower(*q));
+          *r++ = static_cast<char>(std::tolower(
+            static_cast<unsigned char>(*q)));
       *r = '\0';
 
       if (*q == '=') {
