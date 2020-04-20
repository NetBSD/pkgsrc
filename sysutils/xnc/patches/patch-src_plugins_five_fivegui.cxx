$NetBSD: patch-src_plugins_five_fivegui.cxx,v 1.1 2020/04/20 00:46:51 joerg Exp $

--- src/plugins/five/fivegui.cxx.orig	2020-04-19 23:22:58.500838204 +0000
+++ src/plugins/five/fivegui.cxx
@@ -1831,7 +1831,7 @@ void   FiveBookMark::click()
           {
             XDrawLine(disp, Main, rgc, rwx, rwy, rwx, rwy + h);
             XDrawLine(disp, Main, rgc, rwx + 1, rwy, rwx + 1, rwy + h);
-            if (abs(rwx - (Mainl - l) / 2) < STICKY_CENTER)
+            if (abs(rwx - int(Mainl - l) / 2) < STICKY_CENTER)
               rwx = (Mainl - l) / 2;
             if (rwx < (Mainl - l) * MIN_PERCENT / 100)
               rwx = (Mainl - l) * MIN_PERCENT / 100;
@@ -1865,7 +1865,7 @@ void   FiveBookMark::click()
           {
             if (cx > leftrx && cx < rightrx)
               {
-                if (abs(cx - (Mainl - l) / 2) < STICKY_CENTER)
+                if (abs(cx - int(Mainl - l) / 2) < STICKY_CENTER)
                   cx = (Mainl - l) / 2;
                 XDrawLine(disp, Main, rgc, rwx, rwy, rwx, rwy + h);
                 XDrawLine(disp, Main, rgc, rwx + 1, rwy, rwx + 1, rwy + h);
