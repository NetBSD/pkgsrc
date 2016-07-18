$NetBSD: patch-src_RouteMap.cpp,v 1.2 2016/07/18 14:23:46 bouyer Exp $

--- src/RouteMap.cpp.orig	2016-07-16 16:02:32.000000000 +0200
+++ src/RouteMap.cpp	2016-07-18 15:51:20.000000000 +0200
@@ -546,7 +546,7 @@
         VB = polar.Speed(H, VW);
 
     /* failed to determine speed.. */
-    if(isnan(B) || isnan(VB)) {
+    if(std::isnan(B) || std::isnan(VB)) {
         // when does this hit??
         printf("polar failed bad! %f %f %f %f\n", W, VW, B, VB);
         configuration.polar_failed = true;
@@ -662,7 +662,7 @@
         B = W + H; /* rotated relative to true wind */
 
         /* test to avoid extra computations related to backtracking */
-        if(!isnan(bearing1)) {
+        if(!std::isnan(bearing1)) {
             double bearing3 = heading_resolve(B);
             if((bearing1 > bearing2 && bearing3 > bearing2 && bearing3 < bearing1) ||
                (bearing1 < bearing2 && (bearing3 > bearing2 || bearing3 < bearing1))) {
@@ -2089,7 +2089,7 @@
 
         /* did we tack thru the wind? apply penalty */
         bool tacked = false;
-        if(!isnan(dt) && p->parent_heading*H < 0 && fabs(p->parent_heading - H) < 180) {
+        if(!std::isnan(dt) && p->parent_heading*H < 0 && fabs(p->parent_heading - H) < 180) {
             tacked = true;
             dt += configuration.TackingTime;
 #if 0        
@@ -2098,7 +2098,7 @@
 #endif
         }
 
-        if(!isnan(dt) && dt < mindt) {
+        if(!std::isnan(dt) && dt < mindt) {
             mindt = dt;
             minH = H;
             endp = p;
