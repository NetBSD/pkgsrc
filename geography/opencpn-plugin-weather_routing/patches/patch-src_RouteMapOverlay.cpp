$NetBSD: patch-src_RouteMapOverlay.cpp,v 1.3 2018/08/27 16:19:22 bouyer Exp $

--- src/RouteMapOverlay.cpp.orig	2018-08-27 16:21:31.958800595 +0200
+++ src/RouteMapOverlay.cpp	2018-08-27 16:21:42.479225410 +0200
@@ -1448,7 +1448,7 @@
         }
         Unlock();
 
-        if(isinf(mindt)) {
+        if(std::isinf(mindt)) {
             goto not_able_to_propagate;
         }
         destination_position = new Position(configuration.EndLat, configuration.EndLon,
