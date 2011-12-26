$NetBSD: patch-src_video_wscons_SDL__wsconsvideo.c,v 1.2 2011/12/26 12:28:47 wiz Exp $

Fix tty device and color patterns for wscons driver on NetBSD.

--- src/video/wscons/SDL_wsconsvideo.c.orig	2009-10-12 23:07:14.000000000 +0000
+++ src/video/wscons/SDL_wsconsvideo.c
@@ -141,7 +141,13 @@ VideoBootStrap WSCONS_bootstrap = {
   WSCONS_CreateDevice
 };
 
+#ifdef __NetBSD__
+#define WSCONSDEV_FORMAT "/dev/ttyE%01x"
+#endif
+
+#ifdef __OpenBSD__
 #define WSCONSDEV_FORMAT "/dev/ttyC%01x"
+#endif
 
 int WSCONS_VideoInit(_THIS, SDL_PixelFormat *vformat)
 {
@@ -184,6 +190,11 @@ int WSCONS_VideoInit(_THIS, SDL_PixelFor
     return -1;
   }
   if (private->info.depth > 8) {
+#ifdef __NetBSD__
+    private->redMask = 0x0000ff;
+    private->greenMask = 0x00ff00;
+    private->blueMask = 0xff0000;
+#else
     if (wstype == WSDISPLAY_TYPE_SUN24 ||
 	wstype == WSDISPLAY_TYPE_SUNCG12 ||
 	wstype == WSDISPLAY_TYPE_SUNCG14 ||
@@ -202,6 +213,7 @@ int WSCONS_VideoInit(_THIS, SDL_PixelFor
       WSCONS_ReportError("Unknown video hardware");
       return -1;
     }
+#endif
   } else {
     WSCONS_ReportError("Displays with 8 bpp or less are not supported");
     return -1;
