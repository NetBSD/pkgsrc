$NetBSD: patch-src_command__local.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_local.cc.orig	2013-05-03 23:06:13.000000000 +0000
+++ src/command_local.cc
@@ -65,6 +65,16 @@
 #include "control.h"
 #include "command_helpers.h"
 
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
 typedef torrent::ChunkManager CM_t;
 typedef torrent::FileManager  FM_t;
 
@@ -326,8 +336,8 @@ initialize_command_local() {
   core::DownloadList*    dList = control->core()->download_list();
   core::DownloadStore*   dStore = control->core()->download_store();
 
-  CMD2_ANY         ("system.hostname", tr1::bind(&system_hostname));
-  CMD2_ANY         ("system.pid",      tr1::bind(&getpid));
+  CMD2_ANY         ("system.hostname", bind(&system_hostname));
+  CMD2_ANY         ("system.pid",      bind(&getpid));
 
   CMD2_VAR_C_STRING("system.api_version",           (int64_t)API_VERSION);
   CMD2_VAR_C_STRING("system.client_version",        PACKAGE_VERSION);
@@ -337,54 +347,54 @@ initialize_command_local() {
   CMD2_VAR_VALUE   ("system.file.split_size",       -1);
   CMD2_VAR_STRING  ("system.file.split_suffix",     ".part");
 
-  CMD2_ANY         ("system.file_status_cache.size",   tr1::bind(&utils::FileStatusCache::size,
+  CMD2_ANY         ("system.file_status_cache.size",   bind(&utils::FileStatusCache::size,
                                                                       (utils::FileStatusCache::base_type*)control->core()->file_status_cache()));
-  CMD2_ANY_V       ("system.file_status_cache.prune",  tr1::bind(&utils::FileStatusCache::prune, control->core()->file_status_cache()));
+  CMD2_ANY_V       ("system.file_status_cache.prune",  bind(&utils::FileStatusCache::prune, control->core()->file_status_cache()));
 
   CMD2_VAR_BOOL    ("file.prioritize_toc",          0);
   CMD2_VAR_LIST    ("file.prioritize_toc.first");
   CMD2_VAR_LIST    ("file.prioritize_toc.last");
 
-  CMD2_ANY         ("system.files.opened_counter",     tr1::bind(&FM_t::files_opened_counter, fileManager));
-  CMD2_ANY         ("system.files.closed_counter",     tr1::bind(&FM_t::files_closed_counter, fileManager));
-  CMD2_ANY         ("system.files.failed_counter",     tr1::bind(&FM_t::files_failed_counter, fileManager));
-
-  CMD2_ANY         ("system.time",                     tr1::bind(&rak::timer::seconds, &cachedTime));
-  CMD2_ANY         ("system.time_seconds",             tr1::bind(&rak::timer::current_seconds));
-  CMD2_ANY         ("system.time_usec",                tr1::bind(&rak::timer::current_usec));
-
-  CMD2_ANY_VALUE_V ("system.umask.set",                tr1::bind(&umask, tr1::placeholders::_2));
-
-  CMD2_ANY         ("system.cwd",                      tr1::bind(&system_get_cwd));
-  CMD2_ANY_STRING  ("system.cwd.set",                  tr1::bind(&system_set_cwd, tr1::placeholders::_2));
-
-  CMD2_ANY         ("pieces.sync.always_safe",         tr1::bind(&CM_t::safe_sync, chunkManager));
-  CMD2_ANY_VALUE_V ("pieces.sync.always_safe.set",     tr1::bind(&CM_t::set_safe_sync, chunkManager, tr1::placeholders::_2));
-  CMD2_ANY         ("pieces.sync.safe_free_diskspace", tr1::bind(&CM_t::safe_free_diskspace, chunkManager));
-  CMD2_ANY         ("pieces.sync.timeout",             tr1::bind(&CM_t::timeout_sync, chunkManager));
-  CMD2_ANY_VALUE_V ("pieces.sync.timeout.set",         tr1::bind(&CM_t::set_timeout_sync, chunkManager, tr1::placeholders::_2));
-  CMD2_ANY         ("pieces.sync.timeout_safe",        tr1::bind(&CM_t::timeout_safe_sync, chunkManager));
-  CMD2_ANY_VALUE_V ("pieces.sync.timeout_safe.set",    tr1::bind(&CM_t::set_timeout_safe_sync, chunkManager, tr1::placeholders::_2));
-  CMD2_ANY         ("pieces.sync.queue_size",          tr1::bind(&CM_t::sync_queue_size, chunkManager));
-
-  CMD2_ANY         ("pieces.preload.type",             tr1::bind(&CM_t::preload_type, chunkManager));
-  CMD2_ANY_VALUE_V ("pieces.preload.type.set",         tr1::bind(&CM_t::set_preload_type, chunkManager, tr1::placeholders::_2));
-  CMD2_ANY         ("pieces.preload.min_size",         tr1::bind(&CM_t::preload_min_size, chunkManager));
-  CMD2_ANY_VALUE_V ("pieces.preload.min_size.set",     tr1::bind(&CM_t::set_preload_min_size, chunkManager, tr1::placeholders::_2));
-  CMD2_ANY         ("pieces.preload.min_rate",         tr1::bind(&CM_t::preload_required_rate, chunkManager));
-  CMD2_ANY_VALUE_V ("pieces.preload.min_rate.set",     tr1::bind(&CM_t::set_preload_required_rate, chunkManager, tr1::placeholders::_2));
-
-  CMD2_ANY         ("pieces.memory.current",           tr1::bind(&CM_t::memory_usage, chunkManager));
-  CMD2_ANY         ("pieces.memory.sync_queue",        tr1::bind(&CM_t::sync_queue_memory_usage, chunkManager));
-  CMD2_ANY         ("pieces.memory.block_count",       tr1::bind(&CM_t::memory_block_count, chunkManager));
-  CMD2_ANY         ("pieces.memory.max",               tr1::bind(&CM_t::max_memory_usage, chunkManager));
-  CMD2_ANY_VALUE_V ("pieces.memory.max.set",           tr1::bind(&CM_t::set_max_memory_usage, chunkManager, tr1::placeholders::_2));
-  CMD2_ANY         ("pieces.stats_preloaded",          tr1::bind(&CM_t::stats_preloaded, chunkManager));
-  CMD2_ANY         ("pieces.stats_not_preloaded",      tr1::bind(&CM_t::stats_not_preloaded, chunkManager));
+  CMD2_ANY         ("system.files.opened_counter",     bind(&FM_t::files_opened_counter, fileManager));
+  CMD2_ANY         ("system.files.closed_counter",     bind(&FM_t::files_closed_counter, fileManager));
+  CMD2_ANY         ("system.files.failed_counter",     bind(&FM_t::files_failed_counter, fileManager));
+
+  CMD2_ANY         ("system.time",                     bind(&rak::timer::seconds, &cachedTime));
+  CMD2_ANY         ("system.time_seconds",             bind(&rak::timer::current_seconds));
+  CMD2_ANY         ("system.time_usec",                bind(&rak::timer::current_usec));
+
+  CMD2_ANY_VALUE_V ("system.umask.set",                bind(&umask, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY         ("system.cwd",                      bind(&system_get_cwd));
+  CMD2_ANY_STRING  ("system.cwd.set",                  bind(&system_set_cwd, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY         ("pieces.sync.always_safe",         bind(&CM_t::safe_sync, chunkManager));
+  CMD2_ANY_VALUE_V ("pieces.sync.always_safe.set",     bind(&CM_t::set_safe_sync, chunkManager, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("pieces.sync.safe_free_diskspace", bind(&CM_t::safe_free_diskspace, chunkManager));
+  CMD2_ANY         ("pieces.sync.timeout",             bind(&CM_t::timeout_sync, chunkManager));
+  CMD2_ANY_VALUE_V ("pieces.sync.timeout.set",         bind(&CM_t::set_timeout_sync, chunkManager, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("pieces.sync.timeout_safe",        bind(&CM_t::timeout_safe_sync, chunkManager));
+  CMD2_ANY_VALUE_V ("pieces.sync.timeout_safe.set",    bind(&CM_t::set_timeout_safe_sync, chunkManager, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("pieces.sync.queue_size",          bind(&CM_t::sync_queue_size, chunkManager));
+
+  CMD2_ANY         ("pieces.preload.type",             bind(&CM_t::preload_type, chunkManager));
+  CMD2_ANY_VALUE_V ("pieces.preload.type.set",         bind(&CM_t::set_preload_type, chunkManager, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("pieces.preload.min_size",         bind(&CM_t::preload_min_size, chunkManager));
+  CMD2_ANY_VALUE_V ("pieces.preload.min_size.set",     bind(&CM_t::set_preload_min_size, chunkManager, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("pieces.preload.min_rate",         bind(&CM_t::preload_required_rate, chunkManager));
+  CMD2_ANY_VALUE_V ("pieces.preload.min_rate.set",     bind(&CM_t::set_preload_required_rate, chunkManager, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY         ("pieces.memory.current",           bind(&CM_t::memory_usage, chunkManager));
+  CMD2_ANY         ("pieces.memory.sync_queue",        bind(&CM_t::sync_queue_memory_usage, chunkManager));
+  CMD2_ANY         ("pieces.memory.block_count",       bind(&CM_t::memory_block_count, chunkManager));
+  CMD2_ANY         ("pieces.memory.max",               bind(&CM_t::max_memory_usage, chunkManager));
+  CMD2_ANY_VALUE_V ("pieces.memory.max.set",           bind(&CM_t::set_max_memory_usage, chunkManager, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("pieces.stats_preloaded",          bind(&CM_t::stats_preloaded, chunkManager));
+  CMD2_ANY         ("pieces.stats_not_preloaded",      bind(&CM_t::stats_not_preloaded, chunkManager));
 
-  CMD2_ANY         ("pieces.stats.total_size",         tr1::bind(&apply_pieces_stats_total_size));
+  CMD2_ANY         ("pieces.stats.total_size",         bind(&apply_pieces_stats_total_size));
 
-  CMD2_ANY         ("pieces.hash.queue_size",          tr1::bind(&torrent::hash_queue_size));
+  CMD2_ANY         ("pieces.hash.queue_size",          bind(&torrent::hash_queue_size));
   CMD2_VAR_BOOL    ("pieces.hash.on_completion",       true);
 
   CMD2_VAR_STRING  ("directory.default",       "./");
@@ -393,13 +403,13 @@ initialize_command_local() {
   CMD2_VAR_BOOL    ("session.use_lock",        true);
   CMD2_VAR_BOOL    ("session.on_completion",   true);
 
-  CMD2_ANY         ("session.path",            tr1::bind(&core::DownloadStore::path, dStore));
-  CMD2_ANY_STRING_V("session.path.set",        tr1::bind(&core::DownloadStore::set_path, dStore, tr1::placeholders::_2));
+  CMD2_ANY         ("session.path",            bind(&core::DownloadStore::path, dStore));
+  CMD2_ANY_STRING_V("session.path.set",        bind(&core::DownloadStore::set_path, dStore, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_V       ("session.save",            tr1::bind(&core::DownloadList::session_save, dList));
+  CMD2_ANY_V       ("session.save",            bind(&core::DownloadList::session_save, dList));
 
 #define CMD2_EXECUTE(key, flags)                                         \
-  CMD2_ANY(key, tr1::bind(&rpc::ExecFile::execute_object, &rpc::execFile, tr1::placeholders::_2, flags));
+  CMD2_ANY(key, bind(&rpc::ExecFile::execute_object, &rpc::execFile, STD_PLACEHOLDERS::_2, flags));
 
   CMD2_EXECUTE     ("execute2",                rpc::ExecFile::flag_expand_tilde | rpc::ExecFile::flag_throw);
   CMD2_EXECUTE     ("execute.throw",           rpc::ExecFile::flag_expand_tilde | rpc::ExecFile::flag_throw);
@@ -413,25 +423,25 @@ initialize_command_local() {
   CMD2_EXECUTE     ("execute.capture",         rpc::ExecFile::flag_throw | rpc::ExecFile::flag_expand_tilde | rpc::ExecFile::flag_capture);
   CMD2_EXECUTE     ("execute.capture_nothrow", rpc::ExecFile::flag_expand_tilde | rpc::ExecFile::flag_capture);
 
-  CMD2_ANY_LIST    ("log.open_file",  tr1::bind(&apply_log_open_file, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("log.add_output", tr1::bind(&apply_log_add_output, tr1::placeholders::_2));
+  CMD2_ANY_LIST    ("log.open_file",  bind(&apply_log_open_file, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("log.add_output", bind(&apply_log_add_output, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_STRING  ("log.execute",    tr1::bind(&apply_log, tr1::placeholders::_2, 0));
-  CMD2_ANY_STRING  ("log.vmmap.dump", tr1::bind(&log_vmmap_dump, tr1::placeholders::_2));
-  CMD2_ANY_STRING_V("log.xmlrpc",     tr1::bind(&ThreadWorker::set_xmlrpc_log, worker_thread, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("log.libtorrent", tr1::bind(&apply_log_libtorrent, tr1::placeholders::_2));
+  CMD2_ANY_STRING  ("log.execute",    bind(&apply_log, STD_PLACEHOLDERS::_2, 0));
+  CMD2_ANY_STRING  ("log.vmmap.dump", bind(&log_vmmap_dump, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING_V("log.xmlrpc",     bind(&ThreadWorker::set_xmlrpc_log, worker_thread, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("log.libtorrent", bind(&apply_log_libtorrent, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_LIST    ("file.append",    tr1::bind(&cmd_file_append, tr1::placeholders::_2));
+  CMD2_ANY_LIST    ("file.append",    bind(&cmd_file_append, STD_PLACEHOLDERS::_2));
 
   // TODO: Convert to new command types:
   *rpc::command_base::argument(0) = "placeholder.0";
   *rpc::command_base::argument(1) = "placeholder.1";
   *rpc::command_base::argument(2) = "placeholder.2";
   *rpc::command_base::argument(3) = "placeholder.3";
-  CMD2_ANY_P("argument.0", tr1::bind(&rpc::command_base::argument_ref, 0));
-  CMD2_ANY_P("argument.1", tr1::bind(&rpc::command_base::argument_ref, 1));
-  CMD2_ANY_P("argument.2", tr1::bind(&rpc::command_base::argument_ref, 2));
-  CMD2_ANY_P("argument.3", tr1::bind(&rpc::command_base::argument_ref, 3));
+  CMD2_ANY_P("argument.0", bind(&rpc::command_base::argument_ref, 0));
+  CMD2_ANY_P("argument.1", bind(&rpc::command_base::argument_ref, 1));
+  CMD2_ANY_P("argument.2", bind(&rpc::command_base::argument_ref, 2));
+  CMD2_ANY_P("argument.3", bind(&rpc::command_base::argument_ref, 3));
 
-  CMD2_ANY_LIST  ("group.insert", tr1::bind(&group_insert, tr1::placeholders::_2));
+  CMD2_ANY_LIST  ("group.insert", bind(&group_insert, STD_PLACEHOLDERS::_2));
 }
