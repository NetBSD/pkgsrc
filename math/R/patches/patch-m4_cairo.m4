$NetBSD: patch-m4_cairo.m4,v 1.1 2017/10/18 16:14:30 adam Exp $

Detect cairo with any backend (not only X11).

--- m4/cairo.m4.orig	2017-10-18 15:50:34.000000000 +0000
+++ m4/cairo.m4
@@ -70,7 +70,7 @@ else
                     [AC_LINK_IFELSE([AC_LANG_SOURCE([[
 #include <pango/pango.h>
 #include <pango/pangocairo.h>
-#include <cairo-xlib.h>
+#include <cairo.h>
 #if CAIRO_VERSION  < 10200
 #error cairo version >= 1.2 required
 #endif
