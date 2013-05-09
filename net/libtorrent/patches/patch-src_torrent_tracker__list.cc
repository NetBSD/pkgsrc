$NetBSD: patch-src_torrent_tracker__list.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/tracker_list.cc.orig	2012-04-09 06:38:58.000000000 +0000
+++ src/torrent/tracker_list.cc
@@ -56,7 +56,13 @@
 #define LT_LOG_TRACKER(log_level, log_fmt, ...)                         \
   lt_log_print_info(LOG_TRACKER_##log_level, info(), "tracker_list", log_fmt, __VA_ARGS__);
 
-namespace tr1 { using namespace std::tr1; }
+#if __cplusplus >= 201103L
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 
 namespace torrent {
 
@@ -221,8 +227,8 @@ TrackerList::insert_url(unsigned int gro
 
 TrackerList::iterator
 TrackerList::find_url(const std::string& url) {
-  return std::find_if(begin(), end(), tr1::bind(std::equal_to<std::string>(), url,
-                                                tr1::bind(&Tracker::url, tr1::placeholders::_1)));
+  return std::find_if(begin(), end(), bind(std::equal_to<std::string>(), url,
+                                                bind(&Tracker::url, STD_PLACEHOLDERS::_1)));
 }
 
 TrackerList::iterator
