$NetBSD: patch-Swift_QtUI_UserSearch_QtUserSearchWindow.h,v 1.1 2018/06/23 09:40:53 wiz Exp $

Fix build with Qt 5.11.

--- Swift/QtUI/UserSearch/QtUserSearchWindow.h.orig	2016-02-29 10:29:02.000000000 +0000
+++ Swift/QtUI/UserSearch/QtUserSearchWindow.h
@@ -6,6 +6,7 @@
 
 #pragma once
 
+#include <QAbstractItemModel>
 #include <QWizard>
 #include <set>
 
