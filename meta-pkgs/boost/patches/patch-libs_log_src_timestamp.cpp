$NetBSD: patch-libs_log_src_timestamp.cpp,v 1.1 2014/05/13 18:48:49 ryoon Exp $

* OpenBSD 5.5 has no _POSIX_TIMES, fix build under OpenBSD 5.5

--- libs/log/src/timestamp.cpp.orig	2013-08-25 14:20:22.000000000 +0000
+++ libs/log/src/timestamp.cpp
@@ -202,7 +202,7 @@ BOOST_LOG_API get_tick_count_t get_tick_
 
 #endif // _WIN32_WINNT >= 0x0600
 
-#elif defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0
+#elif (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__OpenBSD__)
 
 BOOST_LOG_API int64_t duration::milliseconds() const
 {
