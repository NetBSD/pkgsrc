$NetBSD: patch-src_command__ui.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_ui.cc.orig	2013-05-03 23:09:03.000000000 +0000
+++ src/command_ui.cc
@@ -53,6 +53,16 @@
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
 typedef void (core::ViewManager::*view_cfilter_slot)(const std::string&, const torrent::Object&);
 typedef void (core::ViewManager::*view_event_slot)(const std::string&, const std::string&);
 
@@ -541,41 +551,41 @@ void
 initialize_command_ui() {
   CMD2_VAR_STRING("keys.layout", "qwerty");
 
-  CMD2_ANY_STRING("view.add", object_convert_void(tr1::bind(&core::ViewManager::insert_throw, control->view_manager(), tr1::placeholders::_2)));
+  CMD2_ANY_STRING("view.add", object_convert_void(bind(&core::ViewManager::insert_throw, control->view_manager(), STD_PLACEHOLDERS::_2)));
 
-  CMD2_ANY_L   ("view.list",          tr1::bind(&apply_view_list));
-  CMD2_ANY_LIST("view.set",           tr1::bind(&apply_view_set, tr1::placeholders::_2));
+  CMD2_ANY_L   ("view.list",          bind(&apply_view_list));
+  CMD2_ANY_LIST("view.set",           bind(&apply_view_set, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_LIST("view.filter",        tr1::bind(&apply_view_cfilter, &core::ViewManager::set_filter, tr1::placeholders::_2));
-  CMD2_ANY_LIST("view.filter_on",     tr1::bind(&apply_view_filter_on, tr1::placeholders::_2));
+  CMD2_ANY_LIST("view.filter",        bind(&apply_view_cfilter, &core::ViewManager::set_filter, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST("view.filter_on",     bind(&apply_view_filter_on, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_LIST("view.sort",          tr1::bind(&apply_view_sort, tr1::placeholders::_2));
-  CMD2_ANY_LIST("view.sort_new",      tr1::bind(&apply_view_cfilter, &core::ViewManager::set_sort_new, tr1::placeholders::_2));
-  CMD2_ANY_LIST("view.sort_current",  tr1::bind(&apply_view_cfilter, &core::ViewManager::set_sort_current, tr1::placeholders::_2));
+  CMD2_ANY_LIST("view.sort",          bind(&apply_view_sort, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST("view.sort_new",      bind(&apply_view_cfilter, &core::ViewManager::set_sort_new, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST("view.sort_current",  bind(&apply_view_cfilter, &core::ViewManager::set_sort_current, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_LIST("view.event_added",   tr1::bind(&apply_view_event, &core::ViewManager::set_event_added, tr1::placeholders::_2));
-  CMD2_ANY_LIST("view.event_removed", tr1::bind(&apply_view_event, &core::ViewManager::set_event_removed, tr1::placeholders::_2));
+  CMD2_ANY_LIST("view.event_added",   bind(&apply_view_event, &core::ViewManager::set_event_added, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST("view.event_removed", bind(&apply_view_event, &core::ViewManager::set_event_removed, STD_PLACEHOLDERS::_2));
 
   // Cleanup and add . to view.
 
-  CMD2_ANY_STRING("view.size",              tr1::bind(&cmd_view_size, tr1::placeholders::_2));
-  CMD2_ANY_STRING("view.size_not_visible",  tr1::bind(&cmd_view_size_not_visible, tr1::placeholders::_2));
-  CMD2_ANY_STRING("view.persistent",        tr1::bind(&cmd_view_persistent, tr1::placeholders::_2));
-
-  CMD2_ANY_STRING_V("view.filter_all",      tr1::bind(&core::View::filter, tr1::bind(&core::ViewManager::find_ptr_throw, control->view_manager(), tr1::placeholders::_2)));
-
-  CMD2_DL_STRING ("view.filter_download", tr1::bind(&cmd_view_filter_download, tr1::placeholders::_1, tr1::placeholders::_2));
-  CMD2_DL_STRING ("view.set_visible",     tr1::bind(&cmd_view_set_visible,     tr1::placeholders::_1, tr1::placeholders::_2));
-  CMD2_DL_STRING ("view.set_not_visible", tr1::bind(&cmd_view_set_not_visible, tr1::placeholders::_1, tr1::placeholders::_2));
+  CMD2_ANY_STRING("view.size",              bind(&cmd_view_size, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING("view.size_not_visible",  bind(&cmd_view_size_not_visible, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING("view.persistent",        bind(&cmd_view_persistent, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY_STRING_V("view.filter_all",      bind(&core::View::filter, bind(&core::ViewManager::find_ptr_throw, control->view_manager(), STD_PLACEHOLDERS::_2)));
+
+  CMD2_DL_STRING ("view.filter_download", bind(&cmd_view_filter_download, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
+  CMD2_DL_STRING ("view.set_visible",     bind(&cmd_view_set_visible,     STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
+  CMD2_DL_STRING ("view.set_not_visible", bind(&cmd_view_set_not_visible, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
 
   // Commands that affect the default rtorrent UI.
-  CMD2_DL        ("ui.unfocus_download",   tr1::bind(&cmd_ui_unfocus_download, tr1::placeholders::_1));
-  CMD2_ANY_STRING("ui.current_view.set",   tr1::bind(&cmd_ui_set_view, tr1::placeholders::_2));
+  CMD2_DL        ("ui.unfocus_download",   bind(&cmd_ui_unfocus_download, STD_PLACEHOLDERS::_1));
+  CMD2_ANY_STRING("ui.current_view.set",   bind(&cmd_ui_set_view, STD_PLACEHOLDERS::_2));
 
   // Move.
   CMD2_ANY("print", &apply_print);
   CMD2_ANY("cat",   &apply_cat);
-  CMD2_ANY("if",    tr1::bind(&apply_if, tr1::placeholders::_1, tr1::placeholders::_2, 0));
+  CMD2_ANY("if",    bind(&apply_if, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2, 0));
   CMD2_ANY("not",   &apply_not);
   CMD2_ANY("false", &apply_false);
   CMD2_ANY("and",   &apply_and);
@@ -583,22 +593,22 @@ initialize_command_ui() {
 
   // A temporary command for handling stuff until we get proper
   // support for seperation of commands and literals.
-  CMD2_ANY("branch", tr1::bind(&apply_if, tr1::placeholders::_1, tr1::placeholders::_2, 1));
+  CMD2_ANY("branch", bind(&apply_if, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2, 1));
 
   CMD2_ANY_LIST("less",    &apply_less);
   CMD2_ANY_LIST("greater", &apply_greater);
   CMD2_ANY_LIST("equal",   &apply_equal);
 
-  CMD2_ANY_VALUE("convert.gm_time",      tr1::bind(&apply_to_time, tr1::placeholders::_2, 0));
-  CMD2_ANY_VALUE("convert.gm_date",      tr1::bind(&apply_to_time, tr1::placeholders::_2, 0x2));
-  CMD2_ANY_VALUE("convert.time",         tr1::bind(&apply_to_time, tr1::placeholders::_2, 0x1));
-  CMD2_ANY_VALUE("convert.date",         tr1::bind(&apply_to_time, tr1::placeholders::_2, 0x1 | 0x2));
-  CMD2_ANY_VALUE("convert.elapsed_time", tr1::bind(&apply_to_elapsed_time, tr1::placeholders::_2));
-  CMD2_ANY_VALUE("convert.kb",           tr1::bind(&apply_to_kb, tr1::placeholders::_2));
-  CMD2_ANY_VALUE("convert.mb",           tr1::bind(&apply_to_mb, tr1::placeholders::_2));
-  CMD2_ANY_VALUE("convert.xb",           tr1::bind(&apply_to_xb, tr1::placeholders::_2));
-  CMD2_ANY_VALUE("convert.throttle",     tr1::bind(&apply_to_throttle, tr1::placeholders::_2));
+  CMD2_ANY_VALUE("convert.gm_time",      bind(&apply_to_time, STD_PLACEHOLDERS::_2, 0));
+  CMD2_ANY_VALUE("convert.gm_date",      bind(&apply_to_time, STD_PLACEHOLDERS::_2, 0x2));
+  CMD2_ANY_VALUE("convert.time",         bind(&apply_to_time, STD_PLACEHOLDERS::_2, 0x1));
+  CMD2_ANY_VALUE("convert.date",         bind(&apply_to_time, STD_PLACEHOLDERS::_2, 0x1 | 0x2));
+  CMD2_ANY_VALUE("convert.elapsed_time", bind(&apply_to_elapsed_time, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE("convert.kb",           bind(&apply_to_kb, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE("convert.mb",           bind(&apply_to_mb, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE("convert.xb",           bind(&apply_to_xb, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE("convert.throttle",     bind(&apply_to_throttle, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_LIST ("elapsed.less",         tr1::bind(&apply_elapsed_less, tr1::placeholders::_2));
-  CMD2_ANY_LIST ("elapsed.greater",      tr1::bind(&apply_elapsed_greater, tr1::placeholders::_2));
+  CMD2_ANY_LIST ("elapsed.less",         bind(&apply_elapsed_less, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST ("elapsed.greater",      bind(&apply_elapsed_greater, STD_PLACEHOLDERS::_2));
 }
