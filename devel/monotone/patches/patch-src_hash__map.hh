$NetBSD: patch-src_hash__map.hh,v 1.2 2014/05/06 08:21:15 wiz Exp $

Add missing include. Use C++11 STL for libc++ and when in C++11 mode.

--- src/hash_map.hh.orig	2013-05-06 13:12:19.000000000 +0000
+++ src/hash_map.hh
@@ -50,7 +50,43 @@ namespace hashmap {
   };
 }
 
-#if HAVE_TR1_UNORDERED_MAP_AND_SET && HAVE_WORKING_TR1_UNORDERED_MAP_AND_SET
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#define HASHMAP_PRESENT
+#include <unordered_map>
+#include <unordered_set>
+
+namespace hashmap {
+  template<>
+  struct hash<std::string>
+  {
+    size_t operator()(std::string const & s) const
+    {
+      return std::hash<std::string>()(s);
+    }
+  };
+
+  template<typename _Key, typename _Value>
+  class hash_map : public std::unordered_map<_Key,
+                                                  _Value,
+                                                  hash<_Key>,
+                                                  equal_to<_Key> >
+  {};
+
+  template<typename _Key>
+  class hash_set : public std::unordered_set<_Key,
+                                                  hash<_Key>,
+                                                  equal_to<_Key> >
+  {};
+
+  template<typename _Key, typename _Value>
+  class hash_multimap : public std::unordered_multimap<_Key,
+                                                            _Value,
+                                                            hash<_Key>,
+                                                            equal_to<_Key> >
+  {};
+}
+
+#elif HAVE_TR1_UNORDERED_MAP_AND_SET && HAVE_WORKING_TR1_UNORDERED_MAP_AND_SET
 #define HASHMAP_PRESENT
 #include <tr1/functional>
 #include <tr1/unordered_map>
