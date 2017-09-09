$NetBSD: patch-src_libgame_system.c,v 1.1 2017/09/09 07:10:34 adam Exp $

InitJoystick will be called more than once, so reset the state
variable 'joystick' only if there's no joystick available (yet).

--- src/libgame/system.c.orig	2017-03-15 20:15:06.000000000 +0000
+++ src/libgame/system.c
@@ -1603,9 +1603,10 @@ void InitJoysticks()
 #endif
 
   /* always start with reliable default values */
-  joystick.status = JOYSTICK_NOT_AVAILABLE;
+  if (joystick.status == JOYSTICK_NOT_AVAILABLE) {
   for (i = 0; i < MAX_PLAYERS; i++)
     joystick.fd[i] = -1;		/* joystick device closed */
+  }
 
   SDLInitJoysticks();
 }
