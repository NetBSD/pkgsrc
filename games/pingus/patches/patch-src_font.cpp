$NetBSD: patch-src_font.cpp,v 1.1 2012/11/23 12:35:01 joerg Exp $

--- src/font.cpp.orig	2012-11-22 20:41:19.000000000 +0000
+++ src/font.cpp
@@ -198,7 +198,7 @@ public:
             SDL_Rect& srcrect = chrs[static_cast<unsigned char>(text[i])];
             if (srcrect.w != 0 && srcrect.h != 0)
               {
-		SDL_Rect dstrect = { int(dstx), int(dsty), 0, 0 };
+		SDL_Rect dstrect = { static_cast<Sint16>(dstx), static_cast<Sint16>(dsty), 0, 0 };
                 SDL_BlitSurface(surface, &srcrect, target, &dstrect);
                 dstx += srcrect.w + char_spacing;
               }
