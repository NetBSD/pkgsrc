$NetBSD: patch-src_video_wscons_SDL__wsconsvideo.c,v 1.5 2015/05/31 09:17:53 nat Exp $

#Allow video to initialize even if there is no keyboard and mouse.
--- src/video/wscons/SDL_wsconsvideo.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/wscons/SDL_wsconsvideo.c
@@ -141,12 +141,18 @@ VideoBootStrap WSCONS_bootstrap = {
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
   char devnamebuf[30];
-  char *devname;
+  char *devname, *mouse_devname;
   char *rotation;
   int wstype;
   int wsmode = WSDISPLAYIO_MODE_DUMBFB;
@@ -166,11 +172,23 @@ int WSCONS_VideoInit(_THIS, SDL_PixelFor
     devname = devnamebuf;
   }
 
+  mouse_devname = SDL_getenv("SDL_WSMOUSEDEV");
+  if (mouse_devname == NULL) {
+    mouse_devname = "/dev/wsmouse";
+  }
+
   private->fd = open(devname, O_RDWR | O_NONBLOCK, 0);
   if (private->fd == -1) {
     WSCONS_ReportError("open %s: %s", devname, strerror(errno));
     return -1;
   }
+
+  private->mouseFd = open(mouse_devname, O_RDWR | O_NONBLOCK, 0);
+  if (private->mouseFd == -1) {
+    WSCONS_ReportError("open %s: %s", mouse_devname, strerror(errno));
+    return -1;
+  }
+
   if (ioctl(private->fd, WSDISPLAYIO_GINFO, &private->info) == -1) {
     WSCONS_ReportError("ioctl WSDISPLAY_GINFO: %s", strerror(errno));
     return -1;
@@ -184,6 +202,11 @@ int WSCONS_VideoInit(_THIS, SDL_PixelFor
     return -1;
   }
   if (private->info.depth > 8) {
+#ifdef __NetBSD__
+    private->greenMask = 0x00ff00;
+    private->blueMask = 0x0000ff;
+    private->redMask = 0xff0000;
+#else
     if (wstype == WSDISPLAY_TYPE_SUN24 ||
 	wstype == WSDISPLAY_TYPE_SUNCG12 ||
 	wstype == WSDISPLAY_TYPE_SUNCG14 ||
@@ -202,6 +225,7 @@ int WSCONS_VideoInit(_THIS, SDL_PixelFor
       WSCONS_ReportError("Unknown video hardware");
       return -1;
     }
+#endif
   } else {
     WSCONS_ReportError("Displays with 8 bpp or less are not supported");
     return -1;
@@ -323,9 +347,8 @@ int WSCONS_VideoInit(_THIS, SDL_PixelFor
   vformat->BitsPerPixel = private->info.depth;
   vformat->BytesPerPixel = private->info.depth / 8;
   
-  if (WSCONS_InitKeyboard(this) == -1) {
-    return -1;
-  }
+  WSCONS_InitKeyboard(this);
+  WSCONS_InitMouse(this);
   
   return 0;
 }
@@ -601,7 +624,12 @@ void WSCONS_VideoQuit(_THIS)
   }
 
   WSCONS_ReleaseKeyboard(this);
+  WSCONS_ReleaseMouse(this);
 
+  if (private->mouseFd != -1) {
+    close(private->mouseFd);
+    private->mouseFd = -1;
+  }
   if (private->fd != -1) {
     close(private->fd);
     private->fd = -1;
