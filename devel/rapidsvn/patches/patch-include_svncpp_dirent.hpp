$NetBSD: patch-include_svncpp_dirent.hpp,v 1.1 2016/03/31 09:00:39 markd Exp $

Build with subversion 1.9
https://github.com/RapidSVN/RapidSVN/issues/6

--- include/svncpp/dirent.hpp.orig	2012-06-28 06:39:20.000000000 +0000
+++ include/svncpp/dirent.hpp
@@ -41,7 +41,7 @@ namespace svn
     /**
      * constructor for existing @a svn_dirent_t entries
      */
-    DirEntry(const char * name, svn_dirent_t * dirEntry);
+    DirEntry(const char * name, const svn_dirent_t * dirEntry);
 
     /**
      * copy constructor
@@ -91,3 +91,4 @@ namespace svn
  * eval: (load-file "../../rapidsvn-dev.el")
  * end:
  */
+
