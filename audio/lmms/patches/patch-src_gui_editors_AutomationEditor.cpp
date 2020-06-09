$NetBSD: patch-src_gui_editors_AutomationEditor.cpp,v 1.1 2020/06/09 16:03:00 nia Exp $

[PATCH] Fix Qt 5.15 build issues (#5498)

Add missing QPainterPath includes

https://github.com/LMMS/lmms/commit/29a5abc30b5d5efa30b7f6b73fe06d76ec851cca.patch

--- src/gui/editors/AutomationEditor.cpp.orig	2018-11-03 01:43:42.000000000 +0000
+++ src/gui/editors/AutomationEditor.cpp
@@ -35,6 +35,7 @@
 #include <QLayout>
 #include <QMdiArea>
 #include <QPainter>
+#include <QPainterPath>
 #include <QScrollBar>
 #include <QStyleOption>
 #include <QToolTip>
