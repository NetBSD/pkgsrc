$NetBSD: patch-game_ParticleGroup.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/ParticleGroup.cpp.orig	2013-06-15 10:08:37.000000000 +0000
+++ game/ParticleGroup.cpp
@@ -17,7 +17,7 @@
 #include <ParticleGroup.hpp>
 #include <FindHash.hpp>
 
-hash_map< const string, ParticleType*, hash<const string>, equal_to<const string> > 
+hash_map< const string, ParticleType*, HASH_NAMESPACE::hash<const string>, equal_to<const string> > 
     ParticleGroup::_particleTypeMap;
 
 ParticleGroup::ParticleGroup( const string &groupName, int numParticles):
