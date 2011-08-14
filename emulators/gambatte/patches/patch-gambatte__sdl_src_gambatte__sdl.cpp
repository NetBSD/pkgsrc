$NetBSD: patch-gambatte__sdl_src_gambatte__sdl.cpp,v 1.1 2011/08/14 19:05:04 wiz Exp $

Fix build with gcc-4.5.

--- gambatte_sdl/src/gambatte_sdl.cpp.orig	2009-01-10 22:43:34.000000000 +0000
+++ gambatte_sdl/src/gambatte_sdl.cpp
@@ -21,6 +21,7 @@
 #include <resample/resamplerinfo.h>
 #include <rateest.h>
 #include <SDL.h>
+#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
