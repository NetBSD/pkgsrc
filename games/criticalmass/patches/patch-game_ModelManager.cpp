$NetBSD: patch-game_ModelManager.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/ModelManager.cpp.orig	2013-06-15 10:08:34.000000000 +0000
+++ game/ModelManager.cpp
@@ -26,7 +26,7 @@ ModelManager::~ModelManager()
 {
     XTRACE();
 
-    hash_map< string, Model*, hash<string> >::const_iterator ci;
+    hash_map< string, Model*, HASH_NAMESPACE::hash<string> >::const_iterator ci;
     for( ci=_modelMap.begin(); ci!=_modelMap.end(); ci++)
     {
         delete ci->second;
@@ -39,7 +39,7 @@ void ModelManager::reload( void)
 {
     XTRACE();
 
-    hash_map< string, Model*, hash<string> >::const_iterator ci;
+    hash_map< string, Model*, HASH_NAMESPACE::hash<string> >::const_iterator ci;
     for( ci=_modelMap.begin(); ci!=_modelMap.end(); ci++)
     {
         ci->second->reload();
