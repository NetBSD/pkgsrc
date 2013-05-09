$NetBSD: patch-src_tracker_tracker__udp.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/tracker/tracker_udp.cc.orig	2012-04-20 06:42:32.000000000 +0000
+++ src/tracker/tracker_udp.cc
@@ -56,6 +56,12 @@
 #include "tracker_udp.h"
 #include "manager.h"
 
+#if __cplusplus >= 201103L
+using std::bind;
+#else
+using std::tr1::bind;
+#endif
+
 #define LT_LOG_TRACKER(log_level, log_fmt, ...)                         \
   lt_log_print_info(LOG_TRACKER_##log_level, m_parent->info(), "tracker", "[%u] " log_fmt, group(), __VA_ARGS__);
 
@@ -71,7 +77,7 @@ TrackerUdp::TrackerUdp(TrackerList* pare
   m_readBuffer(NULL),
   m_writeBuffer(NULL) {
 
-  m_taskTimeout.slot() = std::tr1::bind(&TrackerUdp::receive_timeout, this);
+  m_taskTimeout.slot() = bind(&TrackerUdp::receive_timeout, this);
 }
 
 TrackerUdp::~TrackerUdp() {
