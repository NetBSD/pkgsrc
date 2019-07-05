$NetBSD: patch-source_src_rendercubes.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/rendercubes.cpp.orig	2013-10-22 18:57:16.000000000 +0000
+++ source/src/rendercubes.cpp
@@ -202,9 +202,9 @@ void render_flat(int wtex, int x, int y,
     else        // continue strip
     {
         int lighterr = lighterror*2;
-        if((abs(ol1r-l3->r)<lighterr && abs(ol2r-l4->r)<lighterr        // skip vertices if light values are close enough
-        &&  abs(ol1g-l3->g)<lighterr && abs(ol2g-l4->g)<lighterr
-        &&  abs(ol1b-l3->b)<lighterr && abs(ol2b-l4->b)<lighterr) || !wtex)
+        if((iabs(ol1r-l3->r)<lighterr && iabs(ol2r-l4->r)<lighterr        // skip vertices if light values are close enough
+        &&  iabs(ol1g-l3->g)<lighterr && iabs(ol2g-l4->g)<lighterr
+        &&  iabs(ol1b-l3->b)<lighterr && iabs(ol2b-l4->b)<lighterr) || !wtex)
         {
             verts.setsize(verts.length()-2);
             nquads--;
@@ -361,7 +361,7 @@ void render_square(int wtex, float floor
     {
         int lighterr = lighterror*2;
         if((!hf && !ohf)
-        && ((abs(ol1r-l2->r)<lighterr && abs(ol1g-l2->g)<lighterr && abs(ol1b-l2->b)<lighterr) || !wtex))       // skip vertices if light values are close enough
+        && ((iabs(ol1r-l2->r)<lighterr && iabs(ol1g-l2->g)<lighterr && iabs(ol1b-l2->b)<lighterr) || !wtex))       // skip vertices if light values are close enough
         {
             verts.setsize(verts.length()-2);
             nquads--;
