$NetBSD: patch-src_Music.cxx,v 1.1 2025/09/29 14:06:05 nia Exp $

Build fixes for modern clang; via FreeBSD Ports

--- src/Music.cxx.orig	2009-02-28 17:38:34.000000000 +0000
+++ src/Music.cxx
@@ -22,6 +22,7 @@
 #include <assert.h>
 #include <SDL_mixer.h>
 #include <stdexcept>
+#include <string>
 #include "Music.h"
 #include "System.h"
 
