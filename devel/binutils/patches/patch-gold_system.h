$NetBSD: patch-gold_system.h,v 1.5 2020/12/06 18:07:53 fcambus Exp $

--- gold/system.h.orig	2020-07-24 09:12:20.000000000 +0000
+++ gold/system.h
@@ -124,7 +124,7 @@ struct hash<std::string>
 {
   size_t
   operator()(std::string s) const
-  { return __stl_hash_string(s.c_str()); }
+  { return __gnu_cxx::hash<const char *>()(s.c_str()); }
 };
 
 template<typename T>
