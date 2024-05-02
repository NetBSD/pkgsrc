$NetBSD: patch-src_report.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/report.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/report.cc
@@ -642,10 +642,10 @@ value_t report_t::fn_trim(call_scope_t& 
   const char * p = buf.get();
   const char * e = buf.get() + temp.length() - 1;
 
-  while (p <= e && std::isspace(*p))
+  while (p <= e && std::isspace(static_cast<unsigned char>(*p)))
     p++;
 
-  while (e > p && std::isspace(*e))
+  while (e > p && std::isspace(static_cast<unsigned char>(*e)))
     e--;
 
   if (p > e) {
