$NetBSD: patch-lib_colorchanger__crossed__bowl.hpp,v 1.1 2012/12/19 11:25:31 ryoon Exp $

* Fix build with gcc 4.7

--- lib/colorchanger_crossed_bowl.hpp.orig	2011-11-22 20:27:03.000000000 +0000
+++ lib/colorchanger_crossed_bowl.hpp
@@ -79,7 +79,7 @@ public:
 
         int dx = x-width/2;
         int dy = y-height/2;
-        int diag = sqrt(2)*ccdb_size/2;
+        int diag = sqrt((double) 2)*ccdb_size/2;
 
         int dxs, dys;
         if (dx > 0) 
@@ -91,7 +91,7 @@ public:
         else
             dys = dy + stripe_width;
 
-        float r = sqrt(SQR(dxs)+SQR(dys));
+        float r = sqrt((double) (SQR(dxs)+SQR(dys)));
 
         // hue
         if (r < s_radius) {
