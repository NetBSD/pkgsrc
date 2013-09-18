$NetBSD: patch-src_command__events.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/command_events.cc.orig	2012-04-18 07:55:20.000000000 +0000
+++ src/command_events.cc
@@ -60,6 +60,16 @@
 
 #include "thread_worker.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+#define STD_BIND std::bind
+#define STD_PLACEHOLDERS std::placeholders
+#else
+#include <tr1/functional>
+#define STD_BIND std::tr1::bind
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 torrent::Object
 apply_on_ratio(const torrent::Object& rawArgs) {
   const std::string& groupName = rawArgs.as_string();
@@ -308,31 +318,31 @@ d_multicall(const torrent::Object::list_
 
 void
 initialize_command_events() {
-  CMD2_ANY_STRING  ("on_ratio",        tr1::bind(&apply_on_ratio, tr1::placeholders::_2));
+  CMD2_ANY_STRING  ("on_ratio",        STD_BIND(&apply_on_ratio, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY         ("start_tied",      tr1::bind(&apply_start_tied));
-  CMD2_ANY         ("stop_untied",     tr1::bind(&apply_stop_untied));
-  CMD2_ANY         ("close_untied",    tr1::bind(&apply_close_untied));
-  CMD2_ANY         ("remove_untied",   tr1::bind(&apply_remove_untied));
-
-  CMD2_ANY_LIST    ("schedule2",        tr1::bind(&apply_schedule, tr1::placeholders::_2));
-  CMD2_ANY_STRING_V("schedule_remove2", tr1::bind(&rpc::CommandScheduler::erase_str, control->command_scheduler(), tr1::placeholders::_2));
-
-  CMD2_ANY_STRING_V("import",          tr1::bind(&apply_import, tr1::placeholders::_2));
-  CMD2_ANY_STRING_V("try_import",      tr1::bind(&apply_try_import, tr1::placeholders::_2));
-
-  CMD2_ANY_LIST    ("load.normal",        tr1::bind(&apply_load, tr1::placeholders::_2, core::Manager::create_quiet | core::Manager::create_tied));
-  CMD2_ANY_LIST    ("load.verbose",       tr1::bind(&apply_load, tr1::placeholders::_2, core::Manager::create_tied));
-  CMD2_ANY_LIST    ("load.start",         tr1::bind(&apply_load, tr1::placeholders::_2,
+  CMD2_ANY         ("start_tied",      STD_BIND(&apply_start_tied));
+  CMD2_ANY         ("stop_untied",     STD_BIND(&apply_stop_untied));
+  CMD2_ANY         ("close_untied",    STD_BIND(&apply_close_untied));
+  CMD2_ANY         ("remove_untied",   STD_BIND(&apply_remove_untied));
+
+  CMD2_ANY_LIST    ("schedule2",        STD_BIND(&apply_schedule, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING_V("schedule_remove2", STD_BIND(&rpc::CommandScheduler::erase_str, control->command_scheduler(), STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY_STRING_V("import",          STD_BIND(&apply_import, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING_V("try_import",      STD_BIND(&apply_try_import, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY_LIST    ("load.normal",        STD_BIND(&apply_load, STD_PLACEHOLDERS::_2, core::Manager::create_quiet | core::Manager::create_tied));
+  CMD2_ANY_LIST    ("load.verbose",       STD_BIND(&apply_load, STD_PLACEHOLDERS::_2, (int)core::Manager::create_tied));
+  CMD2_ANY_LIST    ("load.start",         STD_BIND(&apply_load, STD_PLACEHOLDERS::_2,
                                                          core::Manager::create_quiet | core::Manager::create_tied | core::Manager::create_start));
-  CMD2_ANY_LIST    ("load.start_verbose", tr1::bind(&apply_load, tr1::placeholders::_2, core::Manager::create_tied  | core::Manager::create_start));
-  CMD2_ANY_LIST    ("load.raw",           tr1::bind(&apply_load, tr1::placeholders::_2, core::Manager::create_quiet | core::Manager::create_raw_data));
-  CMD2_ANY_LIST    ("load.raw_verbose",   tr1::bind(&apply_load, tr1::placeholders::_2, core::Manager::create_raw_data));
-  CMD2_ANY_LIST    ("load.raw_start",     tr1::bind(&apply_load, tr1::placeholders::_2,
+  CMD2_ANY_LIST    ("load.start_verbose", STD_BIND(&apply_load, STD_PLACEHOLDERS::_2, core::Manager::create_tied  | core::Manager::create_start));
+  CMD2_ANY_LIST    ("load.raw",           STD_BIND(&apply_load, STD_PLACEHOLDERS::_2, core::Manager::create_quiet | core::Manager::create_raw_data));
+  CMD2_ANY_LIST    ("load.raw_verbose",   STD_BIND(&apply_load, STD_PLACEHOLDERS::_2, (int)core::Manager::create_raw_data));
+  CMD2_ANY_LIST    ("load.raw_start",     STD_BIND(&apply_load, STD_PLACEHOLDERS::_2,
                                                          core::Manager::create_quiet | core::Manager::create_start | core::Manager::create_raw_data));
 
-  CMD2_ANY_VALUE   ("close_low_diskspace", tr1::bind(&apply_close_low_diskspace, tr1::placeholders::_2));
+  CMD2_ANY_VALUE   ("close_low_diskspace", STD_BIND(&apply_close_low_diskspace, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_LIST    ("download_list",       tr1::bind(&apply_download_list, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("d.multicall2",        tr1::bind(&d_multicall, tr1::placeholders::_2));
+  CMD2_ANY_LIST    ("download_list",       STD_BIND(&apply_download_list, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("d.multicall2",        STD_BIND(&d_multicall, STD_PLACEHOLDERS::_2));
 }
