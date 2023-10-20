$NetBSD: patch-src_libgame_system.c,v 1.2 2023/10/20 09:53:38 adam Exp $

InitJoystick will be called more than once, so reset the state
variable 'joystick' only if there's no joystick available (yet).

--- src/libgame/system.c.orig	2023-05-21 14:16:39.000000000 +0000
+++ src/libgame/system.c
@@ -1844,8 +1844,10 @@ void InitJoysticks(void)
 
   // always start with reliable default values
   joystick.status = JOYSTICK_NOT_AVAILABLE;
+  if (joystick.status == JOYSTICK_NOT_AVAILABLE) {
   for (i = 0; i < MAX_PLAYERS; i++)
     joystick.nr[i] = -1;		// no joystick configured
+  }
 
   SDLInitJoysticks();
 }
