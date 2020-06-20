$NetBSD: patch-src_core_symbology_qgssymbollayer.h,v 1.1 2020/06/20 17:52:05 gdt Exp $

Deal with QT 5.15, from upstream.
https://github.com/qgis/QGIS/issues/37005
https://github.com/qgis/QGIS/commit/31f586ec.patch

--- src/core/symbology/qgssymbollayer.h.orig	2019-09-13 12:11:09.000000000 +0000
+++ src/core/symbology/qgssymbollayer.h
@@ -26,6 +26,7 @@
 #include <QSet>
 #include <QDomDocument>
 #include <QDomElement>
+#include <QPainterPath>
 
 #include "qgssymbol.h"
 #include "qgsfields.h"
