$NetBSD: patch-src_libnrtype_FontFactory.h,v 1.1 2013/12/15 08:29:07 markd Exp $

Build with freetype 2.5.x

--- src/libnrtype/FontFactory.h.orig	2011-07-08 18:25:09.468790000 +0000
+++ src/libnrtype/FontFactory.h
@@ -31,7 +31,8 @@
 #include <pango/pangowin32.h>
 #else
 #include <pango/pangoft2.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #endif
 
 namespace Glib
