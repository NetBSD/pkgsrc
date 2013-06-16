$NetBSD: patch-game_ModelManager.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/ModelManager.hpp.orig	2013-06-15 10:08:00.000000000 +0000
+++ game/ModelManager.hpp
@@ -54,7 +54,7 @@ private:
 
     Model *load( const string &model);
 
-    hash_map< string, Model*, hash<string>, equal_to<string> > _modelMap;
+    hash_map< string, Model*, HASH_NAMESPACE::hash<string>, equal_to<string> > _modelMap;
 };
 
 typedef Singleton<ModelManager> ModelManagerS;
