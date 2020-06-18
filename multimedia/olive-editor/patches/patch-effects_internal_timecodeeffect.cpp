$NetBSD: patch-effects_internal_timecodeeffect.cpp,v 1.1 2020/06/18 14:52:12 nia Exp $

Fix Qt 5.15 build issues

--- effects/internal/timecodeeffect.cpp.orig	2019-07-09 15:16:17.000000000 +0000
+++ effects/internal/timecodeeffect.cpp
@@ -25,6 +25,7 @@
 #include <QOpenGLTexture>
 #include <QTextEdit>
 #include <QPainter>
+#include <QPainterPath>
 #include <QPushButton>
 #include <QColorDialog>
 #include <QFontDatabase>
