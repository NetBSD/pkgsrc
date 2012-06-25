$NetBSD: patch-krdc_vnc_rfbproto.c,v 1.1 2012/06/25 11:51:01 joerg Exp $

--- krdc/vnc/rfbproto.c.orig	2012-06-18 22:15:22.000000000 +0000
+++ krdc/vnc/rfbproto.c
@@ -636,7 +636,7 @@ HandleCursorPos(unsigned int x, unsigned
 void DrawCursorX11Thread(int x, int y) {
   int ox, oy, ow, oh, nx, ny, nw, nh;
   if (!pointerImages[0].set)
-    return True;
+    return ;
   imageIndex = 0;
 
   if (x >= si.framebufferWidth)
