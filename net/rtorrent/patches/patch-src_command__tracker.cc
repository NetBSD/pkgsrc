$NetBSD: patch-src_command__tracker.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_tracker.cc.orig	2013-05-03 23:08:53.000000000 +0000
+++ src/command_tracker.cc
@@ -51,6 +51,16 @@
 #include "command_helpers.h"
 #include "core/dht_manager.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 void
 tracker_set_enabled(torrent::Tracker* tracker, bool state) {
   if (state)
@@ -111,59 +121,59 @@ apply_enable_trackers(int64_t arg) {
 
 void
 initialize_command_tracker() {
-  CMD2_TRACKER        ("t.is_open",           tr1::bind(&torrent::Tracker::is_busy, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.is_enabled",        tr1::bind(&torrent::Tracker::is_enabled, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.is_usable",         tr1::bind(&torrent::Tracker::is_usable, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.is_busy",           tr1::bind(&torrent::Tracker::is_busy, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.is_extra_tracker",  tr1::bind(&torrent::Tracker::is_extra_tracker, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.can_scrape",        tr1::bind(&torrent::Tracker::can_scrape, tr1::placeholders::_1));
-
-  CMD2_TRACKER_V      ("t.enable",            tr1::bind(&torrent::Tracker::enable, tr1::placeholders::_1));
-  CMD2_TRACKER_V      ("t.disable",           tr1::bind(&torrent::Tracker::disable, tr1::placeholders::_1));
-
-  CMD2_TRACKER_VALUE_V("t.is_enabled.set",    tr1::bind(&tracker_set_enabled, tr1::placeholders::_1, tr1::placeholders::_2));
-
-  CMD2_TRACKER        ("t.url",               tr1::bind(&torrent::Tracker::url, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.group",             tr1::bind(&torrent::Tracker::group, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.type",              tr1::bind(&torrent::Tracker::type, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.id",                tr1::bind(&torrent::Tracker::tracker_id, tr1::placeholders::_1));
-
-  CMD2_TRACKER        ("t.latest_event",      tr1::bind(&torrent::Tracker::latest_event, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.latest_new_peers",  tr1::bind(&torrent::Tracker::latest_new_peers, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.latest_sum_peers",  tr1::bind(&torrent::Tracker::latest_sum_peers, tr1::placeholders::_1));
+  CMD2_TRACKER        ("t.is_open",           bind(&torrent::Tracker::is_busy, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.is_enabled",        bind(&torrent::Tracker::is_enabled, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.is_usable",         bind(&torrent::Tracker::is_usable, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.is_busy",           bind(&torrent::Tracker::is_busy, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.is_extra_tracker",  bind(&torrent::Tracker::is_extra_tracker, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.can_scrape",        bind(&torrent::Tracker::can_scrape, STD_PLACEHOLDERS::_1));
+
+  CMD2_TRACKER_V      ("t.enable",            bind(&torrent::Tracker::enable, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER_V      ("t.disable",           bind(&torrent::Tracker::disable, STD_PLACEHOLDERS::_1));
+
+  CMD2_TRACKER_VALUE_V("t.is_enabled.set",    bind(&tracker_set_enabled, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
+
+  CMD2_TRACKER        ("t.url",               bind(&torrent::Tracker::url, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.group",             bind(&torrent::Tracker::group, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.type",              bind(&torrent::Tracker::type, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.id",                bind(&torrent::Tracker::tracker_id, STD_PLACEHOLDERS::_1));
+
+  CMD2_TRACKER        ("t.latest_event",      bind(&torrent::Tracker::latest_event, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.latest_new_peers",  bind(&torrent::Tracker::latest_new_peers, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.latest_sum_peers",  bind(&torrent::Tracker::latest_sum_peers, STD_PLACEHOLDERS::_1));
 
   // Time since last connection, connection attempt.
 
-  CMD2_TRACKER        ("t.normal_interval",   tr1::bind(&torrent::Tracker::normal_interval, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.min_interval",      tr1::bind(&torrent::Tracker::min_interval, tr1::placeholders::_1));
+  CMD2_TRACKER        ("t.normal_interval",   bind(&torrent::Tracker::normal_interval, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.min_interval",      bind(&torrent::Tracker::min_interval, STD_PLACEHOLDERS::_1));
 
-  CMD2_TRACKER        ("t.activity_time_next", tr1::bind(&torrent::Tracker::activity_time_next, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.activity_time_last", tr1::bind(&torrent::Tracker::activity_time_last, tr1::placeholders::_1));
+  CMD2_TRACKER        ("t.activity_time_next", bind(&torrent::Tracker::activity_time_next, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.activity_time_last", bind(&torrent::Tracker::activity_time_last, STD_PLACEHOLDERS::_1));
 
-  CMD2_TRACKER        ("t.success_time_next", tr1::bind(&torrent::Tracker::success_time_next, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.success_time_last", tr1::bind(&torrent::Tracker::success_time_last, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.success_counter",   tr1::bind(&torrent::Tracker::success_counter, tr1::placeholders::_1));
+  CMD2_TRACKER        ("t.success_time_next", bind(&torrent::Tracker::success_time_next, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.success_time_last", bind(&torrent::Tracker::success_time_last, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.success_counter",   bind(&torrent::Tracker::success_counter, STD_PLACEHOLDERS::_1));
 
-  CMD2_TRACKER        ("t.failed_time_next",  tr1::bind(&torrent::Tracker::failed_time_next, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.failed_time_last",  tr1::bind(&torrent::Tracker::failed_time_last, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.failed_counter",    tr1::bind(&torrent::Tracker::failed_counter, tr1::placeholders::_1));
+  CMD2_TRACKER        ("t.failed_time_next",  bind(&torrent::Tracker::failed_time_next, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.failed_time_last",  bind(&torrent::Tracker::failed_time_last, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.failed_counter",    bind(&torrent::Tracker::failed_counter, STD_PLACEHOLDERS::_1));
 
-  CMD2_TRACKER        ("t.scrape_time_last",  tr1::bind(&torrent::Tracker::scrape_time_last, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.scrape_counter",    tr1::bind(&torrent::Tracker::scrape_counter, tr1::placeholders::_1));
+  CMD2_TRACKER        ("t.scrape_time_last",  bind(&torrent::Tracker::scrape_time_last, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.scrape_counter",    bind(&torrent::Tracker::scrape_counter, STD_PLACEHOLDERS::_1));
 
-  CMD2_TRACKER        ("t.scrape_complete",   tr1::bind(&torrent::Tracker::scrape_complete, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.scrape_incomplete", tr1::bind(&torrent::Tracker::scrape_incomplete, tr1::placeholders::_1));
-  CMD2_TRACKER        ("t.scrape_downloaded", tr1::bind(&torrent::Tracker::scrape_downloaded, tr1::placeholders::_1));
+  CMD2_TRACKER        ("t.scrape_complete",   bind(&torrent::Tracker::scrape_complete, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.scrape_incomplete", bind(&torrent::Tracker::scrape_incomplete, STD_PLACEHOLDERS::_1));
+  CMD2_TRACKER        ("t.scrape_downloaded", bind(&torrent::Tracker::scrape_downloaded, STD_PLACEHOLDERS::_1));
 
-  CMD2_ANY_VALUE      ("trackers.enable",     tr1::bind(&apply_enable_trackers, int64_t(1)));
-  CMD2_ANY_VALUE      ("trackers.disable",    tr1::bind(&apply_enable_trackers, int64_t(0)));
+  CMD2_ANY_VALUE      ("trackers.enable",     bind(&apply_enable_trackers, int64_t(1)));
+  CMD2_ANY_VALUE      ("trackers.disable",    bind(&apply_enable_trackers, int64_t(0)));
   CMD2_VAR_VALUE      ("trackers.numwant",    -1);
   CMD2_VAR_BOOL       ("trackers.use_udp",    true);
 
-  CMD2_ANY_STRING_V   ("dht.mode.set",          tr1::bind(&core::DhtManager::set_mode, control->dht_manager(), tr1::placeholders::_2));
+  CMD2_ANY_STRING_V   ("dht.mode.set",          bind(&core::DhtManager::set_mode, control->dht_manager(), STD_PLACEHOLDERS::_2));
   CMD2_VAR_VALUE      ("dht.port",              int64_t(6881));
-  CMD2_ANY_STRING     ("dht.add_node",          tr1::bind(&apply_dht_add_node, tr1::placeholders::_2));
-  CMD2_ANY            ("dht.statistics",        tr1::bind(&core::DhtManager::dht_statistics, control->dht_manager()));
-  CMD2_ANY            ("dht.throttle.name",     tr1::bind(&core::DhtManager::throttle_name, control->dht_manager()));
-  CMD2_ANY_STRING_V   ("dht.throttle.name.set", tr1::bind(&core::DhtManager::set_throttle_name, control->dht_manager(), tr1::placeholders::_2));
+  CMD2_ANY_STRING     ("dht.add_node",          bind(&apply_dht_add_node, STD_PLACEHOLDERS::_2));
+  CMD2_ANY            ("dht.statistics",        bind(&core::DhtManager::dht_statistics, control->dht_manager()));
+  CMD2_ANY            ("dht.throttle.name",     bind(&core::DhtManager::throttle_name, control->dht_manager()));
+  CMD2_ANY_STRING_V   ("dht.throttle.name.set", bind(&core::DhtManager::set_throttle_name, control->dht_manager(), STD_PLACEHOLDERS::_2));
 }
