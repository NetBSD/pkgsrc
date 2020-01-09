$NetBSD: patch-src_x11_fg__joystick__x11.c,v 1.4 2020/01/09 23:34:57 nia Exp $

Resolve "undefined symbol fghJoystickRawRead" on SunOS

From OpenIndiana:
https://github.com/OpenIndiana/oi-userland/commit/ee89e22bb41ce7ac2a00065b85cf2c7f415543d2

--- src/x11/fg_joystick_x11.c.orig	2019-09-11 13:24:28.000000000 +0000
+++ src/x11/fg_joystick_x11.c
@@ -40,6 +40,7 @@
 #endif
 
 #include <fcntl.h>
+void fghJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes );
 
 
 /* BSD defines from "jsBSD.cxx" around lines 42-270 */
