$NetBSD: patch-3rdparty_bgfx_examples_common_font_font__manager.cpp,v 1.2 2019/10/17 13:55:45 wiz Exp $

Compatibility with freetype2-2.6.2.
https://github.com/bkaradzic/bgfx/pull/782

--- 3rdparty/bgfx/examples/common/font/font_manager.cpp.orig	2015-12-30 07:18:51.000000000 +0000
+++ 3rdparty/bgfx/examples/common/font/font_manager.cpp
@@ -17,7 +17,9 @@ BX_PRAGMA_DIAGNOSTIC_IGNORED_MSVC(4245) 
 #pragma push_macro("interface")
 #endif
 #undef interface
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
 #if BX_COMPILER_MSVC || BX_COMPILER_GCC >= 40300
 #pragma pop_macro("interface")
 #endif
