$NetBSD: patch-ljfastraster.cpp,v 1.1 2015/04/26 13:28:23 joerg Exp $

--- ljfastraster.cpp.orig	2015-04-26 12:33:48.000000000 +0000
+++ ljfastraster.cpp
@@ -412,13 +412,13 @@ DRIVER_ERROR HeaderLJFastRaster::SendCAP
 //** this enumeration is for specifying the current color plane that is being
 //** sent via fast raster path.  Toucan ordering is YMCK
 
-typedef enum TonerColor
+typedef enum
 {
 	eYellow = 0,
 	eMagenta,
 	eCyan,
 	eK
-};
+} TonerColor;
 
 typedef enum
 {
