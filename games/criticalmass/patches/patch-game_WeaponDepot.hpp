$NetBSD: patch-game_WeaponDepot.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/WeaponDepot.hpp.orig	2013-06-15 10:08:23.000000000 +0000
+++ game/WeaponDepot.hpp
@@ -37,7 +37,7 @@ private:
 
     void addWeapon( Weapon *weap);
 
-    hash_map< string, Weapon*, hash<string>, equal_to<string> > _weaponMap;
+    hash_map< string, Weapon*, HASH_NAMESPACE::hash<string>, equal_to<string> > _weaponMap;
 };
 
 typedef Singleton<WeaponDepot> WeaponDepotS;
