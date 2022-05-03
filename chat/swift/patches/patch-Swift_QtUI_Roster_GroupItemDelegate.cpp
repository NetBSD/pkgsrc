$NetBSD: patch-Swift_QtUI_Roster_GroupItemDelegate.cpp,v 1.1 2022/05/03 20:03:31 nia Exp $

Support newer Qt versions. via Arch Linux.

--- Swift/QtUI/Roster/GroupItemDelegate.cpp.orig	2018-04-06 10:06:46.000000000 +0000
+++ Swift/QtUI/Roster/GroupItemDelegate.cpp
@@ -7,6 +7,7 @@
 #include <Swift/QtUI/Roster/GroupItemDelegate.h>
 
 #include <QPainter>
+#include <QPainterPath>
 #include <QPen>
 #include <QtDebug>
 
