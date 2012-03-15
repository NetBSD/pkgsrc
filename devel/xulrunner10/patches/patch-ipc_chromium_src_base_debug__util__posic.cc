$NetBSD: patch-ipc_chromium_src_base_debug__util__posic.cc,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- ipc/chromium/src/base/debug_util_posix.cc.orig	2012-03-09 22:20:16.000000000 +0000
+++ ipc/chromium/src/base/debug_util_posix.cc
@@ -5,7 +5,7 @@
 #include "build/build_config.h"
 #include "base/debug_util.h"
 
-#define MOZ_HAVE_EXECINFO_H (!defined(ANDROID) && !defined(__OpenBSD__))
+#define MOZ_HAVE_EXECINFO_H (defined(__linux__) && !defined(ANDROID))
 
 #include <errno.h>
 #include <fcntl.h>
@@ -17,8 +17,11 @@
 #include <unistd.h>
 #if MOZ_HAVE_EXECINFO_H
 #include <execinfo.h>
-#include <sys/sysctl.h>
 #endif
+#if defined(OS_DRAGONFLY)
+#include <sys/user.h>
+#endif
+#include <sys/sysctl.h>
 
 #include "base/basictypes.h"
 #include "base/eintr_wrapper.h"
@@ -32,7 +35,7 @@ bool DebugUtil::SpawnDebuggerOnProcess(u
   return false;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
@@ -71,7 +74,11 @@ bool DebugUtil::BeingDebugged() {
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
+#if defined(__DragonFly__)
+  being_debugged = (info.kp_flags & P_TRACED) != 0;
+#else
   being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
+#endif
   return being_debugged;
 }
 
