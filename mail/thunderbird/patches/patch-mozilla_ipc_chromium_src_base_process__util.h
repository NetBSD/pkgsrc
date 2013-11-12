$NetBSD: patch-mozilla_ipc_chromium_src_base_process__util.h,v 1.5 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/process_util.h.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/src/base/process_util.h
@@ -13,7 +13,7 @@
 #if defined(OS_WIN)
 #include <windows.h>
 #include <tlhelp32.h>
-#elif defined(OS_LINUX) || defined(__GLIBC__)
+#elif defined(OS_LINUX) || defined(__GLIBC__) || defined(OS_SOLARIS)
 #include <dirent.h>
 #include <limits.h>
 #include <sys/types.h>
@@ -32,6 +32,9 @@
 typedef PROCESSENTRY32 ProcessEntry;
 typedef IO_COUNTERS IoCounters;
 #elif defined(OS_POSIX)
+#ifndef NAME_MAX
+#define NAME_MAX _POSIX_NAME_MAX
+#endif
 // TODO(port): we should not rely on a Win32 structure.
 struct ProcessEntry {
   int pid;
@@ -316,7 +319,7 @@ class NamedProcessIterator {
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_LINUX) || defined(__GLIBC__)
+#elif defined(OS_LINUX) || defined(__GLIBC__) || defined(OS_SOLARIS)
   DIR *procfs_dir_;
 #elif defined(OS_BSD)
   std::vector<ProcessEntry> content;
