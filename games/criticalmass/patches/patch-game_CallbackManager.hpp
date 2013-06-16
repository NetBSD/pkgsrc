$NetBSD: patch-game_CallbackManager.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/CallbackManager.hpp.orig	2013-06-15 10:06:55.000000000 +0000
+++ game/CallbackManager.hpp
@@ -36,7 +36,7 @@ private:
     CallbackManager( const CallbackManager&);
     CallbackManager &operator=(const CallbackManager&);
 
-    hash_map< string, Callback*, hash<string>, equal_to<string> > _actionMap;
+    hash_map< string, Callback*, HASH_NAMESPACE::hash<string>, equal_to<string> > _actionMap;
 };
 
 #endif
