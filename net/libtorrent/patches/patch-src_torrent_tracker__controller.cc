$NetBSD: patch-src_torrent_tracker__controller.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/tracker_controller.cc.orig	2012-04-10 12:46:33.000000000 +0000
+++ src/torrent/tracker_controller.cc
@@ -50,7 +50,11 @@
 #define LT_LOG_TRACKER(log_level, log_fmt, ...)                         \
   lt_log_print_info(LOG_TRACKER_##log_level, m_tracker_list->info(), "tracker_controller", log_fmt, __VA_ARGS__);
 
-namespace tr1 { using namespace std::tr1; }
+#if __cplusplus >= 201103L
+using std::bind;
+#else
+using std::tr1::bind;
+#endif
 
 namespace torrent {
 
@@ -91,8 +95,8 @@ TrackerController::TrackerController(Tra
   m_tracker_list(trackers),
   m_private(new tracker_controller_private) {
 
-  m_private->task_timeout.slot() = std::tr1::bind(&TrackerController::do_timeout, this);
-  m_private->task_scrape.slot() = std::tr1::bind(&TrackerController::do_scrape, this);
+  m_private->task_timeout.slot() = bind(&TrackerController::do_timeout, this);
+  m_private->task_scrape.slot() = bind(&TrackerController::do_scrape, this);
 }
 
 TrackerController::~TrackerController() {
