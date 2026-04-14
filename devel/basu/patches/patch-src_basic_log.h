$NetBSD: patch-src_basic_log.h,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* On NetBSD %m is only allowed in syslog(3) like functions

--- src/basic/log.h.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/basic/log.h
@@ -97,9 +97,22 @@ void log_assert_failed_return_realm(
 #define log_warning(...)   log_full(LOG_WARNING, __VA_ARGS__)
 #define log_error(...)     log_full(LOG_ERR,     __VA_ARGS__)
 
-/* Logging triggered by an errno-like error */
-#define log_debug_errno(error, ...)     log_full_errno(LOG_DEBUG,   error, __VA_ARGS__)
-#define log_notice_errno(error, ...)    log_full_errno(LOG_NOTICE,  error, __VA_ARGS__)
-#define log_error_errno(error, ...)     log_full_errno(LOG_ERR,     error, __VA_ARGS__)
+/* Logging triggered by an errno-like error
+ * On NetBSD %m is only allowed in syslog(3) like functions */
+#if defined(__NetBSD__)
+#define log_debug_errno(error, fmt, ...)     \
+        log_full_errno(LOG_DEBUG,   error, fmt ": %s", ##__VA_ARGS__, strerror(-(error)))
+#define log_notice_errno(error, fmt, ...)    \
+        log_full_errno(LOG_NOTICE,  error, fmt ": %s", ##__VA_ARGS__, strerror(-(error)))
+#define log_error_errno(error, fmt, ...)     \
+        log_full_errno(LOG_ERR,     error, fmt ": %s", ##__VA_ARGS__, strerror(-(error)))
+#else
+#define log_debug_errno(error, fmt, ...)     \
+        log_full_errno(LOG_DEBUG,   error, fmt ": %m", ##__VA_ARGS__)
+#define log_notice_errno(error, fmt, ...)    \
+        log_full_errno(LOG_NOTICE,  error, fmt ": %m", ##__VA_ARGS__)
+#define log_error_errno(error, fmt, ...)     \
+        log_full_errno(LOG_ERR,     error, fmt ": %m", ##__VA_ARGS__)
+#endif
 
 #define log_oom() log_oom_internal(LOG_REALM, __FILE__, __LINE__, __func__)
