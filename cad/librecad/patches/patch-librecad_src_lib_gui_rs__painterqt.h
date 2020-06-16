$NetBSD: patch-librecad_src_lib_gui_rs__painterqt.h,v 1.1 2020/06/16 14:43:17 mef Exp $

Adapt for boost update

--- librecad/src/lib/gui/rs_painterqt.h.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/lib/gui/rs_painterqt.h
@@ -29,6 +29,7 @@
 #define RS_PAINTERQT_H
 
 #include <QPainter>
+#include <QPainterPath>
 
 #include "rs_painter.h"
 #include "rs_pen.h"
