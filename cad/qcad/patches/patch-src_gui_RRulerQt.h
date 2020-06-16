$NetBSD: patch-src_gui_RRulerQt.h,v 1.1 2020/06/16 23:09:31 mef Exp $

Adapt Qt Update

--- src/gui/RRulerQt.h.orig	2020-03-17 10:40:38.000000000 +0000
+++ src/gui/RRulerQt.h
@@ -24,6 +24,7 @@
 
 #include <QFrame>
 #include <QMetaType>
+#include <QPainterPath>
 
 #include "RCoordinateListener.h"
 #include "RRuler.h"
