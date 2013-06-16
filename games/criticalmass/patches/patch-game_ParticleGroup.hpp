$NetBSD: patch-game_ParticleGroup.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/ParticleGroup.hpp.orig	2013-06-15 10:04:38.000000000 +0000
+++ game/ParticleGroup.hpp
@@ -86,7 +86,7 @@ public:
 
     static void destroyParticleTypes( void)
     {
-	hash_map< const string, ParticleType*, hash<const string> >::const_iterator ci;
+	hash_map< const string, ParticleType*, HASH_NAMESPACE::hash<const string> >::const_iterator ci;
 	for( ci=_particleTypeMap.begin(); ci!=_particleTypeMap.end(); ci++)
 	{
 	    //don't delete hero!
@@ -104,7 +104,7 @@ private:
 
     //All Particle manager share the particleTypeMap
     static hash_map< 
-        const string, ParticleType*, hash<const string>, equal_to<const string> > _particleTypeMap;
+        const string, ParticleType*, HASH_NAMESPACE::hash<const string>, equal_to<const string> > _particleTypeMap;
 
     ParticleInfo *_particles;
 
