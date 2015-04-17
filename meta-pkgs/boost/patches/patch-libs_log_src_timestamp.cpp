$NetBSD: patch-libs_log_src_timestamp.cpp,v 1.2 2015/04/17 14:04:47 adam Exp $

* OpenBSD 5.5 has no _POSIX_TIMES, fix build under OpenBSD 5.5

--- libs/log/src/timestamp.cpp.orig	2015-04-04 17:33:00.000000000 +0000
+++ libs/log/src/timestamp.cpp
@@ -203,6 +203,7 @@ BOOST_LOG_API get_tick_count_t get_tick_
 #endif // _WIN32_WINNT >= 0x0600
 
 #elif (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)  /* POSIX timers supported */ \
+      || defined(__OpenBSD__) \
       || defined(__GNU__)  /* GNU Hurd does not support POSIX timers fully but does provide clock_gettime() */
 
 BOOST_LOG_API int64_t duration::milliseconds() const
