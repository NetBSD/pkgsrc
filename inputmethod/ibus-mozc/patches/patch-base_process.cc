$NetBSD: patch-base_process.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- base/process.cc.orig	2013-03-29 04:33:43.000000000 +0000
+++ base/process.cc
@@ -46,7 +46,7 @@
 #include "base/mac_process.h"
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 #include <fcntl.h>
 #include <signal.h>
 #include <spawn.h>  // for posix_spawn().
@@ -121,7 +121,7 @@ bool Process::OpenBrowser(const string &
   return ShellExecuteInSystemDir(L"open", wurl.c_str(), NULL, SW_SHOW);
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   static const char kBrowserCommand[] = "/usr/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
@@ -205,7 +205,7 @@ bool Process::SpawnProcess(const string 
   }
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Do not call posix_spawn() for obviously bad path.
   if (!S_ISREG(statbuf.st_mode)) {
     LOG(ERROR) << "Not a regular file: " << path;
@@ -228,7 +228,7 @@ bool Process::SpawnProcess(const string 
   // (www.gnu.org/software/libc/manual/html_node/Heap-Consistency-Checking.html)
   const int kOverwrite = 0;  // Do not overwrite.
   ::setenv("MALLOC_CHECK_", "2", kOverwrite);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
   pid_t tmp_pid = 0;
 
   // Spawn new process.
@@ -399,7 +399,7 @@ bool Process::LaunchErrorMessageDialog(c
   }
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   const char kMozcTool[] = "mozc_tool";
   const string arg = "--mode=error_message_dialog --error_type=" + error_type;
   size_t pid = 0;
@@ -407,7 +407,7 @@ bool Process::LaunchErrorMessageDialog(c
     LOG(ERROR) << "cannot launch " << kMozcTool;
     return false;
   }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
   return true;
 }
