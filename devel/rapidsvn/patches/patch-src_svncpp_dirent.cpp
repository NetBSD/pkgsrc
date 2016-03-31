$NetBSD: patch-src_svncpp_dirent.cpp,v 1.1 2016/03/31 09:00:39 markd Exp $

Build with subversion 1.9 
https://github.com/RapidSVN/RapidSVN/issues/6 

--- src/svncpp/dirent.cpp.orig	2012-06-28 06:39:33.000000000 +0000
+++ src/svncpp/dirent.cpp
@@ -47,7 +47,7 @@ public:
     {
     }
 
-    Data(const char * _name, svn_dirent_t * dirEntry)
+    Data(const char * _name, const svn_dirent_t * dirEntry)
         : name(_name), kind(dirEntry->kind), size(dirEntry->size),
         hasProps(dirEntry->has_props != 0),
         createdRev(dirEntry->created_rev), time(dirEntry->time)
@@ -78,7 +78,7 @@ public:
   {
   }
 
-  DirEntry::DirEntry(const char * name, svn_dirent_t * DirEntry)
+  DirEntry::DirEntry(const char * name, const svn_dirent_t * DirEntry)
       : m(new Data(name, DirEntry))
   {
   }
