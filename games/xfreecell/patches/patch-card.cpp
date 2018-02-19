$NetBSD: patch-card.cpp,v 1.2 2018/02/19 09:51:48 he Exp $

--- card.cpp.orig	1999-03-27 13:36:28.000000000 +0000
+++ card.cpp
@@ -1,3 +1,4 @@
+#include <cstdlib>
 #include <cstdio>
 #include <math.h>
 #ifdef SHAPE
@@ -40,7 +41,7 @@ static Pixmap boundingMask;
 static Pixmap clipMask;
 #endif
 
-static char bitmap[bmWidth * (cardHeight - 2)];
+static unsigned char bitmap[bmWidth * (cardHeight - 2)];
 static MoveMode moveMode;
 
 Card::Card(Suit s, unsigned int v)
@@ -49,9 +50,9 @@ Card::Card(Suit s, unsigned int v)
 #ifdef SHAPE
   if (Option::roundCard() && !initialized) {
     //Shape
-    boundingMask = XCreateBitmapFromData(dpy, root(), boundingMask_bits, 
+    boundingMask = XCreateBitmapFromData(dpy, root(), (const char*)boundingMask_bits, 
 					 boundingMask_width, boundingMask_height);
-    clipMask = XCreateBitmapFromData(dpy, root(), clipMask_bits, clipMask_width, 
+    clipMask = XCreateBitmapFromData(dpy, root(), (const char*)clipMask_bits, clipMask_width, 
 				     clipMask_height);
 
     //Cursor
@@ -89,10 +90,10 @@ Card::Card(Suit s, unsigned int v)
   hilight = getColor(dpy, "lightskyblue4");
 
   _usualPixmap = 
-    XCreatePixmapFromBitmapData(dpy, gameWindow, bitmap, cardWidth - 2,
+    XCreatePixmapFromBitmapData(dpy, gameWindow, (char*)bitmap, cardWidth - 2,
 				cardHeight - 2, fore, back, DefaultDepth(dpy, DefaultScreen(dpy)));
   _hilightedPixmap = 
-    XCreatePixmapFromBitmapData(dpy, gameWindow, bitmap, cardWidth - 2,
+    XCreatePixmapFromBitmapData(dpy, gameWindow, (char*)bitmap, cardWidth - 2,
                                 cardHeight - 2, fore, hilight, DefaultDepth(dpy, DefaultScreen(dpy)));
 
   selectInput(ButtonPressMask | EnterWindowMask | LeaveWindowMask);
