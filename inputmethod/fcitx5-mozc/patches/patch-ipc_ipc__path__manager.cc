$NetBSD: patch-ipc_ipc__path__manager.cc,v 1.2 2024/02/10 12:26:02 ryoon Exp $

--- ipc/ipc_path_manager.cc.orig	2023-12-13 09:35:34.871003763 +0000
+++ ipc/ipc_path_manager.cc
@@ -389,7 +389,7 @@ bool IPCPathManager::IsValidServer(uint3
   server_pid_ = pid;
 #endif  // __APPLE__
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
   // load from /proc/<pid>/exe
   std::string proc = absl::StrFormat("/proc/%u/exe", pid);
   char filename[512];
