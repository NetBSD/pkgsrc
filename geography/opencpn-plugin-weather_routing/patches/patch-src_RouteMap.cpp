$NetBSD: patch-src_RouteMap.cpp,v 1.1 2016/06/16 16:03:55 bouyer Exp $

--- src/RouteMap.cpp.orig	2016-06-13 18:14:41.000000000 +0200
+++ src/RouteMap.cpp	2016-06-13 18:17:23.000000000 +0200
@@ -550,7 +550,7 @@
         VB = polar.Speed(H, VW);
 
     /* failed to determine speed.. */
-    if(isnan(B) || isnan(VB)) {
+    if(std::isnan(B) || std::isnan(VB)) {
         configuration.polar_failed = true;
         return false; //B = VB = 0;
     }
@@ -662,7 +662,7 @@
         B = W + H; /* rotated relative to true wind */
 
         /* test to avoid extra computations related to backtracking */
-        if(!isnan(bearing1)) {
+        if(!std::isnan(bearing1)) {
             double bearing3 = heading_resolve(B);
             if((bearing1 > bearing2 && bearing3 > bearing2 && bearing3 < bearing1) ||
                (bearing1 < bearing2 && (bearing3 > bearing2 || bearing3 < bearing1))) {
@@ -2092,7 +2092,7 @@
 
         /* did we tack thru the wind? apply penalty */
         bool tacked = false;
-        if(!isnan(dt) && p->parent_heading*H < 0 && fabs(p->parent_heading - H) < 180) {
+        if(!std::isnan(dt) && p->parent_heading*H < 0 && fabs(p->parent_heading - H) < 180) {
             tacked = true;
             dt += configuration.TackingTime;
 #if 0        
@@ -2101,7 +2101,7 @@
 #endif
         }
 
-        if(!isnan(dt) && dt < mindt) {
+        if(!std::isnan(dt) && dt < mindt) {
             mindt = dt;
             minH = H;
             endp = p;
