$NetBSD: patch-src_burner_libretro_retro__common.h,v 1.1 2020/08/11 18:47:14 joerg Exp $

Don't cast lvalues.

--- src/burner/libretro/retro_common.h.orig	2020-08-10 22:37:10.415674566 +0000
+++ src/burner/libretro/retro_common.h
@@ -7,7 +7,7 @@
 #include <vector>
 #include "burner.h"
 
-#define SSTR( x ) static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
+#define SSTR( x ) ((( std::ostringstream() << std::dec << x ) ).str())
 
 #define RETRO_GAME_TYPE_CV		1
 #define RETRO_GAME_TYPE_GG		2
