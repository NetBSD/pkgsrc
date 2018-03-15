$NetBSD: patch-native_log.c,v 1.1 2018/03/15 03:13:29 khorben Exp $

Fix build on NetBSD.

--- native/log.c.orig	2018-02-25 22:30:58.000000000 +0000
+++ native/log.c
@@ -107,7 +107,11 @@ void logLog(enum llevel_t ll, const char
         dprintf(log_fd, "%s", logLevels[ll].prefix);
     }
     if (logLevels[ll].print_funcline) {
+#ifdef __linux__
         dprintf(log_fd, "[%s][%s][%d] %s():%d ", timestr, logLevels[ll].descr, (pid_t)syscall(__NR_gettid), fn, ln);
+#else
+        dprintf(log_fd, "[%s][%s][%d] %s():%d ", timestr, logLevels[ll].descr, getpid(), fn, ln);
+#endif
     }
 
     va_list args;
