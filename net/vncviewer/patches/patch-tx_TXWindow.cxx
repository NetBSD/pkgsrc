$NetBSD: patch-tx_TXWindow.cxx,v 1.1 2018/04/18 20:48:19 christos Exp $

Handle gcc widening warnings

--- tx/TXWindow.cxx.orig	2006-05-15 12:56:20.000000000 -0400
+++ tx/TXWindow.cxx	2018-04-18 16:43:55.686069773 -0400
@@ -90,8 +90,9 @@
   static char dotBits[] = { 0x06, 0x0f, 0x0f, 0x06};
   dot = XCreateBitmapFromData(dpy, DefaultRootWindow(dpy), dotBits,
                               dotSize, dotSize);
-  static char tickBits[] = { 0x80, 0xc0, 0xe2, 0x76, 0x3e, 0x1c, 0x08, 0x00};
-  tick = XCreateBitmapFromData(dpy, DefaultRootWindow(dpy), tickBits,
+  static unsigned char tickBits[] = {
+      0x80, 0xc0, 0xe2, 0x76, 0x3e, 0x1c, 0x08, 0x00};
+  tick = XCreateBitmapFromData(dpy, DefaultRootWindow(dpy), (char *)tickBits,
                                tickSize, tickSize);
   defaultWindowClass = rfb::strDup(defaultWindowClass_);
 }
