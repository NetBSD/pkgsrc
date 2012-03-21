$NetBSD: patch-core_utilities_setup_setupplugins.cpp,v 1.1 2012/03/21 21:14:47 markd Exp $

--- core/utilities/setup/setupplugins.cpp.orig	2012-01-03 00:32:01.000000000 +0000
+++ core/utilities/setup/setupplugins.cpp
@@ -6,8 +6,8 @@
  * Date        : 2004-01-02
  * Description : setup Kipi plugins tab.
  *
- * Copyright (C) 2004-2011 by Gilles Caulier <caulier dot gilles at gmail dot com>
- * Copyright (C) 2011 by Andi Clemens <andi dot clemens at googlemail dot com>
+ * Copyright (C) 2004-2012 by Gilles Caulier <caulier dot gilles at gmail dot com>
+ * Copyright (C) 2011-2012 by Andi Clemens <andi dot clemens at googlemail dot com>
  *
  * This program is free software; you can redistribute it
  * and/or modify it under the terms of the GNU General
@@ -100,6 +100,11 @@ SetupPlugins::SetupPlugins(QWidget* pare
 
     panel->setLayout(mainLayout);
 
+#if KIPI_VERSION < 0x010400
+    d->checkAllBtn->setVisible(false);
+    d->clearBtn->setVisible(false);
+#endif
+
     initPlugins();
 
     // --------------------------------------------------------
@@ -158,14 +163,18 @@ void SetupPlugins::applyPlugins()
 void SetupPlugins::slotCheckAll()
 {
     QApplication::setOverrideCursor(Qt::WaitCursor);
+#if KIPI_VERSION >= 0x010400
     d->kipiConfig->slotCheckAll();
+#endif
     QApplication::restoreOverrideCursor();
 }
 
 void SetupPlugins::slotClear()
 {
     QApplication::setOverrideCursor(Qt::WaitCursor);
+#if KIPI_VERSION >= 0x010400
     d->kipiConfig->slotClear();
+#endif
     QApplication::restoreOverrideCursor();
 }
 }  // namespace Digikam
