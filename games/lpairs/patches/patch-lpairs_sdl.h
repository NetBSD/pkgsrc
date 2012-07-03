$NetBSD: patch-lpairs_sdl.h,v 1.1 2012/07/03 18:42:58 joerg Exp $

--- lpairs/sdl.h.orig	2012-07-03 16:02:57.000000000 +0000
+++ lpairs/sdl.h
@@ -116,7 +116,7 @@ void init_sdl( int f );
 void quit_sdl();
 int  set_video_mode( int w, int h, int d, int f );
 void hardware_cap();
-inline void refresh_screen( int x, int y, int w, int h );
+void refresh_screen( int x, int y, int w, int h );
 void refresh_rects();
 void add_refresh_rect(int x, int y, int w, int h);
 void dim_screen(int steps, int delay, int trp);
