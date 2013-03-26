$NetBSD: patch-src_common_OW__HashMultiMap.hpp,v 1.1 2013/03/26 23:34:34 joerg Exp $

--- src/common/OW_HashMultiMap.hpp.orig	2013-03-25 15:16:16.000000000 +0000
+++ src/common/OW_HashMultiMap.hpp
@@ -35,14 +35,14 @@
 #ifndef OW_HASH_MULTI_MAP_HPP_INCLUDE_GUARD_
 #define OW_HASH_MULTI_MAP_HPP_INCLUDE_GUARD_
 #include "OW_config.h"
-#ifdef OW_HAVE_HASH_MAP
-	#include <hash_map>
-	#define OW_HASH_MAP_NS std
-	#define HashMultiMap std::hash_multimap
-#elif OW_HAVE_EXT_HASH_MAP
+#if OW_HAVE_EXT_HASH_MAP
 	#include <ext/hash_map>
 	#define OW_HASH_MAP_NS __gnu_cxx
 	#define HashMultiMap __gnu_cxx::hash_multimap
+#elif OW_HAVE_HASH_MAP
+	#include <hash_map>
+	#define OW_HASH_MAP_NS std
+	#define HashMultiMap std::hash_multimap
 #else
 	// TODO: Write a real hash multi map
 	#include <map>
