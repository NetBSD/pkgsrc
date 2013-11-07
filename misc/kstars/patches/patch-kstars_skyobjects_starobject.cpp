$NetBSD: patch-kstars_skyobjects_starobject.cpp,v 1.1 2013/11/07 12:35:42 markd Exp $

--- kstars/skyobjects/starobject.cpp.orig	2013-08-28 17:03:16.000000000 +0000
+++ kstars/skyobjects/starobject.cpp
@@ -282,7 +282,7 @@ void StarObject::getIndexCoords( KSNumbe
 
     pmms = pmMagnitudeSquared();
 
-    if( isnan( pmms ) || pmms * num->julianMillenia() * num->julianMillenia() < 1. ) {
+    if( std::isnan( pmms ) || pmms * num->julianMillenia() * num->julianMillenia() < 1. ) {
         // Ignore corrections
         *ra = ra0().Degrees();
         *dec = dec0().Degrees();
