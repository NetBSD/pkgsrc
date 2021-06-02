$NetBSD: patch-native_log.c,v 1.2 2021/06/02 23:27:11 khorben Exp $

Fix build on NetBSD.

--- native/log.c.orig	2021-05-18 20:52:07.000000000 +0000
+++ native/log.c
@@ -112,10 +112,10 @@ void logLog(enum llevel_t ll, const char
     if (logLevels[ll].print_funcline) {
 #ifdef __FreeBSD__
         dprintf(log_fd, "[%s][%s][%d] %s():%d ", timestr, logLevels[ll].descr, (pid_t)pthread_getthreadid_np, fn, ln);
-#elif __OpenBSD__
-        dprintf(log_fd, "[%s][%s][%d] %s():%d ", timestr, logLevels[ll].descr, getpid(), fn, ln);
-#else
+#elif defined(__linux__)
         dprintf(log_fd, "[%s][%s][%d] %s():%d ", timestr, logLevels[ll].descr, (pid_t)syscall(__NR_gettid), fn, ln);
+#else
+        dprintf(log_fd, "[%s][%s][%d] %s():%d ", timestr, logLevels[ll].descr, getpid(), fn, ln);
 #endif
     }
 
