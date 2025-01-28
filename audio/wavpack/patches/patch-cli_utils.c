$NetBSD: patch-cli_utils.c,v 1.1 2025/01/28 12:17:44 adam Exp $

Support Darwin.
https://github.com/dbry/WavPack/pull/196

--- cli/utils.c.orig	2025-01-28 12:06:30.022371964 +0000
+++ cli/utils.c
@@ -671,7 +671,9 @@ int check_break (void)
 
 #ifdef ENABLE_THREADS
 
-#if defined(__GNUC__) && !defined(_WIN32)
+#if defined(__APPLE__) || defined(__NetBSD__)
+#include <sys/sysctl.h>
+#elif defined(__GNUC__) && !defined(_WIN32)
 #include <sys/sysinfo.h>
 #endif
 
@@ -683,6 +685,9 @@ int get_default_worker_threads (void)
     SYSTEM_INFO sysinfo;
     GetSystemInfo (&sysinfo);
     num_processors = sysinfo.dwNumberOfProcessors;
+#elif defined(__APPLE__) || defined(__NetBSD__)
+    size_t len = sizeof(num_processors);
+    sysctlbyname("hw.ncpu", &num_processors, &len, NULL, 0);
 #elif defined (__GNUC__)
     num_processors = get_nprocs ();
 #endif
