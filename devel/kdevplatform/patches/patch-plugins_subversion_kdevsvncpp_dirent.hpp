$NetBSD: patch-plugins_subversion_kdevsvncpp_dirent.hpp,v 1.1 2015/08/29 02:29:53 markd Exp $

make subversion plugin compile with subversion 1.9.

--- plugins/subversion/kdevsvncpp/dirent.hpp.orig	2014-08-26 19:49:48.000000000 +0000
+++ plugins/subversion/kdevsvncpp/dirent.hpp
@@ -41,7 +41,7 @@ namespace svn
     /**
      * constructor for existing @a svn_dirent_t entries
      */
-    DirEntry(const char * name, svn_dirent_t * dirEntry);
+    DirEntry(const char * name, const svn_dirent_t * dirEntry);
 
     /**
      * copy constructor
