$NetBSD: patch-utils_ResourceCache.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- utils/ResourceCache.hpp.orig	2013-06-15 10:04:56.000000000 +0000
+++ utils/ResourceCache.hpp
@@ -60,7 +60,7 @@ protected:
     }
     virtual ~ResourceCache()
     {
-	typename hash_map< const string, ResourceT*, hash<const string>, equal_to<const string> >::const_iterator ci;
+	typename hash_map< const string, ResourceT*, HASH_NAMESPACE::hash<const string>, equal_to<const string> >::const_iterator ci;
 	for( ci=_resourceMap.begin(); ci!=_resourceMap.end(); ci++)
 	{
 	    ResourceT *res = ci->second;
@@ -70,7 +70,7 @@ protected:
     }
 
     virtual ResourceT *load( const string &resource) = 0;
-    hash_map< const string, ResourceT*, hash<const string>, equal_to<const string> > _resourceMap;
+    hash_map< const string, ResourceT*, HASH_NAMESPACE::hash<const string>, equal_to<const string> > _resourceMap;
 
 private:
     ResourceCache( const ResourceCache&);
