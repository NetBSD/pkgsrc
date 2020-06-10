$NetBSD: patch-core_dplugins_generic_view_presentation_opengl_presentationgl.cpp,v 1.1 2020/06/10 11:08:05 markd Exp $

qt5.15 fix

--- core/dplugins/generic/view/presentation/opengl/presentationgl.cpp.orig	2019-11-03 09:03:59.000000000 +0000
+++ core/dplugins/generic/view/presentation/opengl/presentationgl.cpp
@@ -44,6 +44,7 @@
 #include <QMatrix>
 #include <QMouseEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <QPixmap>
 #include <QTimer>
 #include <QWheelEvent>
