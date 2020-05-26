$NetBSD: patch-plugins_actor_G-Force_GForceCommon_WaveShape.cpp,v 1.1 2020/05/26 11:25:34 joerg Exp $

--- plugins/actor/G-Force/GForceCommon/WaveShape.cpp.orig	2005-01-17 18:45:25.000000000 +0000
+++ plugins/actor/G-Force/GForceCommon/WaveShape.cpp
@@ -204,7 +204,7 @@ void WaveShape::Draw( long inNumSteps, P
 	else {
 		w2Waves = inWave2 -> mNumWaves;
 		dialate = inMorphPct;
-		mShapeTrans = pow( dialate, SHAPE_MORPH_ALPHA );
+		mShapeTrans = pow( dialate, float(SHAPE_MORPH_ALPHA) );
 		SetupFrame( inWave2, mShapeTrans );
 		
 		if ( mNumWaves > w2Waves ) {
@@ -214,7 +214,7 @@ void WaveShape::Draw( long inNumSteps, P
 			maxWaves = w2Waves;
 		
 		// Set the wave scale factor to the wave leaving/arriving
-		dialate = 20.0 * pow( dialate, 4.0 ) + 1.0;
+		dialate = 20.0 * pow( dialate, 4.0f ) + 1.0;
 
 		// Calc the x and y scale factors for wave 2
 		xscaleW2 = xoff;
