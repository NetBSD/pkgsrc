$NetBSD: patch-font_font__peer__ft2.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

Add and fix default font paths.

--- font/font_peer_ft2.cc.orig	2008-08-31 09:54:15.000000000 +0000
+++ font/font_peer_ft2.cc
@@ -52,12 +52,13 @@ static FontLibrary *library = NULL;
 static char *default_paths[] = {
   ".",
   "/",
-  "/usr/X11R6/lib/X11/fonts/TrueType",
+  "/usr/X11R7/lib/X11/fonts/TTF",
   "/usr/local/share/fonts/TrueType",
   "/usr/local/share/fonts/truetype",
   "/usr/share/fonts/TrueType",
   "/usr/share/fonts/truetype",
   "/usr/share/fonts/tt",
+  "/usr/pkg/share/fonts/X11/TTF",
   NULL
 };
 
