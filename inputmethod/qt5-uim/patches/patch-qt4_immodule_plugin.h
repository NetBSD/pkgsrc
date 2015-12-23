$NetBSD: patch-qt4_immodule_plugin.h,v 1.1 2015/12/23 12:40:37 joerg Exp $

--- qt4/immodule/plugin.h.orig	2015-12-22 23:30:50.000000000 +0000
+++ qt4/immodule/plugin.h
@@ -38,6 +38,7 @@
 #if QT_VERSION < 0x050000
 # include <QtGui/QInputContextPlugin>
 #else
+# include <QtCore/qdatastream.h>
 # include <qpa/qplatforminputcontextplugin_p.h>
 #endif
 
