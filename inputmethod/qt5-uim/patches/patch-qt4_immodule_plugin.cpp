$NetBSD: patch-qt4_immodule_plugin.cpp,v 1.1 2013/12/15 19:38:33 joerg Exp $

--- qt4/immodule/plugin.cpp.orig	2013-12-15 17:58:04.000000000 +0000
+++ qt4/immodule/plugin.cpp
@@ -33,6 +33,7 @@
 */
 
 #include "plugin.h"
+#include <clocale>
 
 #include <QtCore/QStringList>
 #ifdef Q_WS_X11
