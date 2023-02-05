$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.1 2023/02/05 08:32:24 he Exp $

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2020-08-28 21:32:41.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -12,7 +12,9 @@
 #if defined(OS_MACOSX)
 #  include <mach/mach.h>
 #elif defined(OS_NETBSD)
-#  include <lwp.h>
+_Pragma("GCC visibility push(default)")
+#include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #  include <sys/syscall.h>
 #  include <sys/prctl.h>
