$NetBSD: patch-utils_ResourceManager.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- utils/ResourceManager.hpp.orig	2013-04-30 12:13:05.000000000 +0000
+++ utils/ResourceManager.hpp
@@ -71,7 +71,7 @@ private:
     string _openFilename;
     ifstream _infile;
     ziStream *_activeInput;
-    hash_map< const string, DirectoryEntry*, hash<const string>, equal_to<const string> > _dirEntryMap;
+    hash_map<const string, DirectoryEntry*, ::HASH_NAMESPACE::hash<const string>, equal_to<const string> > _dirEntryMap;
     string::size_type _baseLen;
 };
 
