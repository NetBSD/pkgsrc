$NetBSD: patch-game_FontManager.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/FontManager.cpp.orig	2013-06-15 10:08:29.000000000 +0000
+++ game/FontManager.cpp
@@ -28,7 +28,7 @@ FontManager::~FontManager()
 void FontManager::reload( void)
 {
     XTRACE();
-    hash_map< const string, GLBitmapFont*, hash<const string> >::const_iterator ci;
+    hash_map< const string, GLBitmapFont*, HASH_NAMESPACE::hash<const string> >::const_iterator ci;
     for( ci=_resourceMap.begin(); ci!=_resourceMap.end(); ci++)
     {
 	GLBitmapFont *font = ci->second;
