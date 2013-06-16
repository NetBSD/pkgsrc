$NetBSD: patch-game_WeaponDepot.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/WeaponDepot.cpp.orig	2013-06-15 10:08:40.000000000 +0000
+++ game/WeaponDepot.cpp
@@ -32,7 +32,7 @@ WeaponDepot::~WeaponDepot()
 {
     XTRACE();
 
-    hash_map< string, Weapon*, hash<string> >::const_iterator ci;
+    hash_map< string, Weapon*, HASH_NAMESPACE::hash<string> >::const_iterator ci;
     for( ci=_weaponMap.begin(); ci!=_weaponMap.end(); ci++)
     {
         delete ci->second;
