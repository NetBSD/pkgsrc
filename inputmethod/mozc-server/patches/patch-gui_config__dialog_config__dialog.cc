$NetBSD: patch-gui_config__dialog_config__dialog.cc,v 1.7 2021/02/15 14:50:23 ryoon Exp $

* NetBSD support

--- gui/config_dialog/config_dialog.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ gui/config_dialog/config_dialog.cc
@@ -104,21 +104,21 @@ ConfigDialog::ConfigDialog()
   setWindowTitle(tr("%1 Preferences").arg(GuiUtil::ProductName()));
 #endif  // __APPLE__
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   miscDefaultIMEWidget->setVisible(false);
   miscAdministrationWidget->setVisible(false);
   miscStartupWidget->setVisible(false);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
 #ifdef MOZC_NO_LOGGING
   // disable logging options
   miscLoggingWidget->setVisible(false);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // The last "misc" tab has no valid configs on Linux
   const int kMiscTabIndex = 6;
   configDialogTabWidget->removeTab(kMiscTabIndex);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 #endif  // MOZC_NO_LOGGING
 
   suggestionsSizeSpinBox->setRange(1, 9);
@@ -280,7 +280,7 @@ ConfigDialog::ConfigDialog()
   dictionaryPreloadingAndUACLabel->setVisible(false);
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // On Linux, disable all fields for UsageStats
   usageStatsLabel->setEnabled(false);
   usageStatsLabel->setVisible(false);
@@ -290,7 +290,7 @@ ConfigDialog::ConfigDialog()
   usageStatsMessage->setVisible(false);
   usageStatsCheckBox->setEnabled(false);
   usageStatsCheckBox->setVisible(false);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
   GuiUtil::ReplaceWidgetLabels(this);
 
