$NetBSD: patch-plugins_subversion_kdevsvncpp_dirent.cpp,v 1.1 2015/08/29 02:29:53 markd Exp $

make subversion plugin compile with subversion 1.9.

--- plugins/subversion/kdevsvncpp/dirent.cpp.orig	2014-08-26 19:49:48.000000000 +0000
+++ plugins/subversion/kdevsvncpp/dirent.cpp
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
