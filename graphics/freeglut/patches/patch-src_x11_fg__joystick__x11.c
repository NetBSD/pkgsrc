$NetBSD: patch-src_x11_fg__joystick__x11.c,v 1.6 2023/11/09 09:59:49 nros Exp $

fghJoystickRawRead is now called fgJoystickRawRead
https://github.com/FreeGLUTProject/freeglut/commit/eb622d9862158bd088988758b175532563827e39
This caused linking problems in packages using freeglut
complaining that it can't find fghJoystickRawRead on Illumos/Solaris.
Filed upstream:
https://github.com/FreeGLUTProject/freeglut/pull/150

--- src/x11/fg_joystick_x11.c.orig	2023-11-08 23:41:40.649322173 +0000
+++ src/x11/fg_joystick_x11.c
@@ -627,7 +627,7 @@ void fgPlatformJoystickOpen( SFG_Joystic
 
     do
     {
-        fghJoystickRawRead( joy, NULL, joy->center );
+        fgJoystickRawRead( joy, NULL, joy->center );
         counter++;
     } while( !joy->error &&
              counter < 100 &&
