$NetBSD: patch-src_command__file.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_file.cc.orig	2013-05-03 23:02:54.000000000 +0000
+++ src/command_file.cc
@@ -48,6 +48,16 @@
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
 void
 apply_f_set_priority(torrent::File* file, uint32_t value) {
   if (value > torrent::PRIORITY_HIGH)
@@ -100,45 +110,45 @@ apply_fi_filename_last(torrent::FileList
 
 void
 initialize_command_file() {
-  CMD2_FILE("f.is_created",             tr1::bind(&torrent::File::is_created, tr1::placeholders::_1));
-  CMD2_FILE("f.is_open",                tr1::bind(&torrent::File::is_open, tr1::placeholders::_1));
+  CMD2_FILE("f.is_created",             bind(&torrent::File::is_created, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.is_open",                bind(&torrent::File::is_open, STD_PLACEHOLDERS::_1));
 
-  CMD2_FILE("f.is_create_queued",       tr1::bind(&torrent::File::is_create_queued, tr1::placeholders::_1));
-  CMD2_FILE("f.is_resize_queued",       tr1::bind(&torrent::File::is_resize_queued, tr1::placeholders::_1));
+  CMD2_FILE("f.is_create_queued",       bind(&torrent::File::is_create_queued, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.is_resize_queued",       bind(&torrent::File::is_resize_queued, STD_PLACEHOLDERS::_1));
 
-  CMD2_FILE_VALUE_V("f.set_create_queued",   tr1::bind(&torrent::File::set_flags,   tr1::placeholders::_1, torrent::File::flag_create_queued));
-  CMD2_FILE_VALUE_V("f.set_resize_queued",   tr1::bind(&torrent::File::set_flags,   tr1::placeholders::_1, torrent::File::flag_resize_queued));
-  CMD2_FILE_VALUE_V("f.unset_create_queued", tr1::bind(&torrent::File::unset_flags, tr1::placeholders::_1, torrent::File::flag_create_queued));
-  CMD2_FILE_VALUE_V("f.unset_resize_queued", tr1::bind(&torrent::File::unset_flags, tr1::placeholders::_1, torrent::File::flag_resize_queued));
-
-  CMD2_FILE  ("f.prioritize_first",         tr1::bind(&torrent::File::has_flags,   tr1::placeholders::_1, torrent::File::flag_prioritize_first));
-  CMD2_FILE_V("f.prioritize_first.enable",  tr1::bind(&torrent::File::set_flags,   tr1::placeholders::_1, torrent::File::flag_prioritize_first));
-  CMD2_FILE_V("f.prioritize_first.disable", tr1::bind(&torrent::File::unset_flags, tr1::placeholders::_1, torrent::File::flag_prioritize_first));
-  CMD2_FILE  ("f.prioritize_last",          tr1::bind(&torrent::File::has_flags,   tr1::placeholders::_1, torrent::File::flag_prioritize_last));
-  CMD2_FILE_V("f.prioritize_last.enable",   tr1::bind(&torrent::File::set_flags,   tr1::placeholders::_1, torrent::File::flag_prioritize_last));
-  CMD2_FILE_V("f.prioritize_last.disable",  tr1::bind(&torrent::File::unset_flags, tr1::placeholders::_1, torrent::File::flag_prioritize_last));
-
-  CMD2_FILE("f.size_bytes",             tr1::bind(&torrent::File::size_bytes, tr1::placeholders::_1));
-  CMD2_FILE("f.size_chunks",            tr1::bind(&torrent::File::size_chunks, tr1::placeholders::_1));
-  CMD2_FILE("f.completed_chunks",       tr1::bind(&torrent::File::completed_chunks, tr1::placeholders::_1));
-
-  CMD2_FILE("f.offset",                 tr1::bind(&torrent::File::offset, tr1::placeholders::_1));
-  CMD2_FILE("f.range_first",            tr1::bind(&torrent::File::range_first, tr1::placeholders::_1));
-  CMD2_FILE("f.range_second",           tr1::bind(&torrent::File::range_second, tr1::placeholders::_1));
-
-  CMD2_FILE("f.priority",               tr1::bind(&torrent::File::priority, tr1::placeholders::_1));
-  CMD2_FILE_VALUE_V("f.priority.set",   tr1::bind(&apply_f_set_priority, tr1::placeholders::_1, tr1::placeholders::_2));
-
-  CMD2_FILE("f.path",                   tr1::bind(&apply_f_path, tr1::placeholders::_1));
-  CMD2_FILE("f.path_components",        tr1::bind(&apply_f_path_components, tr1::placeholders::_1));
-  CMD2_FILE("f.path_depth",             tr1::bind(&apply_f_path_depth, tr1::placeholders::_1));
-  CMD2_FILE("f.frozen_path",            tr1::bind(&torrent::File::frozen_path, tr1::placeholders::_1));
+  CMD2_FILE_VALUE_V("f.set_create_queued",   bind(&torrent::File::set_flags,   STD_PLACEHOLDERS::_1, torrent::File::flag_create_queued));
+  CMD2_FILE_VALUE_V("f.set_resize_queued",   bind(&torrent::File::set_flags,   STD_PLACEHOLDERS::_1, torrent::File::flag_resize_queued));
+  CMD2_FILE_VALUE_V("f.unset_create_queued", bind(&torrent::File::unset_flags, STD_PLACEHOLDERS::_1, torrent::File::flag_create_queued));
+  CMD2_FILE_VALUE_V("f.unset_resize_queued", bind(&torrent::File::unset_flags, STD_PLACEHOLDERS::_1, torrent::File::flag_resize_queued));
+
+  CMD2_FILE  ("f.prioritize_first",         bind(&torrent::File::has_flags,   STD_PLACEHOLDERS::_1, torrent::File::flag_prioritize_first));
+  CMD2_FILE_V("f.prioritize_first.enable",  bind(&torrent::File::set_flags,   STD_PLACEHOLDERS::_1, torrent::File::flag_prioritize_first));
+  CMD2_FILE_V("f.prioritize_first.disable", bind(&torrent::File::unset_flags, STD_PLACEHOLDERS::_1, torrent::File::flag_prioritize_first));
+  CMD2_FILE  ("f.prioritize_last",          bind(&torrent::File::has_flags,   STD_PLACEHOLDERS::_1, torrent::File::flag_prioritize_last));
+  CMD2_FILE_V("f.prioritize_last.enable",   bind(&torrent::File::set_flags,   STD_PLACEHOLDERS::_1, torrent::File::flag_prioritize_last));
+  CMD2_FILE_V("f.prioritize_last.disable",  bind(&torrent::File::unset_flags, STD_PLACEHOLDERS::_1, torrent::File::flag_prioritize_last));
+
+  CMD2_FILE("f.size_bytes",             bind(&torrent::File::size_bytes, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.size_chunks",            bind(&torrent::File::size_chunks, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.completed_chunks",       bind(&torrent::File::completed_chunks, STD_PLACEHOLDERS::_1));
+
+  CMD2_FILE("f.offset",                 bind(&torrent::File::offset, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.range_first",            bind(&torrent::File::range_first, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.range_second",           bind(&torrent::File::range_second, STD_PLACEHOLDERS::_1));
+
+  CMD2_FILE("f.priority",               bind(&torrent::File::priority, STD_PLACEHOLDERS::_1));
+  CMD2_FILE_VALUE_V("f.priority.set",   bind(&apply_f_set_priority, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
+
+  CMD2_FILE("f.path",                   bind(&apply_f_path, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.path_components",        bind(&apply_f_path_components, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.path_depth",             bind(&apply_f_path_depth, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.frozen_path",            bind(&torrent::File::frozen_path, STD_PLACEHOLDERS::_1));
 
-  CMD2_FILE("f.match_depth_prev",       tr1::bind(&torrent::File::match_depth_prev, tr1::placeholders::_1));
-  CMD2_FILE("f.match_depth_next",       tr1::bind(&torrent::File::match_depth_next, tr1::placeholders::_1));
+  CMD2_FILE("f.match_depth_prev",       bind(&torrent::File::match_depth_prev, STD_PLACEHOLDERS::_1));
+  CMD2_FILE("f.match_depth_next",       bind(&torrent::File::match_depth_next, STD_PLACEHOLDERS::_1));
 
-  CMD2_FILE("f.last_touched",           tr1::bind(&torrent::File::last_touched, tr1::placeholders::_1));
+  CMD2_FILE("f.last_touched",           bind(&torrent::File::last_touched, STD_PLACEHOLDERS::_1));
 
-  CMD2_FILEITR("fi.filename_last",      tr1::bind(&apply_fi_filename_last, tr1::placeholders::_1));
-  CMD2_FILEITR("fi.is_file",            tr1::bind(&torrent::FileListIterator::is_file, tr1::placeholders::_1));
+  CMD2_FILEITR("fi.filename_last",      bind(&apply_fi_filename_last, STD_PLACEHOLDERS::_1));
+  CMD2_FILEITR("fi.is_file",            bind(&torrent::FileListIterator::is_file, STD_PLACEHOLDERS::_1));
 }
