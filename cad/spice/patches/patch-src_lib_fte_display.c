$NetBSD: patch-src_lib_fte_display.c,v 1.1 2013/03/02 17:51:49 joerg Exp $

--- src/lib/fte/display.c.orig	1993-04-25 21:50:26.000000000 +0000
+++ src/lib/fte/display.c
@@ -22,10 +22,11 @@ extern int  X_Init(), X_NewViewport(), X
 
 #ifdef HAS_X11
 extern int  X11_Init(), X11_NewViewport(), X11_Close(), X11_Clear(),
-        X11_DrawLine(), X11_Arc(), X11_Text(), X11_DefineColor(),
+        X11_DrawLine(), X11_Text(), X11_DefineColor(),
         X11_DefineLinestyle(), X11_SetLinestyle(), X11_SetColor(),
-        X11_Update(),
-        X11_Input();
+        X11_Update();
+void X11_Arc(int x0, int y0, int radius, double theta1, double theta2);
+void X11_Input(REQUEST *request, RESPONSE *response);
 #endif
 
 #ifdef HAS_MFB
