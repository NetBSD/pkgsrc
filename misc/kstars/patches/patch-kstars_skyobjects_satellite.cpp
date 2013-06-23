$NetBSD: patch-kstars_skyobjects_satellite.cpp,v 1.1 2013/06/23 19:09:15 jperkin Exp $

Avoid "sun" conflict.

--- kstars/skyobjects/satellite.cpp.orig	2013-05-03 04:38:11.876302746 +0000
+++ kstars/skyobjects/satellite.cpp
@@ -58,6 +58,7 @@
 #define F       3.35281066474748e-3         // Flattening factor
 #define MFACTOR 7.292115e-5
 
+#undef sun
 
 Satellite::Satellite( const QString name, const QString line1, const QString line2 )
 {
