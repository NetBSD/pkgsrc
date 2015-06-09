$NetBSD: patch-gold_system.h,v 1.3 2015/06/09 20:24:39 ryoon Exp $

--- gold/system.h.orig	2014-10-14 07:32:04.000000000 +0000
+++ gold/system.h
@@ -118,7 +118,7 @@ struct hash<std::string>
 {
   size_t
   operator()(std::string s) const
-  { return __stl_hash_string(s.c_str()); }
+  { return __gnu_cxx::hash<const char *>()(s.c_str()); }
 };
 
 template<typename T>
