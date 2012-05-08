$NetBSD: patch-ipc_chromium_src_base_debug__util__posic.cc,v 1.4 2012/05/08 19:29:36 martin Exp $

# Reported upstream: https://bugzilla.mozilla.org/show_bug.cgi?id=753046

--- ipc/chromium/src/base/debug_util_posix.cc.orig	2012-03-13 01:36:53.000000000 +0000
+++ ipc/chromium/src/base/debug_util_posix.cc
@@ -5,7 +5,7 @@
 #include "build/build_config.h"
 #include "base/debug_util.h"
 
-#define MOZ_HAVE_EXECINFO_H (!defined(ANDROID) && !defined(__OpenBSD__))
+#define MOZ_HAVE_EXECINFO_H (defined(__linux__) && !defined(ANDROID))
 
 #include <errno.h>
 #include <fcntl.h>
@@ -17,8 +17,13 @@
 #include <unistd.h>
 #if MOZ_HAVE_EXECINFO_H
 #include <execinfo.h>
-#include <sys/sysctl.h>
 #endif
+#if defined(OS_DRAGONFLY) || defined(OS_FREEBSD)
+#include <sys/user.h>
+#elif defined(OS_FREEBSD)
+#include <sys/proc.h>
+#endif
+#include <sys/sysctl.h>
 
 #include "base/basictypes.h"
 #include "base/eintr_wrapper.h"
@@ -32,7 +37,7 @@ bool DebugUtil::SpawnDebuggerOnProcess(u
   return false;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
@@ -71,7 +76,13 @@ bool DebugUtil::BeingDebugged() {
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
+#if defined(OS_DRAGONFLY)
+  being_debugged = (info.kp_flags & P_TRACED) != 0;
+#elif defined(OS_FREEBSD)
+  being_debugged = (info.ki_flag & P_TRACED) != 0;
+#else
   being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
+#endif
   return being_debugged;
 }
 
