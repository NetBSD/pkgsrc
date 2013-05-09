$NetBSD: patch-src_command__throttle.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_throttle.cc.orig	2013-05-03 23:08:41.000000000 +0000
+++ src/command_throttle.cc
@@ -51,6 +51,16 @@
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
 std::pair<uint32_t, uint32_t>
 parse_address_range(const torrent::Object::list_type& args, torrent::Object::list_type::const_iterator itr) {
   unsigned int prefixWidth, ret;
@@ -173,8 +183,8 @@ throttle_update(const char* variable, in
 
 void
 initialize_command_throttle() {
-  CMD2_ANY         ("throttle.unchoked_uploads",   tr1::bind(&torrent::ResourceManager::currently_upload_unchoked, torrent::resource_manager()));
-  CMD2_ANY         ("throttle.unchoked_downloads", tr1::bind(&torrent::ResourceManager::currently_download_unchoked, torrent::resource_manager()));
+  CMD2_ANY         ("throttle.unchoked_uploads",   bind(&torrent::ResourceManager::currently_upload_unchoked, torrent::resource_manager()));
+  CMD2_ANY         ("throttle.unchoked_downloads", bind(&torrent::ResourceManager::currently_download_unchoked, torrent::resource_manager()));
 
   CMD2_VAR_VALUE   ("throttle.min_peers.normal", 100);
   CMD2_VAR_VALUE   ("throttle.max_peers.normal", 200);
@@ -196,31 +206,31 @@ initialize_command_throttle() {
   CMD2_REDIRECT_GENERIC("throttle.max_downloads.div",    "throttle.max_downloads.div._val");
   CMD2_REDIRECT_GENERIC("throttle.max_downloads.global", "throttle.max_downloads.global._val");
 
-  CMD2_ANY_VALUE   ("throttle.max_uploads.div.set",      tr1::bind(&throttle_update, "throttle.max_uploads.div._val.set", tr1::placeholders::_2));
-  CMD2_ANY_VALUE   ("throttle.max_uploads.global.set",   tr1::bind(&throttle_update, "throttle.max_uploads.global._val.set", tr1::placeholders::_2));
-  CMD2_ANY_VALUE   ("throttle.max_downloads.div.set",    tr1::bind(&throttle_update, "throttle.max_downloads.div._val.set", tr1::placeholders::_2));
-  CMD2_ANY_VALUE   ("throttle.max_downloads.global.set", tr1::bind(&throttle_update, "throttle.max_downloads.global._val.set", tr1::placeholders::_2));
+  CMD2_ANY_VALUE   ("throttle.max_uploads.div.set",      bind(&throttle_update, "throttle.max_uploads.div._val.set", STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE   ("throttle.max_uploads.global.set",   bind(&throttle_update, "throttle.max_uploads.global._val.set", STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE   ("throttle.max_downloads.div.set",    bind(&throttle_update, "throttle.max_downloads.div._val.set", STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE   ("throttle.max_downloads.global.set", bind(&throttle_update, "throttle.max_downloads.global._val.set", STD_PLACEHOLDERS::_2));
 
   // TODO: Move the logic into some libtorrent function.
-  CMD2_ANY         ("throttle.global_up.rate",              tr1::bind(&torrent::Rate::rate, torrent::up_rate()));
-  CMD2_ANY         ("throttle.global_up.total",             tr1::bind(&torrent::Rate::total, torrent::up_rate()));
-  CMD2_ANY         ("throttle.global_up.max_rate",          tr1::bind(&torrent::Throttle::max_rate, torrent::up_throttle_global()));
-  CMD2_ANY_VALUE_V ("throttle.global_up.max_rate.set",      tr1::bind(&ui::Root::set_up_throttle_i64, control->ui(), tr1::placeholders::_2));
-  CMD2_ANY_VALUE_KB("throttle.global_up.max_rate.set_kb",   tr1::bind(&ui::Root::set_up_throttle_i64, control->ui(), tr1::placeholders::_2));
-  CMD2_ANY         ("throttle.global_down.rate",            tr1::bind(&torrent::Rate::rate, torrent::down_rate()));
-  CMD2_ANY         ("throttle.global_down.total",           tr1::bind(&torrent::Rate::total, torrent::down_rate()));
-  CMD2_ANY         ("throttle.global_down.max_rate",        tr1::bind(&torrent::Throttle::max_rate, torrent::down_throttle_global()));
-  CMD2_ANY_VALUE_V ("throttle.global_down.max_rate.set",    tr1::bind(&ui::Root::set_down_throttle_i64, control->ui(), tr1::placeholders::_2));
-  CMD2_ANY_VALUE_KB("throttle.global_down.max_rate.set_kb", tr1::bind(&ui::Root::set_down_throttle_i64, control->ui(), tr1::placeholders::_2));
+  CMD2_ANY         ("throttle.global_up.rate",              bind(&torrent::Rate::rate, torrent::up_rate()));
+  CMD2_ANY         ("throttle.global_up.total",             bind(&torrent::Rate::total, torrent::up_rate()));
+  CMD2_ANY         ("throttle.global_up.max_rate",          bind(&torrent::Throttle::max_rate, torrent::up_throttle_global()));
+  CMD2_ANY_VALUE_V ("throttle.global_up.max_rate.set",      bind(&ui::Root::set_up_throttle_i64, control->ui(), STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE_KB("throttle.global_up.max_rate.set_kb",   bind(&ui::Root::set_up_throttle_i64, control->ui(), STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("throttle.global_down.rate",            bind(&torrent::Rate::rate, torrent::down_rate()));
+  CMD2_ANY         ("throttle.global_down.total",           bind(&torrent::Rate::total, torrent::down_rate()));
+  CMD2_ANY         ("throttle.global_down.max_rate",        bind(&torrent::Throttle::max_rate, torrent::down_throttle_global()));
+  CMD2_ANY_VALUE_V ("throttle.global_down.max_rate.set",    bind(&ui::Root::set_down_throttle_i64, control->ui(), STD_PLACEHOLDERS::_2));
+  CMD2_ANY_VALUE_KB("throttle.global_down.max_rate.set_kb", bind(&ui::Root::set_down_throttle_i64, control->ui(), STD_PLACEHOLDERS::_2));
 
   // Temporary names, need to change this to accept real rates rather
   // than kB.
-  CMD2_ANY_LIST    ("throttle.up",                          tr1::bind(&apply_throttle, tr1::placeholders::_2, true));
-  CMD2_ANY_LIST    ("throttle.down",                        tr1::bind(&apply_throttle, tr1::placeholders::_2, false));
-  CMD2_ANY_LIST    ("throttle.ip",                          tr1::bind(&apply_address_throttle, tr1::placeholders::_2));
-
-  CMD2_ANY_STRING  ("throttle.up.max",    tr1::bind(&retrieve_throttle_info, tr1::placeholders::_2, throttle_info_up | throttle_info_max));
-  CMD2_ANY_STRING  ("throttle.up.rate",   tr1::bind(&retrieve_throttle_info, tr1::placeholders::_2, throttle_info_up | throttle_info_rate));
-  CMD2_ANY_STRING  ("throttle.down.max",  tr1::bind(&retrieve_throttle_info, tr1::placeholders::_2, throttle_info_down | throttle_info_max));
-  CMD2_ANY_STRING  ("throttle.down.rate", tr1::bind(&retrieve_throttle_info, tr1::placeholders::_2, throttle_info_down | throttle_info_rate));
+  CMD2_ANY_LIST    ("throttle.up",                          bind(&apply_throttle, STD_PLACEHOLDERS::_2, true));
+  CMD2_ANY_LIST    ("throttle.down",                        bind(&apply_throttle, STD_PLACEHOLDERS::_2, false));
+  CMD2_ANY_LIST    ("throttle.ip",                          bind(&apply_address_throttle, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY_STRING  ("throttle.up.max",    bind(&retrieve_throttle_info, STD_PLACEHOLDERS::_2, throttle_info_up | throttle_info_max));
+  CMD2_ANY_STRING  ("throttle.up.rate",   bind(&retrieve_throttle_info, STD_PLACEHOLDERS::_2, throttle_info_up | throttle_info_rate));
+  CMD2_ANY_STRING  ("throttle.down.max",  bind(&retrieve_throttle_info, STD_PLACEHOLDERS::_2, throttle_info_down | throttle_info_max));
+  CMD2_ANY_STRING  ("throttle.down.rate", bind(&retrieve_throttle_info, STD_PLACEHOLDERS::_2, throttle_info_down | throttle_info_rate));
 }
