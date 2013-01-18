$NetBSD: patch-ipc_ipc__path__manager.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- ipc/ipc_path_manager.cc.orig	2012-08-31 05:37:07.000000000 +0000
+++ ipc/ipc_path_manager.cc
@@ -48,6 +48,11 @@
 #include "base/mac_util.h"
 #endif
 
+#if defined(OS_NETBSD)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "base/base.h"
 #include "base/const.h"
 #include "base/file_stream.h"
@@ -284,7 +289,7 @@ bool IPCPathManager::GetPathName(string 
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
@@ -360,7 +365,7 @@ bool IPCPathManager::IsValidServer(uint3
   }
 #endif
 
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX)
   int name[] = { CTL_KERN, KERN_PROCARGS, pid };
   size_t data_len = 0;
   if (sysctl(name, arraysize(name), NULL,
@@ -377,7 +382,24 @@ bool IPCPathManager::IsValidServer(uint3
   }
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_NETBSD)
+  int name[] = { CTL_KERN, KERN_PROC_ARGS, pid };
+  size_t data_len = 0;
+  if (sysctl(name, arraysize(name), NULL,
+             &data_len, NULL, 0) < 0) {
+    LOG(ERROR) << "sysctl KERN_PROC_ARGS failed";
+    return false;
+  }
+
+  server_path_.resize(data_len);
+  if (sysctl(name, arraysize(name), &server_path_[0],
+             &data_len, NULL, 0) < 0) {
+    LOG(ERROR) << "sysctl KERN_PROC_ARGS failed";
+    return false;
+  }
+#endif
+
+#if defined(OS_LINUX)
   // load from /proc/<pid>/exe
   char proc[128];
   char filename[512];
@@ -397,7 +419,7 @@ bool IPCPathManager::IsValidServer(uint3
     return true;
   }
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX)
   if ((server_path + " (deleted)") == server_path_) {
     LOG(WARNING) << server_path << " on disk is modified";
     // If a user updates the server binary on disk during the server is running,
