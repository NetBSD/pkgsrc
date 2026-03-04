$NetBSD: patch-font_font__peer__ft2.cc,v 1.2 2026/03/04 10:27:19 tsutsui Exp $

- Add and fix default font paths.
- Appease -Wwrite-strings warnings

--- font/font_peer_ft2.cc.orig	2008-08-31 09:54:15.000000000 +0000
+++ font/font_peer_ft2.cc
@@ -49,15 +49,16 @@ typedef struct _FontLibrary {
 
 static FontLibrary *library = NULL;
 
-static char *default_paths[] = {
+static const char *default_paths[] = {
   ".",
   "/",
-  "/usr/X11R6/lib/X11/fonts/TrueType",
-  "/usr/local/share/fonts/TrueType",
-  "/usr/local/share/fonts/truetype",
+  "/usr/X11R7/lib/X11/fonts/TTF",
+  "/usr/pkg/share/fonts/TrueType",
+  "/usr/pkg/share/fonts/truetype",
   "/usr/share/fonts/TrueType",
   "/usr/share/fonts/truetype",
   "/usr/share/fonts/tt",
+  "/usr/pkg/share/fonts/X11/TTF",
   NULL
 };
 
