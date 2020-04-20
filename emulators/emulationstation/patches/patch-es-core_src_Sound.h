$NetBSD: patch-es-core_src_Sound.h,v 1.1 2020/04/20 00:35:23 joerg Exp $

--- es-core/src/Sound.h.orig	2020-04-19 17:26:02.882026668 +0000
+++ es-core/src/Sound.h
@@ -5,6 +5,7 @@
 #include "SDL_audio.h"
 #include <map>
 #include <memory>
+#include <string>
 
 class ThemeData;
 
