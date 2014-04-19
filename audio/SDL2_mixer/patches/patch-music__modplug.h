$NetBSD: patch-music__modplug.h,v 1.1 2014/04/19 14:52:13 joerg Exp $

--- music_modplug.h.orig	2014-04-19 11:23:23.000000000 +0000
+++ music_modplug.h
@@ -21,7 +21,7 @@
 
 #ifdef MODPLUG_MUSIC
 
-#include "modplug.h"
+#include "libmodplug/modplug.h"
 #include "SDL_rwops.h"
 #include "SDL_audio.h"
 #include "SDL_mixer.h"
