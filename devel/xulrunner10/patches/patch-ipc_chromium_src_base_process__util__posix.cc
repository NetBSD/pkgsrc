$NetBSD: patch-ipc_chromium_src_base_process__util__posix.cc,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- ipc/chromium/src/base/process_util_posix.cc.orig	2012-03-09 22:20:16.000000000 +0000
+++ ipc/chromium/src/base/process_util_posix.cc
@@ -116,6 +116,11 @@ void CloseSuperfluousFds(const base::Inj
 #elif defined(OS_MACOSX)
   static const rlim_t kSystemDefaultMaxFds = 256;
   static const char kFDDir[] = "/dev/fd";
+#elif defined(OS_BSD)
+  // the getrlimit below should never fail, so whatever ..
+  static const rlim_t kSystemDefaultMaxFds = 1024;
+  // at least /dev/fd will exist
+  static const char kFDDir[] = "/dev/fd";
 #endif
 
   // Get the maximum number of FDs possible.
@@ -199,7 +204,7 @@ void CloseSuperfluousFds(const base::Inj
 void SetAllFDsToCloseOnExec() {
 #if defined(OS_LINUX)
   const char fd_dir[] = "/proc/self/fd";
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   const char fd_dir[] = "/dev/fd";
 #endif
   ScopedDIR dir_closer(opendir(fd_dir));
