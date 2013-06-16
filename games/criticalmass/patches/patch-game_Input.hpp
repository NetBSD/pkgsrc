$NetBSD: patch-game_Input.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/Input.hpp.orig	2013-06-15 10:08:05.000000000 +0000
+++ game/Input.hpp
@@ -104,7 +104,7 @@ private:
     CallbackManager _callbackManager;
     Keys _keys;
 
-    hash_map< Trigger, Callback*, hash<Trigger>, equal_to<Trigger> > _callbackMap;
+    hash_map< Trigger, Callback*, HASH_NAMESPACE::hash<Trigger>, equal_to<Trigger> > _callbackMap;
 
     //stuff for mouse smoothing
     float _memoryDX;
