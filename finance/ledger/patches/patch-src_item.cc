$NetBSD: patch-src_item.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/item.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/item.cc
@@ -151,7 +151,8 @@ void item_t::parse_tags(const char * p,
   if (! std::strchr(p, ':')) {
     if (const char * b = std::strchr(p, '[')) {
       if (*(b + 1) != '\0' &&
-          (std::isdigit(*(b + 1)) || *(b + 1) == '=')) {
+          (std::isdigit(static_cast<unsigned char>(*(b + 1))) ||
+           *(b + 1) == '=')) {
         if (const char * e = std::strchr(b, ']')) {
           char buf[256];
           std::strncpy(buf, b + 1, static_cast<std::size_t>(e - b - 1));
