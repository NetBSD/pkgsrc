$NetBSD: patch-source_src_bot_bot__waypoint.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/bot/bot_waypoint.cpp.orig	2013-11-10 18:50:03.000000000 +0000
+++ source/src/bot/bot_waypoint.cpp
@@ -1221,7 +1221,7 @@ void CWaypointClass::CalcCost(node_s *pN
                     flCost += (1.0f-flFraction)*0.5f;
                }
 
-               if ((abs(a) > 4) || (abs(b) > 4)) continue;
+               if ((iabs(a) > 4) || (iabs(b) > 4)) continue;
 
                vec from = to;
                to.z -= (JUMP_HEIGHT - 1.0f);
@@ -1249,7 +1249,7 @@ void CWaypointClass::CalcCost(node_s *pN
                     flCost += (1.0f-flFraction)*0.5f;
                }
 
-               if ((abs(a) > 4) || (abs(b) > 4)) continue;
+               if ((iabs(a) > 4) || (iabs(b) > 4)) continue;
 
                vec from = to;
                to.z -= (JUMP_HEIGHT - 1.0f);
@@ -1671,12 +1671,12 @@ node_s *CWaypointClass::GetNearestTrigge
 void CWaypointClass::GetNodeIndexes(const vec &v_origin, short *i, short *j)
 {
      // Function code by cheesy and PMB
-     //*i = abs((int)((int)(v_origin.x + (2*ssize)) / SECTOR_SIZE));
-     //*j = abs((int)((int)(v_origin.y + (2*ssize)) / SECTOR_SIZE));
+     //*i = iabs((int)((int)(v_origin.x + (2*ssize)) / SECTOR_SIZE));
+     //*j = iabs((int)((int)(v_origin.y + (2*ssize)) / SECTOR_SIZE));
      //*i = (int)((v_origin.x) / ssize * MAX_MAP_GRIDS);
      //*j = (int)((v_origin.y) / ssize * MAX_MAP_GRIDS);
-     *i = abs((int)((v_origin.x) / MAX_MAP_GRIDS));
-     *j = abs((int)((v_origin.y) / MAX_MAP_GRIDS));
+     *i = iabs((int)((v_origin.x) / MAX_MAP_GRIDS));
+     *j = iabs((int)((v_origin.y) / MAX_MAP_GRIDS));
 
      if (*i > MAX_MAP_GRIDS - 1)
           *i = MAX_MAP_GRIDS - 1;
