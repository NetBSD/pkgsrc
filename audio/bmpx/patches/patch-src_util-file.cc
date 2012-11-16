$NetBSD: patch-src_util-file.cc,v 1.1 2012/11/16 20:05:35 joerg Exp $

--- src/util-file.cc.orig	2012-11-16 14:36:30.000000000 +0000
+++ src/util-file.cc
@@ -270,12 +270,12 @@ namespace Bmp
         if (!Audio::typefind (*i, type))
           return false;
 
-        Library::TaglibPluginsMap::const_iterator i (plugins.find (type));
+        Library::TaglibPluginsMap::const_iterator i2 (plugins.find (type));
 
-        if (i == plugins.end())
+        if (i2 == plugins.end())
           return false;
 
-        if (!i->second->set)
+        if (!i2->second->set)
           return false;
       }
       return true;
