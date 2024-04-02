$NetBSD: patch-xpdf_GlobalParams.cc,v 1.2 2024/04/02 18:27:55 rhialto Exp $

Adjust font search directories to @PREFIX@.

--- xpdf/GlobalParams.cc.orig	2024-02-07 20:32:41.000000000 +0000
+++ xpdf/GlobalParams.cc
@@ -107,11 +107,16 @@ static const char *displayFontDirs[] = {
   "c:/windows/fonts",
   "c:/winnt/fonts",
 #else // _WIN32
-  "/usr/share/ghostscript/fonts",
+  "@PREFIX@/share/ghostscript/fonts",
   "/usr/local/share/ghostscript/fonts",
-  "/usr/share/fonts/default/Type1",
-  "/usr/share/fonts/default/ghostscript",
-  "/usr/share/fonts/type1/gsfonts",
+  "@PREFIX@/share/fonts/default/Type1",
+  "@PREFIX@/share/fonts/default/ghostscript",
+  "@PREFIX@/share/fonts/type1/gsfonts",
+  "@PREFIX@/share/fonts/X11/Type1",
+  "/usr/X11R6/lib/X11/fonts/Type1",
+  "/usr/X11R7/lib/X11/fonts/Type1",
+  "@PREFIX@/xorg/lib/X11/fonts/Type1",
+  "@PREFIX@/share/fonts/urw",
 #if defined(__sun) && defined(__SVR4)
   "/usr/sfw/share/ghostscript/fonts",
 #endif
