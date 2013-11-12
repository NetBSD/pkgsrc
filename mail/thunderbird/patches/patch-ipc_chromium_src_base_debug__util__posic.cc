$NetBSD: patch-ipc_chromium_src_base_debug__util__posic.cc,v 1.7 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/debug_util_posix.cc.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/src/base/debug_util_posix.cc
@@ -107,7 +107,7 @@ bool DebugUtil::BeingDebugged() {
   return being_debugged;
 }
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
 
 // We can look in /proc/self/status for TracerPid.  We are likely used in crash
 // handling, so we are careful not to use the heap or have side effects.
