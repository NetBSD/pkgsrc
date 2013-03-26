$NetBSD: patch-src_common_OW__HashMap.hpp,v 1.1 2013/03/26 23:34:34 joerg Exp $

--- src/common/OW_HashMap.hpp.orig	2013-03-25 15:16:33.000000000 +0000
+++ src/common/OW_HashMap.hpp
@@ -35,14 +35,14 @@
 #ifndef OW_HASH_MAP_HPP_INCLUDE_GUARD_
 #define OW_HASH_MAP_HPP_INCLUDE_GUARD_
 #include "OW_config.h"
-#ifdef OW_HAVE_HASH_MAP
-	#include <hash_map> // hash_map is better for the cache than OW_SortedVectorMap
-	#define OW_HASH_MAP_NS std
-	#define HashMap std::hash_map
-#elif OW_HAVE_EXT_HASH_MAP
+#if OW_HAVE_EXT_HASH_MAP
 	#include <ext/hash_map> // hash_map is better for the cache than OW_SortedVectorMap
 	#define OW_HASH_MAP_NS __gnu_cxx
 	#define HashMap __gnu_cxx::hash_map
+#elif OW_HAVE_HASH_MAP
+	#include <hash_map> // hash_map is better for the cache than OW_SortedVectorMap
+	#define OW_HASH_MAP_NS std
+	#define HashMap std::hash_map
 #else
 	#include "OW_SortedVectorMap.hpp"
 	#define OW_HASH_MAP_NS OW_NAMESPACE
