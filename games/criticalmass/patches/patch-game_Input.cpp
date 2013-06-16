$NetBSD: patch-game_Input.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/Input.cpp.orig	2013-06-15 10:08:31.000000000 +0000
+++ game/Input.cpp
@@ -260,7 +260,7 @@ void Input::save( ofstream &outfile)
     XTRACE();
     outfile << "# --- Binding section --- " << endl;
 
-    hash_map< Trigger, Callback*, hash<Trigger> >::const_iterator ci;
+    hash_map< Trigger, Callback*, HASH_NAMESPACE::hash<Trigger> >::const_iterator ci;
     for( ci=_callbackMap.begin(); ci!=_callbackMap.end(); ci++)
     {
         outfile << "bind " 
