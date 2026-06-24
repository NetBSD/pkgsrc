$NetBSD: patch-pdf-backend.hh,v 1.3 2026/06/24 21:57:36 wiz Exp $

Fix build with poppler 26.06.
From Arch.
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.01.0.patch?h=pdf2djvu
https://aur.archlinux.org/cgit/aur.git/plain/pdf2djvu-poppler-26.x.patch?h=pdf2djvu

--- pdf-backend.hh.orig	2022-08-09 20:28:01.000000000 +0000
+++ pdf-backend.hh
@@ -26,7 +26,6 @@
 #include <utility>
 #include <vector>
 
-#include "autoconf.hh"
 
 // Poppler:
 #include <PDFDoc.h>
@@ -49,6 +48,7 @@
 #include <splash/SplashPath.h>
 #include <splash/SplashTypes.h>
 
+#include "autoconf.hh"
 #include "i18n.hh"
 
 namespace pdf
@@ -63,7 +63,12 @@ namespace pdf
     typedef ::Splash Splash;
     typedef ::SplashColor Color;
     typedef ::SplashFont Font;
+#include <poppler-config.h>
+#if POPPLER_VERSION >= 260500
+    typedef double Coord;
+#else
     typedef ::SplashCoord Coord;
+#endif
     typedef ::SplashPath Path;
     typedef ::SplashGlyphBitmap GlyphBitmap;
     typedef ::SplashBitmap Bitmap;
