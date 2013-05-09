$NetBSD: patch-src_command__groups.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_groups.cc.orig	2013-05-03 23:08:09.000000000 +0000
+++ src/command_groups.cc
@@ -52,6 +52,16 @@
 // For cg_d_group.
 #include "core/download.h"
 
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
 // A hack to allow testing of the new choke_group API without the
 // working parts present.
 #define USE_CHOKE_GROUP 0
@@ -264,8 +274,8 @@ apply_cg_tracker_mode_set(const torrent:
   return torrent::Object();
 }
 
-#define CG_GROUP_AT()          tr1::bind(&cg_get_group, tr1::placeholders::_2)
-#define CHOKE_GROUP(direction) tr1::bind(direction, CG_GROUP_AT())
+#define CG_GROUP_AT()          bind(&cg_get_group, STD_PLACEHOLDERS::_2)
+#define CHOKE_GROUP(direction) bind(direction, CG_GROUP_AT())
 
 /*
 
@@ -336,54 +346,54 @@ options.
 void
 initialize_command_groups() {
   // Move somewhere else?
-  CMD2_ANY         ("strings.choke_heuristics",          tr1::bind(&torrent::option_list_strings, torrent::OPTION_CHOKE_HEURISTICS));
-  CMD2_ANY         ("strings.choke_heuristics.upload",   tr1::bind(&torrent::option_list_strings, torrent::OPTION_CHOKE_HEURISTICS_UPLOAD));
-  CMD2_ANY         ("strings.choke_heuristics.download", tr1::bind(&torrent::option_list_strings, torrent::OPTION_CHOKE_HEURISTICS_DOWNLOAD));
-  CMD2_ANY         ("strings.tracker_mode",              tr1::bind(&torrent::option_list_strings, torrent::OPTION_TRACKER_MODE));
+  CMD2_ANY         ("strings.choke_heuristics",          bind(&torrent::option_list_strings, torrent::OPTION_CHOKE_HEURISTICS));
+  CMD2_ANY         ("strings.choke_heuristics.upload",   bind(&torrent::option_list_strings, torrent::OPTION_CHOKE_HEURISTICS_UPLOAD));
+  CMD2_ANY         ("strings.choke_heuristics.download", bind(&torrent::option_list_strings, torrent::OPTION_CHOKE_HEURISTICS_DOWNLOAD));
+  CMD2_ANY         ("strings.tracker_mode",              bind(&torrent::option_list_strings, torrent::OPTION_TRACKER_MODE));
 
-  CMD2_ANY         ("choke_group.list",                tr1::bind(&apply_cg_list));
-  CMD2_ANY_STRING  ("choke_group.insert",              tr1::bind(&apply_cg_insert, tr1::placeholders::_2));
+  CMD2_ANY         ("choke_group.list",                bind(&apply_cg_list));
+  CMD2_ANY_STRING  ("choke_group.insert",              bind(&apply_cg_insert, STD_PLACEHOLDERS::_2));
 
 #if USE_CHOKE_GROUP
-  CMD2_ANY         ("choke_group.size",                tr1::bind(&torrent::ResourceManager::group_size, torrent::resource_manager()));
-  CMD2_ANY_STRING  ("choke_group.index_of",            tr1::bind(&torrent::ResourceManager::group_index_of, torrent::resource_manager(), tr1::placeholders::_2));
+  CMD2_ANY         ("choke_group.size",                bind(&torrent::ResourceManager::group_size, torrent::resource_manager()));
+  CMD2_ANY_STRING  ("choke_group.index_of",            bind(&torrent::ResourceManager::group_index_of, torrent::resource_manager(), STD_PLACEHOLDERS::_2));
 #else
   apply_cg_insert("default");
 
-  CMD2_ANY         ("choke_group.size",                tr1::bind(&std::vector<torrent::choke_group*>::size, cg_list_hack));
-  CMD2_ANY_STRING  ("choke_group.index_of",            tr1::bind(&apply_cg_index_of, tr1::placeholders::_2));
+  CMD2_ANY         ("choke_group.size",                bind(&std::vector<torrent::choke_group*>::size, cg_list_hack));
+  CMD2_ANY_STRING  ("choke_group.index_of",            bind(&apply_cg_index_of, STD_PLACEHOLDERS::_2));
 #endif
 
   // Commands specific for a group. Supports as the first argument the
   // name, the index or a negative index.
-  CMD2_ANY         ("choke_group.general.size",        tr1::bind(&torrent::choke_group::size, CG_GROUP_AT()));
+  CMD2_ANY         ("choke_group.general.size",        bind(&torrent::choke_group::size, CG_GROUP_AT()));
 
-  CMD2_ANY         ("choke_group.tracker.mode",        tr1::bind(&torrent::option_as_string, torrent::OPTION_TRACKER_MODE,
-                                                                 tr1::bind(&torrent::choke_group::tracker_mode, CG_GROUP_AT())));
-  CMD2_ANY_LIST    ("choke_group.tracker.mode.set",    tr1::bind(&apply_cg_tracker_mode_set, tr1::placeholders::_2));
-
-  CMD2_ANY         ("choke_group.up.rate",             tr1::bind(&torrent::choke_group::up_rate, CG_GROUP_AT()));
-  CMD2_ANY         ("choke_group.down.rate",           tr1::bind(&torrent::choke_group::down_rate, CG_GROUP_AT()));
-
-  CMD2_ANY         ("choke_group.up.max.unlimited",    tr1::bind(&torrent::choke_queue::is_unlimited, CHOKE_GROUP(&torrent::choke_group::up_queue)));
-  CMD2_ANY         ("choke_group.up.max",              tr1::bind(&torrent::choke_queue::max_unchoked_signed, CHOKE_GROUP(&torrent::choke_group::up_queue)));
-  CMD2_ANY_LIST    ("choke_group.up.max.set",          tr1::bind(&apply_cg_max_set, tr1::placeholders::_2, true));
-
-  CMD2_ANY         ("choke_group.up.total",            tr1::bind(&torrent::choke_queue::size_total, CHOKE_GROUP(&torrent::choke_group::up_queue)));
-  CMD2_ANY         ("choke_group.up.queued",           tr1::bind(&torrent::choke_queue::size_queued, CHOKE_GROUP(&torrent::choke_group::up_queue)));
-  CMD2_ANY         ("choke_group.up.unchoked",         tr1::bind(&torrent::choke_queue::size_unchoked, CHOKE_GROUP(&torrent::choke_group::up_queue)));
-  CMD2_ANY         ("choke_group.up.heuristics",       tr1::bind(&torrent::option_as_string, torrent::OPTION_CHOKE_HEURISTICS,
-                                                                 tr1::bind(&torrent::choke_queue::heuristics, CHOKE_GROUP(&torrent::choke_group::up_queue))));
-  CMD2_ANY_LIST    ("choke_group.up.heuristics.set",   tr1::bind(&apply_cg_heuristics_set, tr1::placeholders::_2, true));
-
-  CMD2_ANY         ("choke_group.down.max.unlimited",  tr1::bind(&torrent::choke_queue::is_unlimited, CHOKE_GROUP(&torrent::choke_group::down_queue)));
-  CMD2_ANY         ("choke_group.down.max",            tr1::bind(&torrent::choke_queue::max_unchoked_signed, CHOKE_GROUP(&torrent::choke_group::down_queue)));
-  CMD2_ANY_LIST    ("choke_group.down.max.set",        tr1::bind(&apply_cg_max_set, tr1::placeholders::_2, false));
-
-  CMD2_ANY         ("choke_group.down.total",          tr1::bind(&torrent::choke_queue::size_total, CHOKE_GROUP(&torrent::choke_group::down_queue)));
-  CMD2_ANY         ("choke_group.down.queued",         tr1::bind(&torrent::choke_queue::size_queued, CHOKE_GROUP(&torrent::choke_group::down_queue)));
-  CMD2_ANY         ("choke_group.down.unchoked",       tr1::bind(&torrent::choke_queue::size_unchoked, CHOKE_GROUP(&torrent::choke_group::down_queue)));
-  CMD2_ANY         ("choke_group.down.heuristics",     tr1::bind(&torrent::option_as_string, torrent::OPTION_CHOKE_HEURISTICS,
-                                                                 tr1::bind(&torrent::choke_queue::heuristics, CHOKE_GROUP(&torrent::choke_group::down_queue))));
-  CMD2_ANY_LIST    ("choke_group.down.heuristics.set", tr1::bind(&apply_cg_heuristics_set, tr1::placeholders::_2, false));
+  CMD2_ANY         ("choke_group.tracker.mode",        bind(&torrent::option_as_string, torrent::OPTION_TRACKER_MODE,
+                                                                 bind(&torrent::choke_group::tracker_mode, CG_GROUP_AT())));
+  CMD2_ANY_LIST    ("choke_group.tracker.mode.set",    bind(&apply_cg_tracker_mode_set, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY         ("choke_group.up.rate",             bind(&torrent::choke_group::up_rate, CG_GROUP_AT()));
+  CMD2_ANY         ("choke_group.down.rate",           bind(&torrent::choke_group::down_rate, CG_GROUP_AT()));
+
+  CMD2_ANY         ("choke_group.up.max.unlimited",    bind(&torrent::choke_queue::is_unlimited, CHOKE_GROUP(&torrent::choke_group::up_queue)));
+  CMD2_ANY         ("choke_group.up.max",              bind(&torrent::choke_queue::max_unchoked_signed, CHOKE_GROUP(&torrent::choke_group::up_queue)));
+  CMD2_ANY_LIST    ("choke_group.up.max.set",          bind(&apply_cg_max_set, STD_PLACEHOLDERS::_2, true));
+
+  CMD2_ANY         ("choke_group.up.total",            bind(&torrent::choke_queue::size_total, CHOKE_GROUP(&torrent::choke_group::up_queue)));
+  CMD2_ANY         ("choke_group.up.queued",           bind(&torrent::choke_queue::size_queued, CHOKE_GROUP(&torrent::choke_group::up_queue)));
+  CMD2_ANY         ("choke_group.up.unchoked",         bind(&torrent::choke_queue::size_unchoked, CHOKE_GROUP(&torrent::choke_group::up_queue)));
+  CMD2_ANY         ("choke_group.up.heuristics",       bind(&torrent::option_as_string, torrent::OPTION_CHOKE_HEURISTICS,
+                                                                 bind(&torrent::choke_queue::heuristics, CHOKE_GROUP(&torrent::choke_group::up_queue))));
+  CMD2_ANY_LIST    ("choke_group.up.heuristics.set",   bind(&apply_cg_heuristics_set, STD_PLACEHOLDERS::_2, true));
+
+  CMD2_ANY         ("choke_group.down.max.unlimited",  bind(&torrent::choke_queue::is_unlimited, CHOKE_GROUP(&torrent::choke_group::down_queue)));
+  CMD2_ANY         ("choke_group.down.max",            bind(&torrent::choke_queue::max_unchoked_signed, CHOKE_GROUP(&torrent::choke_group::down_queue)));
+  CMD2_ANY_LIST    ("choke_group.down.max.set",        bind(&apply_cg_max_set, STD_PLACEHOLDERS::_2, false));
+
+  CMD2_ANY         ("choke_group.down.total",          bind(&torrent::choke_queue::size_total, CHOKE_GROUP(&torrent::choke_group::down_queue)));
+  CMD2_ANY         ("choke_group.down.queued",         bind(&torrent::choke_queue::size_queued, CHOKE_GROUP(&torrent::choke_group::down_queue)));
+  CMD2_ANY         ("choke_group.down.unchoked",       bind(&torrent::choke_queue::size_unchoked, CHOKE_GROUP(&torrent::choke_group::down_queue)));
+  CMD2_ANY         ("choke_group.down.heuristics",     bind(&torrent::option_as_string, torrent::OPTION_CHOKE_HEURISTICS,
+                                                                 bind(&torrent::choke_queue::heuristics, CHOKE_GROUP(&torrent::choke_group::down_queue))));
+  CMD2_ANY_LIST    ("choke_group.down.heuristics.set", bind(&apply_cg_heuristics_set, STD_PLACEHOLDERS::_2, false));
 }
