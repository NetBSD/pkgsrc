$NetBSD: patch-lbreakout_breakout.cpp,v 1.1 2014/02/09 17:12:33 wiedi Exp $

fix "sqrt(int) is ambiguous" on SunOS
--- lbreakout/breakout.cpp.orig	2001-03-15 15:27:33.000000000 +0000
+++ lbreakout/breakout.cpp
@@ -1437,7 +1437,7 @@ void BreakOut::Club_HandleContact(Ball *
     b->club_con = 1;
 
     if (a.x != 0 && a.y != 0) {
-        d = sqrt(2);
+        d = sqrt((double)2);
         a.x /= d; a.y /= d;
     }
 
@@ -1557,7 +1557,7 @@ void BreakOut::Ball_CheckBrickReflection
 
         // norm //
         if (a.x != 0 && a.y != 0) {
-            d = sqrt(2);
+            d = sqrt((double)2);
             a.x /= d; a.y /= d;
         }
 
