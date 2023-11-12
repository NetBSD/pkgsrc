$NetBSD: patch-src_audio_coreaudio_SDL__coreaudio.h,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/audio/coreaudio/SDL_coreaudio.h.orig	2014-03-16 02:31:44.000000000 +0000
+++ src/audio/coreaudio/SDL_coreaudio.h
@@ -31,7 +31,14 @@
 
 #if MACOSX_COREAUDIO
 #include <CoreAudio/CoreAudio.h>
+#if defined(__ALTIVEC__) && !defined(MAC_OS_X_VERSION_10_5)
+/* to cricumvent a bug in Mac OS X 10.4 SDK */
+#define vector __vector
 #include <CoreServices/CoreServices.h>
+#undef vector
+#else
+#include <CoreServices/CoreServices.h>
+#endif
 #else
 #include <AudioToolbox/AudioToolbox.h>
 #endif
