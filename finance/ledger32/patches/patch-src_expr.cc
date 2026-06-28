$NetBSD: patch-src_expr.cc,v 1.2 2026/06/28 19:59:00 wiz Exp $

Fix build with latest boost.

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/expr.cc.orig	2020-05-18 05:30:10.000000000 +0000
+++ src/expr.cc
@@ -31,6 +31,7 @@
 
 #include <system.hh>
 
+#include <boost/scoped_ptr.hpp>
 #include "expr.h"
 #include "parser.h"
 #include "scope.h"
@@ -220,7 +221,7 @@ bool merged_expr_t::check_for_single_identifier(const 
 {
   bool single_identifier = true;
   for (const char * p = expr.c_str(); *p; ++p)
-    if (! std::isalnum(*p) || *p == '_') {
+    if (! std::isalnum(static_cast<unsigned char>(*p)) || *p == '_') {
       single_identifier = false;
       break;
     }
