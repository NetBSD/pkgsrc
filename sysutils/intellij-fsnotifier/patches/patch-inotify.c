$NetBSD: patch-inotify.c,v 1.1 2024/12/12 15:21:57 ryoon Exp $

--- inotify.c.orig	2023-07-24 21:16:54.000000000 +0000
+++ inotify.c
@@ -45,7 +45,12 @@ static void watch_limit_reached(void);
 static bool watch_count_initialised = false;
 static void init_watch_count(void) {
   size_t len = 4;
+#if !defined(__NetBSD__)
   sysctlbyname("kern.maxfilesperproc", &watch_count, &len, NULL, 0);
+#else
+  sysctlbyname("kern.maxfiles", &watch_count, &len, NULL, 0);
+  watch_count = watch_count / 100;
+#endif
   userlog(LOG_INFO, "kern.maxfilesperproc=%d", watch_count);
 
   userlog(LOG_INFO, 
