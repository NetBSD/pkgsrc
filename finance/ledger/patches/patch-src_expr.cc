$NetBSD: patch-src_expr.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/expr.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/expr.cc
@@ -222,7 +222,7 @@ bool merged_expr_t::check_for_single_ide
 {
   bool single_identifier = true;
   for (const char * p = expr.c_str(); *p; ++p)
-    if (! std::isalnum(*p) || *p == '_') {
+    if (! std::isalnum(static_cast<unsigned char>(*p)) || *p == '_') {
       single_identifier = false;
       break;
     }
