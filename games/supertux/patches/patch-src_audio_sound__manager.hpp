$NetBSD: patch-src_audio_sound__manager.hpp,v 1.1 2025/09/28 15:58:14 adam Exp $

Fix build on Darwin.

--- src/audio/sound_manager.hpp.orig	2025-09-28 15:34:52.973835904 +0000
+++ src/audio/sound_manager.hpp
@@ -22,8 +22,8 @@
 #include <string>
 #include <vector>
 
-#include <al.h>
-#include <alc.h>
+#include <AL/al.h>
+#include <AL/alc.h>
 
 #include "math/vector.hpp"
 #include "util/currenton.hpp"
