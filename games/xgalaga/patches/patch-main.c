$NetBSD: patch-main.c,v 1.1 2020/11/20 13:50:23 nia Exp $

Don't start fullscreen, appears to be buggy...

--- main.c.orig	2008-03-05 21:58:16.000000000 +0000
+++ main.c
@@ -1277,7 +1277,7 @@ char  **argv;
     int ac;
     char *dpyname = 0;
     int mx, my, but;
-    int start_fullscreen = 1;
+    int start_fullscreen = 0;
    
     for(ac = 1; ac < argc; ac++) {
         if(*argv[ac] == '-') {
