$NetBSD: patch-src_map.cpp,v 1.1 2020/08/27 12:33:19 joerg Exp $

--- src/map.cpp.orig	2020-08-26 12:02:32.310434861 +0000
+++ src/map.cpp
@@ -115,14 +115,14 @@ int MapCoords::getRelativeDirection(cons
     if (map && map->border_behavior == Map::BORDER_WRAP) {
         MapCoords me = *this;            
         
-        if (abs(me.x - c.x) > abs(me.x + map->width - c.x))
+        if (abs(me.x - c.x) > abs(me.x + int(map->width - c.x)))
             me.x += map->width;
-        else if (abs(me.x - c.x) > abs(me.x - map->width - c.x))
+        else if (abs(me.x - c.x) > abs(int(me.x - map->width) - c.x))
             me.x -= map->width;
 
-        if (abs(me.y - c.y) > abs(me.y + map->width - c.y))
+        if (abs(me.y - c.y) > abs(me.y + int(map->width - c.y)))
             me.y += map->height;
-        else if (abs(me.y - c.y) > abs(me.y - map->width - c.y))
+        else if (abs(me.y - c.y) > abs(int(me.y - map->width) - c.y))
             me.y -= map->height;
 
         dx = me.x - c.x;
