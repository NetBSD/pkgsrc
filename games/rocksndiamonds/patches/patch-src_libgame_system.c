$NetBSD: patch-src_libgame_system.c,v 1.4 2019/05/05 07:59:38 adam Exp $

InitJoystick will be called more than once, so reset the state
variable 'joystick' only if there's no joystick available (yet).

--- src/libgame/system.c.orig	2019-02-17 19:09:38.000000000 +0000
+++ src/libgame/system.c
@@ -1748,8 +1748,10 @@ void InitJoysticks(void)
 
   // always start with reliable default values
   joystick.status = JOYSTICK_NOT_AVAILABLE;
+  if (joystick.status == JOYSTICK_NOT_AVAILABLE) {
   for (i = 0; i < MAX_PLAYERS; i++)
     joystick.nr[i] = -1;		// no joystick configured
+  }
 
   SDLInitJoysticks();
 }
