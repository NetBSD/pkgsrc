$NetBSD: patch-gui_config__dialog_config__dialog.cc,v 1.8 2024/02/10 01:17:27 ryoon Exp $

--- gui/config_dialog/config_dialog.cc.orig	2023-12-13 09:33:40.403986822 +0000
+++ gui/config_dialog/config_dialog.cc
@@ -105,7 +105,7 @@ ConfigDialog::ConfigDialog()
   setWindowTitle(tr("%1 Preferences").arg(GuiUtil::ProductName()));
 #endif  // __APPLE__
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   miscDefaultIMEWidget->setVisible(false);
   miscAdministrationWidget->setVisible(false);
   miscStartupWidget->setVisible(false);
@@ -115,7 +115,7 @@ ConfigDialog::ConfigDialog()
   // disable logging options
   miscLoggingWidget->setVisible(false);
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   // The last "misc" tab has no valid configs on Linux
   constexpr int kMiscTabIndex = 6;
   configDialogTabWidget->removeTab(kMiscTabIndex);
@@ -281,7 +281,7 @@ ConfigDialog::ConfigDialog()
   dictionaryPreloadingAndUACLabel->setVisible(false);
 #endif  // _WIN32
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
   // On Linux, disable all fields for UsageStats
   usageStatsLabel->setEnabled(false);
   usageStatsLabel->setVisible(false);
