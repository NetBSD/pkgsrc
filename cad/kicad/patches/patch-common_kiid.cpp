$NetBSD: patch-common_kiid.cpp,v 1.1 2024/10/04 04:25:36 ryoon Exp $

* Fix build with boost-1.86.0.
From: https://gitlab.com/kicad/code/kicad/-/commit/9a3ebfba404e43d82b5c194e01f6afb67909bf88
      https://gitlab.com/kicad/code/kicad/-/commit/a9e115925a5168034f60d0fe1e7b369861f84b82

--- common/kiid.cpp.orig	2024-09-06 16:28:40.000000000 +0000
+++ common/kiid.cpp
@@ -25,9 +25,9 @@
 
 #include <kiid.h>
 
+#include <boost/random/mersenne_twister.hpp>
 #include <boost/uuid/uuid_generators.hpp>
 #include <boost/uuid/uuid_io.hpp>
-#include <boost/functional/hash.hpp>
 
 #if BOOST_VERSION >= 106700
 #include <boost/uuid/entropy_error.hpp>
@@ -235,15 +235,7 @@ timestamp_t KIID::AsLegacyTimestamp() co
 
 size_t KIID::Hash() const
 {
-    size_t hash = 0;
-
-    // Note: this is NOT little-endian/big-endian safe, but as long as it's just used
-    // at runtime it won't matter.
-
-    for( int i = 0; i < 4; ++i )
-        boost::hash_combine( hash, reinterpret_cast<const uint32_t*>( m_uuid.data )[i] );
-
-    return hash;
+    return boost::uuids::hash_value( m_uuid );
 }
 
 
