$NetBSD: patch-gold_system.h,v 1.2 2015/03/24 14:23:14 joerg Exp $

--- gold/system.h.orig	2013-11-04 15:33:39.000000000 +0000
+++ gold/system.h
@@ -56,8 +56,18 @@
 #endif
 
 // Figure out how to get a hash set and a hash map.
+#include <cstddef>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <unordered_set>
+#include <unordered_map>
+
+#define Unordered_set std::unordered_set
+#define Unordered_map std::unordered_map
+#define Unordered_multimap std::unordered_multimap
 
-#if defined(HAVE_TR1_UNORDERED_SET) && defined(HAVE_TR1_UNORDERED_MAP) \
+#define reserve_unordered_map(map, n) ((map)->rehash(n))
+
+#elif defined(HAVE_TR1_UNORDERED_SET) && defined(HAVE_TR1_UNORDERED_MAP) \
     && defined(HAVE_TR1_UNORDERED_MAP_REHASH)
 
 #include <tr1/unordered_set>
@@ -105,7 +115,7 @@ struct hash<std::string>
 {
   size_t
   operator()(std::string s) const
-  { return __stl_hash_string(s.c_str()); }
+  { return __gnu_cxx::hash<const char *>()(s.c_str()); }
 };
 
 template<typename T>
