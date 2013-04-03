$NetBSD: patch-kstars_skyobjects_ksmoon.cpp,v 1.1 2013/04/03 10:52:03 markd Exp $

'isnan' was not declared in scope

--- kstars/skyobjects/ksmoon.cpp.orig	2013-03-01 06:45:57.000000000 +0000
+++ kstars/skyobjects/ksmoon.cpp
@@ -222,7 +222,7 @@ void KSMoon::findMagnitude(const KSNumbe
     // relevant data put into ksplanetbase.h) was taken from
     // SkyChart v3 Beta
     double phd = phase().Degrees();
-    if( isnan( phd ) ) // Avoid nanny phases.
+    if( std::isnan( phd ) ) // Avoid nanny phases.
         return;
     int p = floor( phd );
     if( p > 180 )
