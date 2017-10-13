$NetBSD: patch-src_libgame_system.c,v 1.2 2017/10/13 16:08:35 adam Exp $

InitJoystick will be called more than once, so reset the state
variable 'joystick' only if there's no joystick available (yet).

--- src/libgame/system.c.orig	2017-09-12 20:17:10.000000000 +0000
+++ src/libgame/system.c
@@ -1630,8 +1630,10 @@ void InitJoysticks()
 
   /* always start with reliable default values */
   joystick.status = JOYSTICK_NOT_AVAILABLE;
+  if (joystick.status == JOYSTICK_NOT_AVAILABLE) {
   for (i = 0; i < MAX_PLAYERS; i++)
     joystick.nr[i] = -1;		/* no joystick configured */
+  }
 
   SDLInitJoysticks();
 }
