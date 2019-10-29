$NetBSD: patch-src_dhcpcd-qt_main.cpp,v 1.1 2019/10/29 12:39:13 kamil Exp $

Port to Qt5.

--- src/dhcpcd-qt/main.cpp.orig	2015-01-07 09:18:28.000000000 +0000
+++ src/dhcpcd-qt/main.cpp
@@ -24,6 +24,7 @@
  * SUCH DAMAGE.
  */
 
+#include <QApplication>
 #include <QtGui>
 
 #include "dhcpcd-qt.h"
