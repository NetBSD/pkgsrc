$NetBSD: patch-game_ParticleGroupManager.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/ParticleGroupManager.hpp.orig	2013-06-15 10:08:18.000000000 +0000
+++ game/ParticleGroupManager.hpp
@@ -47,7 +47,7 @@ private:
     ParticleGroupManager &operator=(const ParticleGroupManager&);
 
     hash_map< 
-        const string, ParticleGroup*, hash<const string>, equal_to<const string> > _particleGroupMap;
+        const string, ParticleGroup*, HASH_NAMESPACE::hash<const string>, equal_to<const string> > _particleGroupMap;
     list<ParticleGroup*> _particleGroupList;
 
     struct LinkedParticleGroup
