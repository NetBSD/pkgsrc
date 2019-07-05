$NetBSD: patch-source_src_worldrender.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/worldrender.cpp.orig	2013-10-09 08:27:37.000000000 +0000
+++ source/src/worldrender.cpp
@@ -270,10 +270,10 @@ void distlod(int &low, int &high, int an
 void render_world(float vx, float vy, float vh, float changelod, int yaw, int pitch, float fov, float fovy, int w, int h)
 {
     loopi(LARGEST_FACTOR) stats[i] = 0;
-    min_lod = minimap || (player1->isspectating() && player1->spectatemode == SM_OVERVIEW) ? MAX_LOD : MIN_LOD+abs(pitch)/12;
+    min_lod = minimap || (player1->isspectating() && player1->spectatemode == SM_OVERVIEW) ? MAX_LOD : MIN_LOD+iabs(pitch)/12;
     yaw = 360-yaw;
     float widef = fov/75.0f;
-    int cdist = abs(yaw%90-45);
+    int cdist = iabs(yaw%90-45);
     if(cdist<7)    // hack to avoid popup at high fovs at 45 yaw
     {
         min_lod = max(min_lod, (int)(MIN_LOD+(10-cdist)/1.0f*widef)); // less if lod worked better
