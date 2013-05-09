$NetBSD: patch-src_command__network.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_network.cc.orig	2013-05-03 23:07:09.000000000 +0000
+++ src/command_network.cc
@@ -62,7 +62,15 @@
 #include "control.h"
 #include "command_helpers.h"
 
-namespace tr1 { using namespace std::tr1; }
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 
 torrent::Object
 apply_encryption(const torrent::Object::list_type& args) {
@@ -126,10 +134,10 @@ xmlrpc_find_peer(core::Download* downloa
 void
 initialize_xmlrpc() {
   rpc::xmlrpc.initialize();
-  rpc::xmlrpc.slot_find_download() = tr1::bind(&core::DownloadList::find_hex_ptr, control->core()->download_list(), tr1::placeholders::_1);
-  rpc::xmlrpc.slot_find_file() = tr1::bind(&xmlrpc_find_file, tr1::placeholders::_1, tr1::placeholders::_2);
-  rpc::xmlrpc.slot_find_tracker() = tr1::bind(&xmlrpc_find_tracker, tr1::placeholders::_1, tr1::placeholders::_2);
-  rpc::xmlrpc.slot_find_peer() = tr1::bind(&xmlrpc_find_peer, tr1::placeholders::_1, tr1::placeholders::_2);
+  rpc::xmlrpc.slot_find_download() = bind(&core::DownloadList::find_hex_ptr, control->core()->download_list(), STD_PLACEHOLDERS::_1);
+  rpc::xmlrpc.slot_find_file() = bind(&xmlrpc_find_file, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2);
+  rpc::xmlrpc.slot_find_tracker() = bind(&xmlrpc_find_tracker, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2);
+  rpc::xmlrpc.slot_find_peer() = bind(&xmlrpc_find_peer, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2);
 
   unsigned int count = 0;
 
@@ -236,23 +244,23 @@ initialize_command_network() {
   torrent::FileManager* fileManager = torrent::file_manager();
   core::CurlStack* httpStack = control->core()->http_stack();
 
-  CMD2_ANY         ("strings.connection_type", tr1::bind(&torrent::option_list_strings, torrent::OPTION_CONNECTION_TYPE));
-  CMD2_ANY         ("strings.encryption",      tr1::bind(&torrent::option_list_strings, torrent::OPTION_ENCRYPTION));
+  CMD2_ANY         ("strings.connection_type", bind(&torrent::option_list_strings, torrent::OPTION_CONNECTION_TYPE));
+  CMD2_ANY         ("strings.encryption",      bind(&torrent::option_list_strings, torrent::OPTION_ENCRYPTION));
 
   CMD2_VAR_BOOL    ("log.handshake", false);
 
-  // CMD2_ANY_STRING  ("encoding_list",    tr1::bind(&apply_encoding_list, tr1::placeholders::_2));
-  CMD2_ANY_STRING  ("encoding.add", tr1::bind(&apply_encoding_list, tr1::placeholders::_2));
+  // CMD2_ANY_STRING  ("encoding_list",    bind(&apply_encoding_list, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING  ("encoding.add", bind(&apply_encoding_list, STD_PLACEHOLDERS::_2));
 
   // Isn't port_open used?
   CMD2_VAR_BOOL    ("network.port_open",   true);
   CMD2_VAR_BOOL    ("network.port_random", true);
   CMD2_VAR_STRING  ("network.port_range",  "6881-6999");
 
-  CMD2_ANY         ("network.listen.port",    tr1::bind(&torrent::ConnectionManager::listen_port, cm));
+  CMD2_ANY         ("network.listen.port",    bind(&torrent::ConnectionManager::listen_port, cm));
 
   CMD2_VAR_BOOL    ("protocol.pex",            true);
-  CMD2_ANY_LIST    ("protocol.encryption.set", tr1::bind(&apply_encryption, tr1::placeholders::_2));
+  CMD2_ANY_LIST    ("protocol.encryption.set", bind(&apply_encryption, STD_PLACEHOLDERS::_2));
 
   CMD2_VAR_STRING  ("protocol.connection.leech", "leech");
   CMD2_VAR_STRING  ("protocol.connection.seed",  "seed");
@@ -262,43 +270,43 @@ initialize_command_network() {
   CMD2_VAR_STRING  ("protocol.choke_heuristics.down.leech", "download_leech");
   CMD2_VAR_STRING  ("protocol.choke_heuristics.down.seed",  "download_leech");
 
-  CMD2_ANY         ("network.http.capath",                tr1::bind(&core::CurlStack::http_capath, httpStack));
-  CMD2_ANY_STRING_V("network.http.capath.set",            tr1::bind(&core::CurlStack::set_http_capath, httpStack, tr1::placeholders::_2));
-  CMD2_ANY         ("network.http.cacert",                tr1::bind(&core::CurlStack::http_cacert, httpStack));
-  CMD2_ANY_STRING_V("network.http.cacert.set",            tr1::bind(&core::CurlStack::set_http_cacert, httpStack, tr1::placeholders::_2));
-  CMD2_ANY         ("network.http.proxy_address",         tr1::bind(&core::CurlStack::http_proxy, httpStack));
-  CMD2_ANY_STRING_V("network.http.proxy_address.set",     tr1::bind(&core::CurlStack::set_http_proxy, httpStack, tr1::placeholders::_2));
-  CMD2_ANY         ("network.http.max_open",              tr1::bind(&core::CurlStack::max_active, httpStack));
-  CMD2_ANY_VALUE_V ("network.http.max_open.set",          tr1::bind(&core::CurlStack::set_max_active, httpStack, tr1::placeholders::_2));
-  CMD2_ANY         ("network.http.ssl_verify_peer",       tr1::bind(&core::CurlStack::ssl_verify_peer, httpStack));
-  CMD2_ANY_VALUE_V ("network.http.ssl_verify_peer.set",   tr1::bind(&core::CurlStack::set_ssl_verify_peer, httpStack, tr1::placeholders::_2));
-  CMD2_ANY         ("network.http.dns_cache_timeout",     tr1::bind(&core::CurlStack::dns_timeout, httpStack));
-  CMD2_ANY_VALUE_V ("network.http.dns_cache_timeout.set", tr1::bind(&core::CurlStack::set_dns_timeout, httpStack, tr1::placeholders::_2));
-
-  CMD2_ANY         ("network.send_buffer.size",        tr1::bind(&torrent::ConnectionManager::send_buffer_size, cm));
-  CMD2_ANY_VALUE_V ("network.send_buffer.size.set",    tr1::bind(&torrent::ConnectionManager::set_send_buffer_size, cm, tr1::placeholders::_2));
-  CMD2_ANY         ("network.receive_buffer.size",     tr1::bind(&torrent::ConnectionManager::receive_buffer_size, cm));
-  CMD2_ANY_VALUE_V ("network.receive_buffer.size.set", tr1::bind(&torrent::ConnectionManager::set_receive_buffer_size, cm, tr1::placeholders::_2));
-  CMD2_ANY_STRING  ("network.tos.set",                 tr1::bind(&apply_tos, tr1::placeholders::_2));
-
-  CMD2_ANY         ("network.bind_address",        tr1::bind(&core::Manager::bind_address, control->core()));
-  CMD2_ANY_STRING_V("network.bind_address.set",    tr1::bind(&core::Manager::set_bind_address, control->core(), tr1::placeholders::_2));
-  CMD2_ANY         ("network.local_address",       tr1::bind(&core::Manager::local_address, control->core()));
-  CMD2_ANY_STRING_V("network.local_address.set",   tr1::bind(&core::Manager::set_local_address, control->core(), tr1::placeholders::_2));
-  CMD2_ANY         ("network.proxy_address",       tr1::bind(&core::Manager::proxy_address, control->core()));
-  CMD2_ANY_STRING_V("network.proxy_address.set",   tr1::bind(&core::Manager::set_proxy_address, control->core(), tr1::placeholders::_2));
-
-  CMD2_ANY         ("network.max_open_files",       tr1::bind(&torrent::FileManager::max_open_files, fileManager));
-  CMD2_ANY_VALUE_V ("network.max_open_files.set",   tr1::bind(&torrent::FileManager::set_max_open_files, fileManager, tr1::placeholders::_2));
-  CMD2_ANY         ("network.open_sockets",         tr1::bind(&torrent::ConnectionManager::size, cm));
-  CMD2_ANY         ("network.max_open_sockets",     tr1::bind(&torrent::ConnectionManager::max_size, cm));
-  CMD2_ANY_VALUE_V ("network.max_open_sockets.set", tr1::bind(&torrent::ConnectionManager::set_max_size, cm, tr1::placeholders::_2));
+  CMD2_ANY         ("network.http.capath",                bind(&core::CurlStack::http_capath, httpStack));
+  CMD2_ANY_STRING_V("network.http.capath.set",            bind(&core::CurlStack::set_http_capath, httpStack, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.http.cacert",                bind(&core::CurlStack::http_cacert, httpStack));
+  CMD2_ANY_STRING_V("network.http.cacert.set",            bind(&core::CurlStack::set_http_cacert, httpStack, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.http.proxy_address",         bind(&core::CurlStack::http_proxy, httpStack));
+  CMD2_ANY_STRING_V("network.http.proxy_address.set",     bind(&core::CurlStack::set_http_proxy, httpStack, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.http.max_open",              bind(&core::CurlStack::max_active, httpStack));
+  CMD2_ANY_VALUE_V ("network.http.max_open.set",          bind(&core::CurlStack::set_max_active, httpStack, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.http.ssl_verify_peer",       bind(&core::CurlStack::ssl_verify_peer, httpStack));
+  CMD2_ANY_VALUE_V ("network.http.ssl_verify_peer.set",   bind(&core::CurlStack::set_ssl_verify_peer, httpStack, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.http.dns_cache_timeout",     bind(&core::CurlStack::dns_timeout, httpStack));
+  CMD2_ANY_VALUE_V ("network.http.dns_cache_timeout.set", bind(&core::CurlStack::set_dns_timeout, httpStack, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY         ("network.send_buffer.size",        bind(&torrent::ConnectionManager::send_buffer_size, cm));
+  CMD2_ANY_VALUE_V ("network.send_buffer.size.set",    bind(&torrent::ConnectionManager::set_send_buffer_size, cm, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.receive_buffer.size",     bind(&torrent::ConnectionManager::receive_buffer_size, cm));
+  CMD2_ANY_VALUE_V ("network.receive_buffer.size.set", bind(&torrent::ConnectionManager::set_receive_buffer_size, cm, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING  ("network.tos.set",                 bind(&apply_tos, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY         ("network.bind_address",        bind(&core::Manager::bind_address, control->core()));
+  CMD2_ANY_STRING_V("network.bind_address.set",    bind(&core::Manager::set_bind_address, control->core(), STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.local_address",       bind(&core::Manager::local_address, control->core()));
+  CMD2_ANY_STRING_V("network.local_address.set",   bind(&core::Manager::set_local_address, control->core(), STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.proxy_address",       bind(&core::Manager::proxy_address, control->core()));
+  CMD2_ANY_STRING_V("network.proxy_address.set",   bind(&core::Manager::set_proxy_address, control->core(), STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY         ("network.max_open_files",       bind(&torrent::FileManager::max_open_files, fileManager));
+  CMD2_ANY_VALUE_V ("network.max_open_files.set",   bind(&torrent::FileManager::set_max_open_files, fileManager, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.open_sockets",         bind(&torrent::ConnectionManager::size, cm));
+  CMD2_ANY         ("network.max_open_sockets",     bind(&torrent::ConnectionManager::max_size, cm));
+  CMD2_ANY_VALUE_V ("network.max_open_sockets.set", bind(&torrent::ConnectionManager::set_max_size, cm, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_STRING  ("network.scgi.open_port",   tr1::bind(&apply_scgi, tr1::placeholders::_2, 1));
-  CMD2_ANY_STRING  ("network.scgi.open_local",  tr1::bind(&apply_scgi, tr1::placeholders::_2, 2));
+  CMD2_ANY_STRING  ("network.scgi.open_port",   bind(&apply_scgi, STD_PLACEHOLDERS::_2, 1));
+  CMD2_ANY_STRING  ("network.scgi.open_local",  bind(&apply_scgi, STD_PLACEHOLDERS::_2, 2));
   CMD2_VAR_BOOL    ("network.scgi.dont_route",  false);
 
-  CMD2_ANY_STRING  ("network.xmlrpc.dialect.set",    tr1::bind(&apply_xmlrpc_dialect, tr1::placeholders::_2));
-  CMD2_ANY         ("network.xmlrpc.size_limit",     tr1::bind(&rpc::XmlRpc::size_limit));
-  CMD2_ANY_VALUE_V ("network.xmlrpc.size_limit.set", tr1::bind(&rpc::XmlRpc::set_size_limit, tr1::placeholders::_2));
+  CMD2_ANY_STRING  ("network.xmlrpc.dialect.set",    bind(&apply_xmlrpc_dialect, STD_PLACEHOLDERS::_2));
+  CMD2_ANY         ("network.xmlrpc.size_limit",     bind(&rpc::XmlRpc::size_limit));
+  CMD2_ANY_VALUE_V ("network.xmlrpc.size_limit.set", bind(&rpc::XmlRpc::set_size_limit, STD_PLACEHOLDERS::_2));
 }
