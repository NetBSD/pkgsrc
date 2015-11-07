$NetBSD: patch-libfsemu_src_emu_audio__openal.c,v 1.1 2015/11/07 13:30:21 adam Exp $

Fix OpenAL support on Darwin.

--- libfsemu/src/emu/audio_openal.c.orig	2015-11-07 13:27:07.000000000 +0000
+++ libfsemu/src/emu/audio_openal.c
@@ -14,11 +14,15 @@
 
 #ifdef HAVE_AL_AL_H
 #include <AL/al.h>
+#elif defined(__APPLE__)
+#include <OpenAL/al.h>
 #else
 #include <al.h>
 #endif
 #ifdef HAVE_AL_ALC_H
 #include <AL/alc.h>
+#elif defined(__APPLE__)
+#include <OpenAL/alc.h>
 #else
 #include <alc.h>
 #endif
