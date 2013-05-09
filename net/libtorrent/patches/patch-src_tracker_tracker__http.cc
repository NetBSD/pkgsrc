$NetBSD: patch-src_tracker_tracker__http.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/tracker/tracker_http.cc.orig	2012-03-19 11:36:45.000000000 +0000
+++ src/tracker/tracker_http.cc
@@ -58,14 +58,20 @@
 #include "globals.h"
 #include "manager.h"
 
+#if __cplusplus >= 201103L
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 #define LT_LOG_TRACKER(log_level, log_fmt, ...)                         \
   lt_log_print_info(LOG_TRACKER_##log_level, m_parent->info(), "tracker", "[%u] " log_fmt, group(), __VA_ARGS__);
 
 #define LT_LOG_TRACKER_DUMP(log_level, log_dump_data, log_dump_size, log_fmt, ...)                   \
   lt_log_print_info_dump(LOG_TRACKER_##log_level, log_dump_data, log_dump_size, m_parent->info(), "tracker", "[%u] " log_fmt, group(), __VA_ARGS__);
 
-namespace tr1 { using namespace std::tr1; }
-
 namespace torrent {
 
 TrackerHttp::TrackerHttp(TrackerList* parent, const std::string& url, int flags) :
@@ -74,8 +80,8 @@ TrackerHttp::TrackerHttp(TrackerList* pa
   m_get(Http::slot_factory()()),
   m_data(NULL) {
 
-  m_get->signal_done().push_back(tr1::bind(&TrackerHttp::receive_done, this));
-  m_get->signal_failed().push_back(tr1::bind(&TrackerHttp::receive_failed, this, tr1::placeholders::_1));
+  m_get->signal_done().push_back(bind(&TrackerHttp::receive_done, this));
+  m_get->signal_failed().push_back(bind(&TrackerHttp::receive_failed, this, STD_PLACEHOLDERS::_1));
 
   // Haven't considered if this needs any stronger error detection,
   // can dropping the '?' be used for malicious purposes?
