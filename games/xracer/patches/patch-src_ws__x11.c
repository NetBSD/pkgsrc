$NetBSD: patch-src_ws__x11.c,v 1.1 2016/04/04 17:33:42 khorben Exp $

Avoid references to obsolete GLUT internals

--- src/ws_x11.c.orig	2016-04-04 07:44:51.000000000 +0000
+++ src/ws_x11.c
@@ -28,6 +28,7 @@
 #include "xracer-ws.h"
 #include "xracer-log.h"
 
+#if 0
 /* X11- and GLUT-specific hack to warp and grab the pointer into the window. */
 struct GLUTwindow
 {
@@ -39,33 +40,43 @@ extern Display *__glutDisplay;
 
 extern Window __glutRoot;
 extern struct GLUTwindow *__glutCurrentWindow;
+#endif
 
 void
 xrWsWarpPointer ()
 {
+#if 0
   Window window = __glutCurrentWindow->win;
 
   XWarpPointer(__glutDisplay, 0, window, 0, 0, 0, 0, xrWidth/2, xrHeight/2);
+#else
+  glutWarpPointer(xrWidth/2, xrHeight/2);
+#endif
 }
 
 /* Grab the pointer. */
 void
 xrWsGrabPointer ()
 {
+#if 0
   Window window = __glutCurrentWindow->win;
 
   if (XGrabPointer(__glutDisplay, window, True,
         ButtonReleaseMask | ButtonPressMask,
         GrabModeAsync, GrabModeAsync,
         window, None, CurrentTime) != GrabSuccess)
+#else
     xrLog (LOG_ERROR, "pointer grab failed");
+#endif
 }
 
 /* Flush out the event queue. */
 void
 xrWsFlushEventQueue ()
 {
+#if 0
   XSync(__glutDisplay, False);
+#endif
 }
 
 /* X11 hack to give window a class, so WindowManagers can interact with it
@@ -75,10 +86,12 @@ xrWsFlushEventQueue ()
 void
 xrWsFixWindowClass ()
 {
+#if 0
    XClassHint classhint;
    Window window = __glutCurrentWindow->win;
 
    classhint.res_name = (char *) "xracer";
    classhint.res_class = (char *) "XRacer";
    XSetClassHint (__glutDisplay, window, &classhint);
+#endif
 }
