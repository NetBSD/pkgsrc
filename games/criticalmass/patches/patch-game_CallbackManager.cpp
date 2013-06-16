$NetBSD: patch-game_CallbackManager.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/CallbackManager.cpp.orig	2013-06-15 10:08:42.000000000 +0000
+++ game/CallbackManager.cpp
@@ -27,7 +27,7 @@ CallbackManager::~CallbackManager()
 {
     XTRACE();
 
-    hash_map< string, Callback*, hash<string> >::const_iterator ci;
+    hash_map< string, Callback*, HASH_NAMESPACE::hash<string> >::const_iterator ci;
     for( ci=_actionMap.begin(); ci!=_actionMap.end(); ci++)
     {
         delete ci->second;
