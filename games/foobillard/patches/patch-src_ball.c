$NetBSD: patch-src_ball.c,v 1.1 2015/09/21 14:00:11 tnn Exp $

--- src/ball.c.orig	2004-02-23 01:09:01.000000000 +0000
+++ src/ball.c
@@ -1820,7 +1820,7 @@ void draw_balls( BallsType balls, myvec 
                 draw_ball(&balls.ball[i],cam_pos,cam_FOV,win_width,1);
             } else if( options_cuberef && cuberef_binds!=0 ){
                 glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, cuberef_binds[i]);
-#ifdef GL_VERTEX_PROGRAM_NV
+#if defined(GL_VERTEX_PROGRAM_NV) && defined(USE_BALL_FRESNEL)
                 {
                     myvec cam_pos2;
 //                    cam_pos2=vec_scale(vec_unit(vec_diff(cam_pos,balls.ball[i].r)),BALL_D/2.5);
