$NetBSD: patch-ipc_ipc__path__manager.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- ipc/ipc_path_manager.cc.orig	2013-03-29 04:33:26.000000000 +0000
+++ ipc/ipc_path_manager.cc
@@ -44,6 +44,11 @@
 #endif  // OS_MACOSX
 #endif  // OS_WIN
 
+#if defined(OS_NETBSD)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
+
 #include <cstdlib>
 #include <map>
 
@@ -427,7 +432,24 @@ bool IPCPathManager::IsValidServer(uint3
     return true;
   }
 
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
   if ((server_path + " (deleted)") == server_path_) {
     LOG(WARNING) << server_path << " on disk is modified";
     // If a user updates the server binary on disk during the server is running,
