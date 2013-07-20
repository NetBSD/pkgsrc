$NetBSD: patch-gui_config__dialog_config__dialog.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- gui/config_dialog/config_dialog.cc.orig	2013-07-17 02:38:18.000000000 +0000
+++ gui/config_dialog/config_dialog.cc
@@ -97,21 +97,21 @@ ConfigDialog::ConfigDialog()
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
 
 #ifndef ENABLE_CLOUD_SYNC
@@ -347,7 +347,7 @@ ConfigDialog::ConfigDialog()
   dictionaryPreloadingAndUACLabel->setVisible(false);
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // On Linux, disable all fields for UsageStats
   usageStatsLabel->setEnabled(false);
   usageStatsLabel->setVisible(false);
@@ -357,7 +357,7 @@ ConfigDialog::ConfigDialog()
   usageStatsMessage->setVisible(false);
   usageStatsCheckBox->setEnabled(false);
   usageStatsCheckBox->setVisible(false);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
   webUsageDictionaryCheckBox->setVisible(false);
   editWebServiceEntryButton->setVisible(false);
@@ -460,7 +460,7 @@ bool ConfigDialog::Update() {
   }
 
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_NETBSD)
   if ((initial_preedit_method_ !=
        static_cast<int>(config.preedit_method())) ||
       (initial_use_keyboard_to_change_preedit_method_ !=
