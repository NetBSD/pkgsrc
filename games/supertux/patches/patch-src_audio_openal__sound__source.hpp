$NetBSD: patch-src_audio_openal__sound__source.hpp,v 1.2 2026/03/31 10:47:13 adam Exp $

Fix build on Darwin.

--- src/audio/openal_sound_source.hpp.orig	2026-03-15 05:38:51.000000000 +0000
+++ src/audio/openal_sound_source.hpp
@@ -16,7 +16,7 @@
 
 #pragma once
 
-#include <al.h>
+#include <AL/al.h>
 
 #include "audio/sound_source.hpp"
 
