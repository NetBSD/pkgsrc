$NetBSD: patch-lib-src_enigma-core_ecl_font.cc,v 1.1 2011/02/23 10:20:26 adam Exp $

Fix comparison.

--- lib-src/enigma-core/ecl_font.cc.orig	2011-02-22 13:18:46.000000000 +0000
+++ lib-src/enigma-core/ecl_font.cc
@@ -114,7 +114,7 @@ BitmapFont::BitmapFont(Surface *s, const
         char_rects[c].y = 0;
         char_rects[c].h = s->height();
         advance[c] = adv;
-        if (adv = 0)
+        if (adv == 0)
             std::cout << "BitFont 0\n";
     }
 }
