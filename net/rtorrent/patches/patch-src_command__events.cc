$NetBSD: patch-src_command__events.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_events.cc.orig	2013-05-03 23:02:24.000000000 +0000
+++ src/command_events.cc
@@ -60,6 +60,16 @@
 
 #include "thread_worker.h"
 
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
 torrent::Object
 apply_on_ratio(const torrent::Object& rawArgs) {
   const std::string& groupName = rawArgs.as_string();
@@ -308,31 +318,31 @@ d_multicall(const torrent::Object::list_
 
 void
 initialize_command_events() {
-  CMD2_ANY_STRING  ("on_ratio",        tr1::bind(&apply_on_ratio, tr1::placeholders::_2));
+  CMD2_ANY_STRING  ("on_ratio",        bind(&apply_on_ratio, STD_PLACEHOLDERS::_2));
 
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
+  CMD2_ANY         ("start_tied",      bind(&apply_start_tied));
+  CMD2_ANY         ("stop_untied",     bind(&apply_stop_untied));
+  CMD2_ANY         ("close_untied",    bind(&apply_close_untied));
+  CMD2_ANY         ("remove_untied",   bind(&apply_remove_untied));
+
+  CMD2_ANY_LIST    ("schedule2",        bind(&apply_schedule, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING_V("schedule_remove2", bind(&rpc::CommandScheduler::erase_str, control->command_scheduler(), STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY_STRING_V("import",          bind(&apply_import, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING_V("try_import",      bind(&apply_try_import, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY_LIST    ("load.normal",        bind(&apply_load, STD_PLACEHOLDERS::_2, core::Manager::create_quiet | core::Manager::create_tied));
+  CMD2_ANY_LIST    ("load.verbose",       bind(&apply_load, STD_PLACEHOLDERS::_2, core::Manager::create_tied));
+  CMD2_ANY_LIST    ("load.start",         bind(&apply_load, STD_PLACEHOLDERS::_2,
                                                          core::Manager::create_quiet | core::Manager::create_tied | core::Manager::create_start));
-  CMD2_ANY_LIST    ("load.start_verbose", tr1::bind(&apply_load, tr1::placeholders::_2, core::Manager::create_tied  | core::Manager::create_start));
-  CMD2_ANY_LIST    ("load.raw",           tr1::bind(&apply_load, tr1::placeholders::_2, core::Manager::create_quiet | core::Manager::create_raw_data));
-  CMD2_ANY_LIST    ("load.raw_verbose",   tr1::bind(&apply_load, tr1::placeholders::_2, core::Manager::create_raw_data));
-  CMD2_ANY_LIST    ("load.raw_start",     tr1::bind(&apply_load, tr1::placeholders::_2,
+  CMD2_ANY_LIST    ("load.start_verbose", bind(&apply_load, STD_PLACEHOLDERS::_2, core::Manager::create_tied  | core::Manager::create_start));
+  CMD2_ANY_LIST    ("load.raw",           bind(&apply_load, STD_PLACEHOLDERS::_2, core::Manager::create_quiet | core::Manager::create_raw_data));
+  CMD2_ANY_LIST    ("load.raw_verbose",   bind(&apply_load, STD_PLACEHOLDERS::_2, core::Manager::create_raw_data));
+  CMD2_ANY_LIST    ("load.raw_start",     bind(&apply_load, STD_PLACEHOLDERS::_2,
                                                          core::Manager::create_quiet | core::Manager::create_start | core::Manager::create_raw_data));
 
-  CMD2_ANY_VALUE   ("close_low_diskspace", tr1::bind(&apply_close_low_diskspace, tr1::placeholders::_2));
+  CMD2_ANY_VALUE   ("close_low_diskspace", bind(&apply_close_low_diskspace, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_LIST    ("download_list",       tr1::bind(&apply_download_list, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("d.multicall2",        tr1::bind(&d_multicall, tr1::placeholders::_2));
+  CMD2_ANY_LIST    ("download_list",       bind(&apply_download_list, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("d.multicall2",        bind(&d_multicall, STD_PLACEHOLDERS::_2));
 }
