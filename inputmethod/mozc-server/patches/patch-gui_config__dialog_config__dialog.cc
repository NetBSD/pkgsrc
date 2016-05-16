$NetBSD: patch-gui_config__dialog_config__dialog.cc,v 1.5 2016/05/16 11:51:49 ryoon Exp $

--- gui/config_dialog/config_dialog.cc.orig	2016-05-15 08:11:11.000000000 +0000
+++ gui/config_dialog/config_dialog.cc
@@ -100,21 +100,21 @@ ConfigDialog::ConfigDialog()
   setWindowTitle(tr("Mozc Preferences"));
 #endif  // OS_MACOSX
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   miscDefaultIMEWidget->setVisible(false);
   miscAdministrationWidget->setVisible(false);
   miscStartupWidget->setVisible(false);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
 #ifdef NO_LOGGING
   // disable logging options
   miscLoggingWidget->setVisible(false);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // The last "misc" tab has no valid configs on Linux
   const int kMiscTabIndex = 6;
   configDialogTabWidget->removeTab(kMiscTabIndex);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 #endif  // NO_LOGGING
 
 #ifndef ENABLE_CLOUD_HANDWRITING
@@ -324,7 +324,7 @@ ConfigDialog::ConfigDialog()
   dictionaryPreloadingAndUACLabel->setVisible(false);
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // On Linux, disable all fields for UsageStats
   usageStatsLabel->setEnabled(false);
   usageStatsLabel->setVisible(false);
@@ -334,7 +334,7 @@ ConfigDialog::ConfigDialog()
   usageStatsMessage->setVisible(false);
   usageStatsCheckBox->setEnabled(false);
   usageStatsCheckBox->setVisible(false);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
   Reload();
 
