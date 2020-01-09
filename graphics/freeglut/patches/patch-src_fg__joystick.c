$NetBSD: patch-src_fg__joystick.c,v 1.1 2020/01/09 23:34:57 nia Exp $

Resolve "undefined symbol fghJoystickRawRead" on SunOS

From OpenIndiana:
https://github.com/OpenIndiana/oi-userland/commit/ee89e22bb41ce7ac2a00065b85cf2c7f415543d2

--- src/fg_joystick.c.orig	2017-07-31 20:49:26.000000000 +0000
+++ src/fg_joystick.c
@@ -76,7 +76,7 @@ SFG_Joystick *fgJoystick [ MAX_NUM_JOYST
 /*
  * Read the raw joystick data
  */
-static void fghJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes )
+void fghJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes )
 {
     int i;
 
