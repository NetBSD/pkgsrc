$NetBSD: patch-examples_loadables_getconf.c,v 1.4 2024/03/16 12:24:36 nia Exp $

Handle _SC_RTSIG_MAX not being defined (NetBSD 9) as well as other missing
definitions (_SC_REALTIME_SIGNALS, _SC_TIMER_MAX, _SC_CPUTIME,
_SC_THREAD_CPUTIME, SC_DELAYTIMER_MAX, _SC_SIGQUEUE_MAX) on earlier OS
versions.

--- examples/loadables/getconf.c.orig	2021-12-03 16:46:22.000000000 +0000
+++ examples/loadables/getconf.c
@@ -269,9 +269,15 @@ static const struct conf vars[] =
 #ifdef _SC_AVPHYS_PAGES
     { "_AVPHYS_PAGES", _SC_AVPHYS_PAGES, SYSCONF },
 #endif
+#ifdef _SC_NPROCESSORS_CONF
     { "_NPROCESSORS_CONF", _SC_NPROCESSORS_CONF, SYSCONF },
+#endif
+#ifdef _SC_NPROCESSORS_ONLN
     { "_NPROCESSORS_ONLN", _SC_NPROCESSORS_ONLN, SYSCONF },
+#endif
+#ifdef _SC_PHYS_PAGES
     { "_PHYS_PAGES", _SC_PHYS_PAGES, SYSCONF },
+#endif
 #ifdef _SC_ARG_MAX
     { "_POSIX_ARG_MAX", _SC_ARG_MAX, SYSCONF },
 #else
@@ -329,7 +335,9 @@ static const struct conf vars[] =
     { "_POSIX_PRIORITIZED_IO", _SC_PRIORITIZED_IO, SYSCONF },
 #endif
     { "_POSIX_PRIORITY_SCHEDULING", _SC_PRIORITY_SCHEDULING, SYSCONF },
+#ifdef _SC_REALTIME_SIGNALS
     { "_POSIX_REALTIME_SIGNALS", _SC_REALTIME_SIGNALS, SYSCONF },
+#endif
     { "_POSIX_SAVED_IDS", _SC_SAVED_IDS, SYSCONF },
 #ifdef _SC_SELECT
     { "_POSIX_SELECT", _SC_SELECT, SYSCONF },
@@ -366,7 +374,9 @@ static const struct conf vars[] =
     { "_POSIX_THREAD_PROCESS_SHARED", _SC_THREAD_PROCESS_SHARED, SYSCONF },
     { "_POSIX_THREAD_SAFE_FUNCTIONS", _SC_THREAD_SAFE_FUNCTIONS, SYSCONF },
     { "_POSIX_TIMERS", _SC_TIMERS, SYSCONF },
+#ifdef _SC_TIMER_MAX
     { "TIMER_MAX", _SC_TIMER_MAX, SYSCONF },
+#endif
 #ifdef _POSIX_TZNAME_MAX
     { "_POSIX_TZNAME_MAX", _SC_TZNAME_MAX, SYSCONF },
 #else
@@ -743,8 +753,12 @@ static const struct conf vars[] =
     { "_POSIX_C_LANG_SUPPORT_R", _SC_C_LANG_SUPPORT_R, SYSCONF },
 #endif
     { "_POSIX_CLOCK_SELECTION", _SC_CLOCK_SELECTION, SYSCONF },
+#ifdef _SC_CPUTIME
     { "_POSIX_CPUTIME", _SC_CPUTIME, SYSCONF },
+#endif
+#ifdef _SC_THREAD_CPUTIME
     { "_POSIX_THREAD_CPUTIME", _SC_THREAD_CPUTIME, SYSCONF },
+#endif
 #ifdef _SC_DEVICE_SPECIFIC
     { "_POSIX_DEVICE_SPECIFIC", _SC_DEVICE_SPECIFIC, SYSCONF },
 #endif
@@ -826,7 +840,9 @@ static const struct conf vars[] =
 #ifdef _SC_AIO_PRIO_DELTA_MAX
     { "AIO_PRIO_DELTA_MAX", _SC_AIO_PRIO_DELTA_MAX, SYSCONF },
 #endif
+#ifdef _SC_DELAYTIMER_MAX
     { "DELAYTIMER_MAX", _SC_DELAYTIMER_MAX, SYSCONF },
+#endif
     { "HOST_NAME_MAX", _SC_HOST_NAME_MAX, SYSCONF },
     { "LOGIN_NAME_MAX", _SC_LOGIN_NAME_MAX, SYSCONF },
     { "MQ_OPEN_MAX", _SC_MQ_OPEN_MAX, SYSCONF },
@@ -846,15 +862,21 @@ static const struct conf vars[] =
 #ifdef _SC_TRACE_LOG
     { "_POSIX_TRACE_LOG", _SC_TRACE_LOG, SYSCONF },
 #endif
+#ifdef _SC_RTSIG_MAX
     { "RTSIG_MAX", _SC_RTSIG_MAX, SYSCONF },
+#endif
 #ifdef _SC_SEM_NSEMS_MAX
     { "SEM_NSEMS_MAX", _SC_SEM_NSEMS_MAX, SYSCONF },
 #endif
 #ifdef _SC_SEM_VALUE_MAX
     { "SEM_VALUE_MAX", _SC_SEM_VALUE_MAX, SYSCONF },
 #endif
+#ifdef _SC_SIGQUEUE_MAX
     { "SIGQUEUE_MAX", _SC_SIGQUEUE_MAX, SYSCONF },
+#endif
+#ifdef _PC_FILESIZEBITS
     { "FILESIZEBITS", _PC_FILESIZEBITS, PATHCONF },
+#endif
 #ifdef _PC_ALLOC_SIZE_MIN
     { "POSIX_ALLOC_SIZE_MIN", _PC_ALLOC_SIZE_MIN, PATHCONF },
 #endif
@@ -870,7 +892,9 @@ static const struct conf vars[] =
 #ifdef _PC_REC_XFER_ALIGN
     { "POSIX_REC_XFER_ALIGN", _PC_REC_XFER_ALIGN, PATHCONF },
 #endif
+#ifdef _PC_SYMLINK_MAX
     { "SYMLINK_MAX", _PC_SYMLINK_MAX, PATHCONF },
+#endif
 #ifdef _PC_2_SYMLINKS
     { "POSIX2_SYMLINKS", _PC_2_SYMLINKS, PATHCONF },
 #endif
