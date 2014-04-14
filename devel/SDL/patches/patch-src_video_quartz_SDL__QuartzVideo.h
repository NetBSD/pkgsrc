$NetBSD: patch-src_video_quartz_SDL__QuartzVideo.h,v 1.1 2014/04/14 19:27:46 adam Exp $

Fix building on newer OS X.

--- src/video/quartz/SDL_QuartzVideo.h.orig	2014-04-14 07:38:30.000000000 +0000
+++ src/video/quartz/SDL_QuartzVideo.h
@@ -91,7 +91,9 @@ typedef struct SDL_PrivateVideoData {
     CGDirectDisplayID  display;            /* 0 == main display (only support single display) */
     const void         *mode;              /* current mode of the display */
     const void         *save_mode;         /* original mode of the display */
+#if (MAC_OS_X_VERSION_MIN_REQUIRED < 1070)
     CGDirectPaletteRef palette;            /* palette of an 8-bit display */
+#endif
     NSOpenGLContext    *gl_context;        /* OpenGL rendering context */
     NSGraphicsContext  *nsgfx_context;     /* Cocoa graphics context */
     Uint32             width, height, bpp; /* frequently used data about the display */
