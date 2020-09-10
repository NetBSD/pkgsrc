$NetBSD: patch-src_burner_libretro_retro__common.h,v 1.2 2020/09/10 10:10:18 nia Exp $

Don't cast lvalues.

--- src/burner/libretro/retro_common.h.orig	2020-05-30 15:55:11.000000000 +0000
+++ src/burner/libretro/retro_common.h
@@ -7,7 +7,11 @@
 #include <vector>
 #include "burner.h"
 
+#ifndef __clang__
 #define SSTR( x ) static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
+#else
+#define SSTR( x ) ((( std::ostringstream() << std::dec << x ) ).str())
+#endif
 
 #define RETRO_GAME_TYPE_CV		1
 #define RETRO_GAME_TYPE_GG		2
