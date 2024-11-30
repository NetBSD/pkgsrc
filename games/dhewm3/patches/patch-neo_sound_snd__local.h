$NetBSD: patch-neo_sound_snd__local.h,v 1.1 2024/11/30 23:02:05 wiz Exp $

Fix build with openal-soft-1.24.
https://github.com/dhewm/dhewm3/issues/633#issuecomment-2509399667

--- neo/sound/snd_local.h.orig	2024-11-30 22:29:45.302155237 +0000
+++ neo/sound/snd_local.h
@@ -34,6 +34,7 @@ If you have questions concerning this li
 // because the implemenations are in openal_stub.cpp
 // this is ensured by defining AL_LIBTYPE_STATIC before including the AL headers
 #define AL_LIBTYPE_STATIC
+#define AL_DISABLE_NOEXCEPT
 #endif
 
 #include <AL/al.h>
