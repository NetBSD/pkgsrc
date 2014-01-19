$NetBSD: patch-ipc_ipc__path__manager.cc,v 1.4 2014/01/19 01:18:50 ryoon Exp $

--- ipc/ipc_path_manager.cc.orig	2014-01-06 07:10:26.000000000 +0000
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
 #ifdef OS_WIN
@@ -407,6 +412,23 @@ bool IPCPathManager::IsValidServer(uint3
     return true;
   }
 
+#if defined(OS_NETBSD)
+  int name[] = { CTL_KERN, KERN_PROC_ARGS, static_cast<int>(pid) };
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
+#endif // OS_NETBSD
+
 #ifdef OS_LINUX
   if ((server_path + " (deleted)") == server_path_) {
     LOG(WARNING) << server_path << " on disk is modified";
