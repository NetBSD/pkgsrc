$NetBSD: patch-base_process.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- base/process.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/process.cc
@@ -50,7 +50,7 @@
 #include "base/mac_process.h"
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 #include <fcntl.h>
 #include <signal.h>
 #include <spawn.h>  // for posix_spawn().
@@ -120,7 +120,7 @@ bool Process::OpenBrowser(const string &
   return ShellExecuteInSystemDir(L"open", wurl.c_str(), NULL, SW_SHOW);
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   static const char kBrowserCommand[] = "/usr/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
@@ -204,7 +204,7 @@ bool Process::SpawnProcess(const string 
   }
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Do not call posix_spawn() for obviously bad path.
   if (!S_ISREG(statbuf.st_mode)) {
     LOG(ERROR) << "Not a regular file: " << path;
@@ -227,7 +227,7 @@ bool Process::SpawnProcess(const string 
   // (www.gnu.org/software/libc/manual/html_node/Heap-Consistency-Checking.html)
   const int kOverwrite = 0;  // Do not overwrite.
   ::setenv("MALLOC_CHECK_", "2", kOverwrite);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
   pid_t tmp_pid = 0;
 
   // Spawn new process.
@@ -398,7 +398,7 @@ bool Process::LaunchErrorMessageDialog(c
   }
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   const char kMozcTool[] = "mozc_tool";
   const string arg = "--mode=error_message_dialog --error_type=" + error_type;
   size_t pid = 0;
@@ -406,7 +406,7 @@ bool Process::LaunchErrorMessageDialog(c
     LOG(ERROR) << "cannot launch " << kMozcTool;
     return false;
   }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
   return true;
 }
