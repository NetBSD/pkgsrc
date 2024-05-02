$NetBSD: patch-src_amount.cc,v 1.1 2024/05/02 12:22:13 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/amount.cc.orig	2020-05-18 05:30:10.000000000 +0000
+++ src/amount.cc
@@ -979,7 +979,8 @@ namespace {
               std::isdigit(c) || c == '-' || c == '.' || c == ',');
 
     string::size_type len = std::strlen(buf);
-    while (len > 0 && ! std::isdigit(buf[len - 1])) {
+    while (len > 0 &&
+           ! std::isdigit(static_cast<unsigned char>(buf[len - 1]))) {
       buf[--len] = '\0';
       in.unget();
     }
@@ -1014,7 +1015,7 @@ bool amount_t::parse(std::istream& in, c
     parse_quantity(in, quant);
 
     if (! in.eof() && ((n = static_cast<char>(in.peek())) != '\n')) {
-      if (std::isspace(n))
+      if (std::isspace(static_cast<unsigned char>(n)))
         comm_flags |= COMMODITY_STYLE_SEPARATED;
 
       commodity_t::parse_symbol(in, symbol);
@@ -1030,7 +1031,7 @@ bool amount_t::parse(std::istream& in, c
     commodity_t::parse_symbol(in, symbol);
 
     if (! in.eof() && ((n = static_cast<char>(in.peek())) != '\n')) {
-      if (std::isspace(static_cast<char>(in.peek())))
+      if (std::isspace(in.peek()))
         comm_flags |= COMMODITY_STYLE_SEPARATED;
 
       parse_quantity(in, quant);
