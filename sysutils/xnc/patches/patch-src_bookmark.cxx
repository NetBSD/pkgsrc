$NetBSD: patch-src_bookmark.cxx,v 1.1 2020/04/20 00:46:51 joerg Exp $

--- src/bookmark.cxx.orig	2020-04-19 23:17:54.222880929 +0000
+++ src/bookmark.cxx
@@ -1243,7 +1243,7 @@ void   BookMark::click()
           {
             XDrawLine(disp, Main, rgc, rwx, rwy, rwx, rwy + h);
             XDrawLine(disp, Main, rgc, rwx + 1, rwy, rwx + 1, rwy + h);
-            if (abs(rwx - (Mainl - l) / 2) < STICKY_CENTER)
+            if (abs(rwx - int(Mainl - l) / 2) < STICKY_CENTER)
               rwx = (Mainl - l) / 2;
             if (rwx < (Mainl - l) * MIN_PERCENT / 100)
               rwx = (Mainl - l) * MIN_PERCENT / 100;
@@ -1277,7 +1277,7 @@ void   BookMark::click()
           {
             if (cx > leftrx && cx < rightrx)
               {
-                if (abs(cx - (Mainl - l) / 2) < STICKY_CENTER)
+                if (abs(cx - int(Mainl - l) / 2) < STICKY_CENTER)
                   cx = (Mainl - l) / 2;
                 XDrawLine(disp, Main, rgc, rwx, rwy, rwx, rwy + h);
                 XDrawLine(disp, Main, rgc, rwx + 1, rwy, rwx + 1, rwy + h);
