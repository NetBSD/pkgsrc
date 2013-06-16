$NetBSD: patch-game_SampleManager.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/SampleManager.cpp.orig	2013-06-15 10:07:57.000000000 +0000
+++ game/SampleManager.cpp
@@ -30,7 +30,7 @@ SampleManager::~SampleManager()
     //need to override base destructor behaviour, since we need
     //to Mix_FreeChunk not delete.
     
-    hash_map< const string, Mix_Chunk*, hash<const string> >::const_iterator ci;
+    hash_map< const string, Mix_Chunk*, HASH_NAMESPACE::hash<const string> >::const_iterator ci;
     for( ci=_resourceMap.begin(); ci!=_resourceMap.end(); ci++)
     {
 	Mix_Chunk *res = ci->second;
