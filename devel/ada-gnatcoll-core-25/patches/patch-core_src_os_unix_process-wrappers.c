$NetBSD: patch-core_src_os_unix_process-wrappers.c,v 1.1 2025/07/10 18:52:41 dkazankov Exp $

Add NetBSD support

--- core/src/os/unix/process-wrappers.c.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/os/unix/process-wrappers.c
@@ -28,6 +28,10 @@
 #include <unistd.h>
 #include <sys/wait.h>
 #include <signal.h>
+#if defined(__NetBSD__)
+#include <sys/select.h>
+#include <sys/time.h>
+#endif
 
 typedef long long int sint_64;
 
