$NetBSD: patch-utils_ResourceManager.cpp,v 1.2 2013/06/16 20:40:40 joerg Exp $

--- utils/ResourceManager.cpp.orig	2005-01-02 02:59:29.000000000 +0000
+++ utils/ResourceManager.cpp
@@ -15,6 +15,7 @@
 #include <iomanip>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <string.h>
 
 #include <Trace.hpp>
 #include <ResourceManager.hpp>
@@ -31,7 +32,7 @@ const char PATH_SEPERATOR = '/';
 //Destroy resource manager
 ResourceManager::~ResourceManager()
 {
-    hash_map< const string, DirectoryEntry*, hash<const string> >::const_iterator ci;
+    hash_map< const string, DirectoryEntry*, HASH_NAMESPACE::hash<const string> >::const_iterator ci;
     for( ci=_dirEntryMap.begin(); ci!=_dirEntryMap.end(); ci++)
     {
         delete ci->second;
@@ -285,7 +286,7 @@ ziStream &ResourceManager::getInputStrea
 
 void ResourceManager::getResourceList( list<string> &rNameList)
 {
-    hash_map< const string, DirectoryEntry*, hash<const string> >::const_iterator ci;
+    hash_map< const string, DirectoryEntry*, HASH_NAMESPACE::hash<const string> >::const_iterator ci;
     for( ci=_dirEntryMap.begin(); ci!=_dirEntryMap.end(); ci++)
     {
         rNameList.insert( rNameList.end(), ci->second->resourceName);
@@ -297,7 +298,7 @@ void ResourceManager::dump( void)
     int totalOrig = 0;
     int totalComp = 0;
 
-    hash_map< const string, DirectoryEntry*, hash<const string> >::const_iterator ci;
+    hash_map< const string, DirectoryEntry*, HASH_NAMESPACE::hash<const string> >::const_iterator ci;
     for( ci=_dirEntryMap.begin(); ci!=_dirEntryMap.end(); ci++)
     {
         DirectoryEntry &di = *(ci->second);
