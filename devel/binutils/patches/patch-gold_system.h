$NetBSD: patch-gold_system.h,v 1.1 2014/05/27 09:56:33 joerg Exp $

--- gold/system.h.orig	2014-05-26 18:29:32.000000000 +0000
+++ gold/system.h
@@ -105,7 +105,7 @@ struct hash<std::string>
 {
   size_t
   operator()(std::string s) const
-  { return __stl_hash_string(s.c_str()); }
+  { return __gnu_cxx::hash<const char *>()(s.c_str()); }
 };
 
 template<typename T>
