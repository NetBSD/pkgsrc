$NetBSD: patch-Swift_QtUI_UserSearch_QtUserSearchWindow.h,v 1.2 2022/05/03 20:03:31 nia Exp $

Support newer Qt versions. via Arch Linux.

--- Swift/QtUI/UserSearch/QtUserSearchWindow.h.orig	2018-04-06 10:06:46.000000000 +0000
+++ Swift/QtUI/UserSearch/QtUserSearchWindow.h
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2010-2016 Isode Limited.
+ * Copyright (c) 2010-2018 Isode Limited.
  * All rights reserved.
  * See the COPYING file for more information.
  */
@@ -8,6 +8,7 @@
 
 #include <set>
 
+#include <QAbstractItemModel>
 #include <QWizard>
 
 #include <Swiften/Base/Override.h>
