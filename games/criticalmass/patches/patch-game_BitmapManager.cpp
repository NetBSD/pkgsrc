$NetBSD: patch-game_BitmapManager.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/BitmapManager.cpp.orig	2013-06-15 10:07:54.000000000 +0000
+++ game/BitmapManager.cpp
@@ -29,7 +29,7 @@ BitmapManager::~BitmapManager()
 void BitmapManager::reload( void)
 {
     XTRACE();
-    hash_map< const string, GLBitmapCollection*, hash<const string> >::const_iterator ci;
+    hash_map< const string, GLBitmapCollection*, HASH_NAMESPACE::hash<const string> >::const_iterator ci;
     for( ci=_resourceMap.begin(); ci!=_resourceMap.end(); ci++)
     {
 	GLBitmapCollection *bitmap = ci->second;
