$NetBSD: patch-src_goocanvas_src_goocanvassvg.h,v 1.1 2012/08/29 16:51:40 wiz Exp $

Do not include deprecated header.

--- src/goocanvas/src/goocanvassvg.h.orig	2011-01-08 22:27:14.000000000 +0000
+++ src/goocanvas/src/goocanvassvg.h
@@ -10,7 +10,6 @@
 #include <gtk/gtk.h>
 #include "goocanvasitemsimple.h"
 #include <librsvg/rsvg.h>
-#include <librsvg/rsvg-cairo.h>
 
 G_BEGIN_DECLS
 
