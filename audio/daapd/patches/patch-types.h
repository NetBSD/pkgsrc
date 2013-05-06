$NetBSD: patch-types.h,v 1.1 2013/05/06 14:17:28 joerg Exp $

--- types.h.orig	2013-05-04 14:53:09.000000000 +0000
+++ types.h
@@ -32,6 +32,7 @@
 #include <sys/stat.h>
 #include <strings.h>
 #include <pthread.h>
+#include <cstdlib>
 
 // #include "mmgr.h"
 
@@ -40,41 +41,7 @@
 
 #include "dboutput.h"
 #include "songcache.h"
-
-
-// STL defines no hash function for std::string.
-// How annoying.
-
-#ifdef __GNUC__
-// gcc version < 3.1.0 ?
-#if __GNUC__ < 3 || \
-(__GNUC__ == 3 && __GNUC_MINOR__ < 1)
-	__STL_BEGIN_NAMESPACE
-		template<> struct hash<std::string> {
-			size_t operator()(std::string __s) const { 
-				return __stl_hash_string( (const char*) __s.c_str() ); 
-			}
-		};
-	__STL_END_NAMESPACE
-#else
-	namespace __gnu_cxx {
-		template<> struct hash<std::string> {
-			size_t operator()(std::string __s) const { 
-				return __stl_hash_string( (const char*) __s.c_str() ); 
-			}
-		};
-	}
-#endif // GCC_VERSION
-#else
-	__STL_BEGIN_NAMESPACE
-		template<> struct hash<std::string> {
-			size_t operator()(std::string __s) const { 
-				return __stl_hash_string( (const char*) __s.c_str() ); 
-			}
-		};
-	__STL_END_NAMESPACE
-#endif // __GNUC__
-
+#include <string>
 
 // database/server init parameters
 struct InitParams {
