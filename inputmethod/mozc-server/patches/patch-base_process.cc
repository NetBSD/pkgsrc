$NetBSD: patch-base_process.cc,v 1.6 2021/02/15 14:50:23 ryoon Exp $

* NetBSD support

--- base/process.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ base/process.cc
@@ -46,12 +46,12 @@
 #include "base/mac_process.h"
 #endif  // __APPLE__
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NETBSD)
 #include <fcntl.h>
 #include <signal.h>
 #include <spawn.h>  // for posix_spawn().
 #include <sys/types.h>
-#endif  // OS_LINUX || OS_ANDROID
+#endif  // OS_LINUX || OS_ANDROID || OS_NETBSD
 
 #include <cstdlib>
 #include <memory>
@@ -98,12 +98,12 @@ bool Process::OpenBrowser(const std::str
   return WinUtil::ShellExecuteInSystemDir(L"open", wurl.c_str(), nullptr);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
-  static const char kBrowserCommand[] = "/usr/bin/xdg-open";
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NETBSD)
+  static const char kBrowserCommand[] = "@PREFIX@/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
-#endif  // OS_LINUX || OS_ANDROID
+#endif  // OS_LINUX || OS_ANDROID || OS_NETBSD
 
 #ifdef __APPLE__
   return MacProcess::OpenBrowserForMac(url);
@@ -185,7 +185,7 @@ bool Process::SpawnProcess(const std::st
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NETBSD)
   // Do not call posix_spawn() for obviously bad path.
   if (!S_ISREG(statbuf.st_mode)) {
     LOG(ERROR) << "Not a regular file: " << path;
@@ -208,7 +208,7 @@ bool Process::SpawnProcess(const std::st
   // (www.gnu.org/software/libc/manual/html_node/Heap-Consistency-Checking.html)
   const int kOverwrite = 0;  // Do not overwrite.
   ::setenv("MALLOC_CHECK_", "2", kOverwrite);
-#endif  // OS_LINUX || OS_ANDROID
+#endif  // OS_LINUX || OS_ANDROID || OS_NETBSD
   pid_t tmp_pid = 0;
 
   // Spawn new process.
@@ -383,7 +383,7 @@ bool Process::LaunchErrorMessageDialog(c
   }
 #endif  // OS_WIN
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NETBSD)
   const char kMozcTool[] = "mozc_tool";
   const std::string arg =
       "--mode=error_message_dialog --error_type=" + error_type;
@@ -392,7 +392,7 @@ bool Process::LaunchErrorMessageDialog(c
     LOG(ERROR) << "cannot launch " << kMozcTool;
     return false;
   }
-#endif  // OS_LINUX || OS_ANDROID
+#endif  // OS_LINUX || OS_ANDROID || OS_NETBSD
 
   return true;
 }
