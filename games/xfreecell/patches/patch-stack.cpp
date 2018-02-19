$NetBSD: patch-stack.cpp,v 1.1 2018/02/19 09:51:48 he Exp $

--- stack.cpp.orig	1999-03-21 16:48:40.000000000 +0000
+++ stack.cpp
@@ -219,16 +219,16 @@ void SingleStack::dispatchEvent(const XE
 static Pixmap clipMask = 0;
 static Pixmap boundingMask = 0;
 static bool initialized = false;
-static char bitmap[bmWidth * (cardHeight - 2)];
+static unsigned char bitmap[bmWidth * (cardHeight - 2)];
 
 DoneStack::DoneStack(int x_ini, int y_ini, Suit s)
   : Stack(x_ini, y_ini)
 {
 #ifdef SHAPE
   if (Option::roundCard() && !initialized) {
-    boundingMask = XCreateBitmapFromData(dpy, RootWindow(dpy, 0),  boundingMask_bits,
+    boundingMask = XCreateBitmapFromData(dpy, RootWindow(dpy, 0),  (const char*)boundingMask_bits,
                                          boundingMask_width, boundingMask_height);
-    clipMask = XCreateBitmapFromData(dpy, RootWindow(dpy, 0), clipMask_bits, clipMask_width,
+    clipMask = XCreateBitmapFromData(dpy, RootWindow(dpy, 0), (const char*)clipMask_bits, clipMask_width,
 				     clipMask_height);
     initialized = true;
   }
@@ -247,7 +247,7 @@ DoneStack::DoneStack(int x_ini, int y_in
   back = WhitePixel(dpy, 0);
   makeOneSymbolBitmap(s, bitmap);
 
-  bgpixmap = XCreatePixmapFromBitmapData(dpy, gameWindow, bitmap, cardWidth - 2,
+  bgpixmap = XCreatePixmapFromBitmapData(dpy, gameWindow, (char*)bitmap, cardWidth - 2,
 					 cardHeight - 2, fore, back, DefaultDepth(dpy, DefaultScreen(dpy)));
   resize(cardWidth, cardHeight);
   backgroundPixmap(bgpixmap);
