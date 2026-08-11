$NetBSD: patch-utils_remote.cc,v 1.1 2026/08/11 14:21:47 riastradh Exp $

Fix ctype(3) abuse.
https://gnats.NetBSD.org/60574

--- utils/remote.cc.orig	2026-06-29 23:12:56.000000000 +0000
+++ utils/remote.cc
@@ -623,7 +623,7 @@ void add_id_arg(tr_variant::Map& params,
 
         for (auto const& ch : id_str)
         {
-            is_num = is_num && isdigit(ch);
+            is_num = is_num && isdigit(static_cast<unsigned char>(ch));
         }
 
         if (is_num || is_list)
