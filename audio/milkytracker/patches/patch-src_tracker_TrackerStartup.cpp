$NetBSD: patch-src_tracker_TrackerStartup.cpp,v 1.2 2015/06/25 06:01:01 dholland Exp $

Taking the absolute value of the difference of two values doesn't work
if the difference is unsigned. Do something else semi-reasonable
instead for the case when the clock goes backwards.

--- src/tracker/TrackerStartUp.cpp.orig	2013-11-09 00:12:01.000000000 +0000
+++ src/tracker/TrackerStartUp.cpp
@@ -119,14 +119,16 @@ void Tracker::showSplash()
 	pp_int32 deltaT = 100;
 	while (shade <= 256.0f)
 	{
-		pp_int32 startTime = ::PPGetTickCount();
+		pp_uint32 startTime = ::PPGetTickCount();
 #if defined(__EXCLUDE_BIGLOGO__) || defined(__LOWRES__)
 		screen->paintSplash(LogoSmall::rawData, LogoSmall::width, LogoSmall::height, LogoSmall::width*4, 4, (int)shade); 		
 #else
 		screen->paintSplash(LogoBig::rawData, LogoBig::width, LogoBig::height, LogoBig::width*3, 3, (int)shade); 		
 #endif
 		shade+=deltaT * (1.0f/6.25f);
-		deltaT = abs(::PPGetTickCount() - startTime);
+		pp_uint32 nowTime = ::PPGetTickCount();
+		/* just in case the clock goes backwards */
+		deltaT = nowTime > startTime ? nowTime - startTime : 0;
 		if (!deltaT) deltaT++;
 	}
 #if defined(__EXCLUDE_BIGLOGO__) || defined(__LOWRES__)
@@ -150,14 +152,16 @@ void Tracker::hideSplash()
 	pp_int32 deltaT = 100;
 	while (shade >= 0.0f)
 	{
-		pp_int32 startTime = ::PPGetTickCount();
+		pp_uint32 startTime = ::PPGetTickCount();
 #if defined(__EXCLUDE_BIGLOGO__) || defined(__LOWRES__)
 		screen->paintSplash(LogoSmall::rawData, LogoSmall::width, LogoSmall::height, LogoSmall::width*4, 4, (int)shade); 		
 #else
 		screen->paintSplash(LogoBig::rawData, LogoBig::width, LogoBig::height, LogoBig::width*3, 3, (int)shade); 		
 #endif
 		shade-=deltaT * (1.0f/6.25f);
-		deltaT = abs(::PPGetTickCount() - startTime);
+		pp_uint32 nowTime = ::PPGetTickCount();
+		/* just in case the clock goes backwards */
+		deltaT = nowTime > startTime ? nowTime - startTime : 0;
 		if (!deltaT) deltaT++;
 	}
 	screen->clear(); 	
