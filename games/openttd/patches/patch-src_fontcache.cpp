$NetBSD: patch-src_fontcache.cpp,v 1.1 2014/12/11 22:10:04 joerg Exp $

bitmap.width and bitmap.rows are unsigned, so std::max needs unsigned 1 too.

--- src/fontcache.cpp.orig	2014-12-11 21:17:16.000000000 +0000
+++ src/fontcache.cpp
@@ -481,8 +481,8 @@ const Sprite *FreeTypeFontCache::GetGlyp
 	aa = (slot->bitmap.pixel_mode == FT_PIXEL_MODE_GRAY);
 
 	/* Add 1 pixel for the shadow on the medium font. Our sprite must be at least 1x1 pixel */
-	int width  = max(1, slot->bitmap.width + (this->fs == FS_NORMAL));
-	int height = max(1, slot->bitmap.rows  + (this->fs == FS_NORMAL));
+	int width  = max(1U, slot->bitmap.width + (this->fs == FS_NORMAL));
+	int height = max(1U, slot->bitmap.rows  + (this->fs == FS_NORMAL));
 
 	/* Limit glyph size to prevent overflows later on. */
 	if (width > 256 || height > 256) usererror("Font glyph is too large");
