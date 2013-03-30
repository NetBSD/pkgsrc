$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.10 2013/03/30 20:03:09 ryoon Exp $

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2013-03-07 10:48:46.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -10,7 +10,9 @@
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
