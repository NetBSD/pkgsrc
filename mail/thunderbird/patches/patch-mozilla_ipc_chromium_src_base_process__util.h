$NetBSD: patch-mozilla_ipc_chromium_src_base_process__util.h,v 1.7 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/ipc/chromium/src/base/process_util.h.orig	2016-04-07 21:33:19.000000000 +0000
+++ mozilla/ipc/chromium/src/base/process_util.h
@@ -41,6 +41,9 @@
 typedef PROCESSENTRY32 ProcessEntry;
 typedef IO_COUNTERS IoCounters;
 #elif defined(OS_POSIX)
+#ifndef NAME_MAX
+#define NAME_MAX _POSIX_NAME_MAX
+#endif
 // TODO(port): we should not rely on a Win32 structure.
 struct ProcessEntry {
   int pid;
