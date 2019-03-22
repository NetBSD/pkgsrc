$NetBSD: patch-src_gui_DatabaseWidget.cpp,v 1.1 2019/03/22 15:56:41 ryoon Exp $

* Fix build without WITH_XC_KEESHARE

--- src/gui/DatabaseWidget.cpp.orig	2019-03-19 22:59:14.000000000 +0000
+++ src/gui/DatabaseWidget.cpp
@@ -1112,7 +1112,9 @@ void DatabaseWidget::search(const QStrin
     }
 
     m_searchingLabel->setVisible(true);
+#ifdef WITH_XC_KEESHARE
     m_shareLabel->setVisible(false);
+#endif
 
     emit searchModeActivated();
 }
