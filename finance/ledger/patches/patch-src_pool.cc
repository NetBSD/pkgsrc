$NetBSD: patch-src_pool.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/pool.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/pool.cc
@@ -327,13 +327,15 @@ commodity_pool_t::parse_price_directive
   datetime_t datetime;
   string     symbol;
 
-  if (! no_date && std::isdigit(time_field_ptr[0])) {
+  if (! no_date &&
+      std::isdigit(static_cast<unsigned char>(time_field_ptr[0]))) {
     symbol_and_price = next_element(time_field_ptr);
     if (! symbol_and_price) return none;
 
     datetime = parse_datetime(date_field + " " + time_field_ptr);
   }
-  else if (! no_date && std::isdigit(date_field_ptr[0])) {
+  else if (! no_date &&
+           std::isdigit(static_cast<unsigned char>(date_field_ptr[0]))) {
     symbol_and_price = time_field_ptr;
     datetime = datetime_t(parse_date(date_field));
   }
