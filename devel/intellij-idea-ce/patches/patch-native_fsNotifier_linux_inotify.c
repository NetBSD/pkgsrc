$NetBSD: patch-native_fsNotifier_linux_inotify.c,v 1.2 2014/04/24 16:19:40 ryoon Exp $

* Non-Linux (*BSD?) support

--- native/fsNotifier/linux/inotify.c.orig	2013-11-21 22:26:48.000000000 +0000
+++ native/fsNotifier/linux/inotify.c
@@ -18,7 +18,11 @@
 
 #include <dirent.h>
 #include <errno.h>
+#if defined(__linux__)
 #include <linux/limits.h>
+#else
+#include <limits.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -27,11 +31,13 @@
 #include <syslog.h>
 #include <unistd.h>
 
+#if defined(__linux__)
 #ifdef __amd64__
 __asm__(".symver memcpy,memcpy@GLIBC_2.2.5");
 #else
 __asm__(".symver memcpy,memcpy@GLIBC_2.0");
 #endif
+#endif
 
 
 #define WATCH_COUNT_NAME "/proc/sys/fs/inotify/max_user_watches"
