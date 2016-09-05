$NetBSD: patch-librecad_src_lib_engine_rs__color.h,v 1.1 2016/09/05 21:13:21 plunky Exp $

add missing includes

--- librecad/src/lib/engine/rs_color.h.orig	2016-06-20 18:43:27.000000000 +0000
+++ librecad/src/lib/engine/rs_color.h
@@ -29,6 +29,7 @@
 #define RS_COLOR_H

 #include <QColor>
+#include <ostream>

 #include "rs.h"
 #include "rs_flags.h"
