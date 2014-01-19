$NetBSD: patch-gui_config__dialog_config__dialog.cc,v 1.4 2014/01/19 01:18:50 ryoon Exp $

--- gui/config_dialog/config_dialog.cc.orig	2014-01-06 07:10:44.000000000 +0000
+++ gui/config_dialog/config_dialog.cc
@@ -94,21 +94,21 @@ ConfigDialog::ConfigDialog()
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
@@ -323,7 +323,7 @@ ConfigDialog::ConfigDialog()
   dictionaryPreloadingAndUACLabel->setVisible(false);
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // On Linux, disable all fields for UsageStats
   usageStatsLabel->setEnabled(false);
   usageStatsLabel->setVisible(false);
@@ -333,7 +333,7 @@ ConfigDialog::ConfigDialog()
   usageStatsMessage->setVisible(false);
   usageStatsCheckBox->setEnabled(false);
   usageStatsCheckBox->setVisible(false);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
   Reload();
 
@@ -409,7 +409,7 @@ bool ConfigDialog::Update() {
   }
 
 
-#if defined(OS_WIN)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_NETBSD)
   if ((initial_preedit_method_ !=
        static_cast<int>(config.preedit_method())) ||
       (initial_use_keyboard_to_change_preedit_method_ !=
@@ -421,7 +421,7 @@ bool ConfigDialog::Update() {
     initial_use_keyboard_to_change_preedit_method_ =
         config.use_keyboard_to_change_preedit_method();
   }
-#endif  // OS_WIN
+#endif  // OS_WIN, OS_LINUX or OS_NETBSD
 
 #ifdef OS_WIN
   if (initial_use_mode_indicator_ != config.use_mode_indicator()) {
