$NetBSD: patch-base_process.cc,v 1.5 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- base/process.cc.orig	2017-11-02 13:32:45.000000000 +0000
+++ base/process.cc
@@ -44,12 +44,12 @@
 #include "base/mac_process.h"
 #endif  // OS_MACOSX
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
 #include <fcntl.h>
 #include <signal.h>
 #include <spawn.h>  // for posix_spawn().
 #include <sys/types.h>
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 
 #include <cstdlib>
 #include <memory>
@@ -96,12 +96,12 @@ bool Process::OpenBrowser(const string &
   return WinUtil::ShellExecuteInSystemDir(L"open", wurl.c_str(), nullptr);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
-  static const char kBrowserCommand[] = "/usr/bin/xdg-open";
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
+  static const char kBrowserCommand[] = "@PREFIX@/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 
 #ifdef OS_MACOSX
   return MacProcess::OpenBrowserForMac(url);
@@ -180,7 +180,7 @@ bool Process::SpawnProcess(const string 
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   // Do not call posix_spawn() for obviously bad path.
   if (!S_ISREG(statbuf.st_mode)) {
     LOG(ERROR) << "Not a regular file: " << path;
@@ -203,7 +203,7 @@ bool Process::SpawnProcess(const string 
   // (www.gnu.org/software/libc/manual/html_node/Heap-Consistency-Checking.html)
   const int kOverwrite = 0;  // Do not overwrite.
   ::setenv("MALLOC_CHECK_", "2", kOverwrite);
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
   pid_t tmp_pid = 0;
 
   // Spawn new process.
@@ -374,7 +374,7 @@ bool Process::LaunchErrorMessageDialog(c
   }
 #endif  // OS_WIN
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   const char kMozcTool[] = "mozc_tool";
   const string arg = "--mode=error_message_dialog --error_type=" + error_type;
   size_t pid = 0;
@@ -382,7 +382,7 @@ bool Process::LaunchErrorMessageDialog(c
     LOG(ERROR) << "cannot launch " << kMozcTool;
     return false;
   }
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 
   return true;
 }
