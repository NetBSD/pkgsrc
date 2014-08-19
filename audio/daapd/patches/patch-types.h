$NetBSD: patch-types.h,v 1.2 2014/08/19 13:30:39 joerg Exp $

--- types.h.orig	2014-08-19 12:33:06.000000000 +0000
+++ types.h
@@ -52,7 +52,7 @@
 	__STL_BEGIN_NAMESPACE
 		template<> struct hash<std::string> {
 			size_t operator()(std::string __s) const { 
-				return __stl_hash_string( (const char*) __s.c_str() ); 
+				return hash<const char *>()(__s.c_str()); 
 			}
 		};
 	__STL_END_NAMESPACE
@@ -60,7 +60,7 @@
 	namespace __gnu_cxx {
 		template<> struct hash<std::string> {
 			size_t operator()(std::string __s) const { 
-				return __stl_hash_string( (const char*) __s.c_str() ); 
+				return hash<const char *>()(__s.c_str()); 
 			}
 		};
 	}
@@ -69,7 +69,7 @@
 	__STL_BEGIN_NAMESPACE
 		template<> struct hash<std::string> {
 			size_t operator()(std::string __s) const { 
-				return __stl_hash_string( (const char*) __s.c_str() ); 
+				return hash<const char *>()(__s.c_str()); 
 			}
 		};
 	__STL_END_NAMESPACE
@@ -109,7 +109,7 @@ struct InitParams {
 	}
 
 	~InitParams() {
-		free(dirs);
+		delete dirs;
 	}
 };
 
