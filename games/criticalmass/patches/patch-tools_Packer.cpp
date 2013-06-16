$NetBSD: patch-tools_Packer.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- tools/Packer.cpp.orig	2013-06-15 10:04:06.000000000 +0000
+++ tools/Packer.cpp
@@ -21,7 +21,7 @@ const char RPATH_SEPERATOR = '/';
 //OS dependent seperator
 const char PATH_SEPERATOR = '/';
 
-bool operator<( DirectoryEntry &de1, DirectoryEntry &de2)
+bool operator<( const DirectoryEntry &de1, const DirectoryEntry &de2)
 {
     return( de1.resourceName < de2.resourceName);
 }
