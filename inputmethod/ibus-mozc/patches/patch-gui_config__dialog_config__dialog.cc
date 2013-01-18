$NetBSD: patch-gui_config__dialog_config__dialog.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- gui/config_dialog/config_dialog.cc.orig	2012-08-31 05:37:09.000000000 +0000
+++ gui/config_dialog/config_dialog.cc
@@ -83,21 +83,21 @@ ConfigDialog::ConfigDialog()
   miscAdministrationWidget->setVisible(false);
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
 
 #ifndef ENABLE_CLOUD_SYNC
@@ -322,7 +322,7 @@ ConfigDialog::ConfigDialog()
   dictionaryPreloadingAndUACLabel->setVisible(false);
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // On Linux, disable all fields for UsageStats
   usageStatsLabel->setEnabled(false);
   usageStatsLabel->setVisible(false);
@@ -332,7 +332,7 @@ ConfigDialog::ConfigDialog()
   usageStatsMessage->setVisible(false);
   usageStatsCheckBox->setEnabled(false);
   usageStatsCheckBox->setVisible(false);
-#endif // OS_LINUX
+#endif // OS_LINUX || OS_NETBSD
 
   webUsageDictionaryCheckBox->setVisible(false);
   editWebServiceEntryButton->setVisible(false);
@@ -438,7 +438,7 @@ bool ConfigDialog::Update() {
   }
 
 
-#if defined(OS_WINDOWS) || defined(OS_LINUX)
+#if defined(OS_WINDOWS) || defined(OS_LINUX) || defined(OS_NETBSD)
   if (initial_preedit_method_ !=
       static_cast<int>(config.preedit_method()) ||
       initial_use_keyboard_to_change_preedit_method_ !=
