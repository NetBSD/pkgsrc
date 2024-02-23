$NetBSD: patch-apps_lib_ktexteditor__utils.h,v 1.1 2024/02/23 04:00:03 gutteridge Exp $

Fix non-PCH-enabled build by adding missing includes.

--- apps/lib/ktexteditor_utils.h.orig	2023-12-04 03:09:43.000000000 +0000
+++ apps/lib/ktexteditor_utils.h
@@ -7,6 +7,8 @@
 #include "kateprivate_export.h"
 
 #include <QString>
+#include <QUrl>
+#include <QWidgetList>
 
 QT_BEGIN_NAMESPACE
 class QScrollBar;
