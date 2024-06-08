$NetBSD: patch-src_osd_modules_input_input__sdl.cpp,v 1.4 2024/06/08 16:06:26 wiz Exp $

Fix "lround is not a member of std::" on NetBSD.
https://github.com/mamedev/mame/issues/12458

--- src/osd/modules/input/input_sdl.cpp.orig	2024-05-29 17:42:54.000000000 +0000
+++ src/osd/modules/input/input_sdl.cpp
@@ -31,6 +31,7 @@
 #include <SDL2/SDL.h>
 
 #include <algorithm>
+#include <cmath>
 #include <cctype>
 #include <chrono>
 #include <cstddef>
