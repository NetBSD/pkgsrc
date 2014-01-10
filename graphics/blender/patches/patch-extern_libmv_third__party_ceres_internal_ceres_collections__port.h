$NetBSD: patch-extern_libmv_third__party_ceres_internal_ceres_collections__port.h,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- extern/libmv/third_party/ceres/internal/ceres/collections_port.h.orig	2013-11-20 21:36:24.000000000 +0000
+++ extern/libmv/third_party/ceres/internal/ceres/collections_port.h
@@ -33,11 +33,13 @@
 #ifndef CERES_INTERNAL_COLLECTIONS_PORT_H_
 #define CERES_INTERNAL_COLLECTIONS_PORT_H_
 
+#include <cstddef>
+
 #if defined(CERES_NO_TR1)
 #  include <map>
 #  include <set>
 #else
-#  if defined(_MSC_VER)
+#  if defined(_MSC_VER) || defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
 #    include <unordered_map>
 #    include <unordered_set>
 #  else
@@ -71,11 +73,24 @@ struct HashSet : set<K> {};
 namespace ceres {
 namespace internal {
 
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#undef CERES_HASH_NAMESPACE_START
+#define CERES_HASH_NAMESPACE_START namespace std {
+#undef CERES_HASH_NAMESPACE_END
+#define CERES_HASH_NAMESPACE_END }
+
+template<typename K, typename V>
+struct HashMap : std::unordered_map<K, V> {};
+
+template<typename K>
+struct HashSet : std::unordered_set<K> {};
+#else
 template<typename K, typename V>
 struct HashMap : std::tr1::unordered_map<K, V> {};
 
 template<typename K>
 struct HashSet : std::tr1::unordered_set<K> {};
+#endif
 
 #if defined(_WIN32) && !defined(__MINGW64__) && !defined(__MINGW32__)
 #define GG_LONGLONG(x) x##I64
