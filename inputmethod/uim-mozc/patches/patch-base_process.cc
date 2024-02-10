$NetBSD: patch-base_process.cc,v 1.1 2024/02/10 02:20:18 ryoon Exp $

--- base/process.cc.orig	2023-12-13 09:15:36.129469332 +0000
+++ base/process.cc
@@ -98,12 +98,12 @@ bool Process::OpenBrowser(const std::str
       L"open", win32::Utf8ToWide(url).c_str(), nullptr);
 #endif  // _WIN32
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 
 #ifndef MOZC_BROWSER_COMMAND
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
-#define MOZC_BROWSER_COMMAND "/usr/bin/xdg-open"
+#define MOZC_BROWSER_COMMAND "@PREFIX@/bin/xdg-open"
 #endif  // MOZC_BROWSER_COMMAND
 
   return SpawnProcess(MOZC_BROWSER_COMMAND, url);
@@ -387,7 +387,7 @@ bool Process::LaunchErrorMessageDialog(c
   }
 #endif  // _WIN32
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__NetBSD__)) && !defined(__ANDROID__)
   constexpr char kMozcTool[] = "mozc_tool";
   const std::string arg =
       "--mode=error_message_dialog --error_type=" + error_type;
