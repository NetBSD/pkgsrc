$NetBSD: patch-source_src_rendertext.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/rendertext.cpp.orig	2013-10-22 18:57:16.000000000 +0000
+++ source/src/rendertext.cpp
@@ -330,7 +330,7 @@ static void text_color(char c, char *sta
         if(c=='r') c = stack[(sp > 0) ? --sp : sp]; // restore color
         else if(c == 'b') { if(allowblinkingtext && !ignoreblinkingbit) stack[sp] *= -1; } // blinking text - only if allowed
         else stack[sp] = c;
-        switch(abs(stack[sp]))
+        switch(iabs(stack[sp]))
         {
             case '0': color = bvec( 2,  255,  128 ); break;   // green: player talk
             case '1': color = bvec( 96,  160, 255 ); break;   // blue: team chat
@@ -380,7 +380,7 @@ static void text_color(char c, char *sta
             //default: color = bvec( 255, 255, 255 ); break;
         }
         int b = (int) (sinf(lastmillis / 200.0f) * 115.0f);
-        b = stack[sp] > 0 ? 100 : min(abs(b), 100);
+        b = stack[sp] > 0 ? 100 : min(iabs(b), 100);
         glColor4ub(color.x, color.y, color.z, (a * b) / 100);
     }
 }
