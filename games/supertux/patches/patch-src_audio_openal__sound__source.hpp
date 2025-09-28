$NetBSD: patch-src_audio_openal__sound__source.hpp,v 1.1 2025/09/28 15:58:14 adam Exp $

Fix build on Darwin.

--- src/audio/openal_sound_source.hpp.orig	2025-09-28 15:35:30.674258557 +0000
+++ src/audio/openal_sound_source.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_SUPERTUX_AUDIO_OPENAL_SOUND_SOURCE_HPP
 #define HEADER_SUPERTUX_AUDIO_OPENAL_SOUND_SOURCE_HPP
 
-#include <al.h>
+#include <AL/al.h>
 
 #include "audio/sound_source.hpp"
 
