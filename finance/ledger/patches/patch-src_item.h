$NetBSD: patch-src_item.h,v 1.1 2018/03/14 13:59:52 wiz Exp $

Fix build with boost-1.61+ and gcc-6.
https://github.com/ledger/ledger/commit/258cab91ab702e82d477b41bb1c6a026c848bda5

--- src/item.h.orig	2016-01-11 15:59:38.000000000 +0000
+++ src/item.h
@@ -92,7 +92,7 @@ public:
 
   typedef std::pair<optional<value_t>, bool> tag_data_t;
   typedef std::map<string, tag_data_t,
-                   function<bool(string, string)> > string_map;
+                   std::function<bool(string, string)> > string_map;
 
   state_t              _state;
   optional<date_t>     _date;
