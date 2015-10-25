$NetBSD: patch-modules_video__output_sdl.c,v 1.1 2015/10/25 11:00:18 wiz Exp $

--- modules/video_output/sdl.c.orig	2014-11-16 18:57:59.000000000 +0000
+++ modules/video_output/sdl.c
@@ -41,10 +41,9 @@
 #include <SDL.h>
 
 #if !defined(_WIN32) && !defined(__OS2__)
-# ifdef X_DISPLAY_MISSING
-#  error Xlib required due to XInitThreads
-# endif
+# ifdef HAVE_X11_XLIB_H
 # include <vlc_xlib.h>
+# endif
 #endif
 
 /*****************************************************************************
