$NetBSD: patch-src_libgame_system.c,v 1.3 2018/07/13 17:27:32 adam Exp $

InitJoystick will be called more than once, so reset the state
variable 'joystick' only if there's no joystick available (yet).

--- src/libgame/system.c.orig	2018-04-10 19:44:08.000000000 +0000
+++ src/libgame/system.c
@@ -1744,8 +1744,10 @@ void InitJoysticks()
 
   /* always start with reliable default values */
   joystick.status = JOYSTICK_NOT_AVAILABLE;
+  if (joystick.status == JOYSTICK_NOT_AVAILABLE) {
   for (i = 0; i < MAX_PLAYERS; i++)
     joystick.nr[i] = -1;		/* no joystick configured */
+  }
 
   SDLInitJoysticks();
 }
