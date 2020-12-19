$NetBSD: patch-xpdf_GlobalParams.cc,v 1.1 2020/12/19 13:42:59 rhialto Exp $

Adjust font search directories to @PREFIX@.

--- xpdf/GlobalParams.cc.orig	2019-09-25 19:54:33.000000000 +0000
+++ xpdf/GlobalParams.cc
@@ -109,11 +109,16 @@ static const char *displayFontDirs[] = {
 };
 #else
 static const char *displayFontDirs[] = {
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
