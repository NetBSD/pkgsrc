$NetBSD: patch-source_src_editing.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/editing.cpp.orig	2013-10-22 18:57:16.000000000 +0000
+++ source/src/editing.cpp
@@ -126,11 +126,11 @@ void checkselections()
 void makesel(bool isnew)
 {
     block &cursel = sels.last(); //RR 10/12/12 - FIXEME, error checking should happen with "isnew", not here checking if it really is new.
-    if(isnew || sels.length() == 0) addselection(min(lastx, cx), min(lasty, cy), abs(lastx-cx)+1, abs(lasty-cy)+1, max(lasth, ch));
+    if(isnew || sels.length() == 0) addselection(min(lastx, cx), min(lasty, cy), iabs(lastx-cx)+1, iabs(lasty-cy)+1, max(lasth, ch));
     else
     {
         cursel.x = min(lastx, cx); cursel.y = min(lasty, cy);
-        cursel.xs = abs(lastx-cx)+1; cursel.ys = abs(lasty-cy)+1;
+        cursel.xs = iabs(lastx-cx)+1; cursel.ys = iabs(lasty-cy)+1;
         cursel.h = max(lasth, ch);
         correctsel(cursel);
     }
@@ -645,7 +645,7 @@ void movemap(int xo, int yo, int zo) // 
     }
     if(xo || yo)
     {
-        block b = { max(-xo, 0), max(-yo, 0), ssize - abs(xo), ssize - abs(yo) }, *cp = blockcopy(b);
+        block b = { max(-xo, 0), max(-yo, 0), ssize - iabs(xo), ssize - iabs(yo) }, *cp = blockcopy(b);
         cp->x = max(xo, 0);
         cp->y = max(yo, 0);
         blockpaste(*cp);
