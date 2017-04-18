$NetBSD: patch-src_RouteMapOverlay.cpp,v 1.1 2017/04/18 16:54:35 bouyer Exp $
--- src/RouteMapOverlay.cpp.orig	2017-04-14 13:36:07.000000000 +0200
+++ src/RouteMapOverlay.cpp	2017-04-14 13:36:23.000000000 +0200
@@ -1186,7 +1186,7 @@
         }
         Unlock();
 
-        if(isinf(mindt))
+        if(std::isinf(mindt))
             goto not_able_to_propagate;
 
         destination_position = new Position(configuration.EndLat, configuration.EndLon,
