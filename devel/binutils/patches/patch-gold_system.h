$NetBSD: patch-gold_system.h,v 1.4 2016/02/03 19:56:34 jperkin Exp $

--- gold/system.h.orig	2015-11-13 08:27:42.000000000 +0000
+++ gold/system.h
@@ -118,7 +118,7 @@ struct hash<std::string>
 {
   size_t
   operator()(std::string s) const
-  { return __stl_hash_string(s.c_str()); }
+  { return __gnu_cxx::hash<const char *>()(s.c_str()); }
 };
 
 template<typename T>
