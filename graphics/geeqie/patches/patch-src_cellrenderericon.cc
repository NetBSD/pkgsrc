$NetBSD: patch-src_cellrenderericon.cc,v 1.2 2026/08/09 17:42:34 wiz Exp $

../src/cellrenderericon.cc: In function 'gint gqv_cell_renderer_icon_mark_at(GtkCellRenderer*, GtkWidget*, const GdkRectangle*, gdouble, gdouble)':
../src/cellrenderericon.cc:101:50: error: 'floor' is not a member of 'std'; did you mean 'floor'?
  101 |         return std::clamp(static_cast<gint>(std::floor(((x - first_center) / TOGGLE_SPACING) + 0.5)),
      |                                                  ^~~~~
https://github.com/BestImageViewer/geeqie/pull/2533

--- src/cellrenderericon.cc.orig	2026-08-09 17:20:27.910468088 +0000
+++ src/cellrenderericon.cc
@@ -20,6 +20,7 @@
 #include "cellrenderericon.h"
 
 #include <algorithm>
+#include <cmath>
 #include <cstddef>
 
 #include <cairo.h>
