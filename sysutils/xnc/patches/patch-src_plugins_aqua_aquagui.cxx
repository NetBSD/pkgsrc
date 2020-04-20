$NetBSD: patch-src_plugins_aqua_aquagui.cxx,v 1.1 2020/04/20 00:46:51 joerg Exp $

--- src/plugins/aqua/aquagui.cxx.orig	2020-04-19 23:23:41.525988818 +0000
+++ src/plugins/aqua/aquagui.cxx
@@ -971,7 +971,7 @@ void   AquaBookMark::click()
           {
             XDrawLine(disp, Main, rgc, rwx, rwy, rwx, rwy + h);
             XDrawLine(disp, Main, rgc, rwx + 1, rwy, rwx + 1, rwy + h);
-            if (abs(rwx - (Mainl - l) / 2) < STICKY_CENTER)
+            if (abs(rwx - int(Mainl - l) / 2) < STICKY_CENTER)
               rwx = (Mainl - l) / 2;
             if (rwx < (Mainl - l) * MIN_PERCENT / 100)
               rwx = (Mainl - l) * MIN_PERCENT / 100;
@@ -1005,7 +1005,7 @@ void   AquaBookMark::click()
           {
             if (cx > leftrx && cx < rightrx)
               {
-                if (abs(cx - (Mainl - l) / 2) < STICKY_CENTER)
+                if (abs(cx - int(Mainl - l) / 2) < STICKY_CENTER)
                   cx = (Mainl - l) / 2;
                 XDrawLine(disp, Main, rgc, rwx, rwy, rwx, rwy + h);
                 XDrawLine(disp, Main, rgc, rwx + 1, rwy, rwx + 1, rwy + h);
