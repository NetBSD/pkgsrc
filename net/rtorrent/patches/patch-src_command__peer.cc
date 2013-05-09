$NetBSD: patch-src_command__peer.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_peer.cc.orig	2013-05-03 23:06:44.000000000 +0000
+++ src/command_peer.cc
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
 torrent::Object
 retrieve_p_id(torrent::Peer* peer) {
   const torrent::HashString* hashString = &peer->id();
@@ -97,37 +107,37 @@ retrieve_p_completed_percent(torrent::Pe
 
 void
 initialize_command_peer() {
-  CMD2_PEER("p.id",                tr1::bind(&retrieve_p_id, tr1::placeholders::_1));
-  CMD2_PEER("p.id_html",           tr1::bind(&retrieve_p_id_html, tr1::placeholders::_1));
-  CMD2_PEER("p.client_version",    tr1::bind(&retrieve_p_client_version, tr1::placeholders::_1));
-
-  CMD2_PEER("p.options_str",       tr1::bind(&retrieve_p_options_str, tr1::placeholders::_1));
-
-  CMD2_PEER("p.is_encrypted",      tr1::bind(&torrent::Peer::is_encrypted, tr1::placeholders::_1));
-  CMD2_PEER("p.is_incoming",       tr1::bind(&torrent::Peer::is_incoming, tr1::placeholders::_1));
-  CMD2_PEER("p.is_obfuscated",     tr1::bind(&torrent::Peer::is_obfuscated, tr1::placeholders::_1));
-  CMD2_PEER("p.is_snubbed",        tr1::bind(&torrent::Peer::is_snubbed, tr1::placeholders::_1));
-
-  CMD2_PEER("p.is_unwanted",       tr1::bind(&torrent::PeerInfo::is_unwanted,  tr1::bind(&torrent::Peer::peer_info, tr1::placeholders::_1)));
-  CMD2_PEER("p.is_preferred",      tr1::bind(&torrent::PeerInfo::is_preferred, tr1::bind(&torrent::Peer::peer_info, tr1::placeholders::_1)));
-
-  CMD2_PEER("p.address",           tr1::bind(&retrieve_p_address, tr1::placeholders::_1));
-  CMD2_PEER("p.port",              tr1::bind(&retrieve_p_port, tr1::placeholders::_1));
-
-  CMD2_PEER("p.completed_percent", tr1::bind(&retrieve_p_completed_percent, tr1::placeholders::_1));
-
-  CMD2_PEER("p.up_rate",           tr1::bind(&torrent::Rate::rate,  tr1::bind(&torrent::Peer::up_rate, tr1::placeholders::_1)));
-  CMD2_PEER("p.up_total",          tr1::bind(&torrent::Rate::total, tr1::bind(&torrent::Peer::up_rate, tr1::placeholders::_1)));
-  CMD2_PEER("p.down_rate",         tr1::bind(&torrent::Rate::rate,  tr1::bind(&torrent::Peer::down_rate, tr1::placeholders::_1)));
-  CMD2_PEER("p.down_total",        tr1::bind(&torrent::Rate::total, tr1::bind(&torrent::Peer::down_rate, tr1::placeholders::_1)));
-  CMD2_PEER("p.peer_rate",         tr1::bind(&torrent::Rate::rate,  tr1::bind(&torrent::Peer::peer_rate, tr1::placeholders::_1)));
-  CMD2_PEER("p.peer_total",        tr1::bind(&torrent::Rate::total, tr1::bind(&torrent::Peer::peer_rate, tr1::placeholders::_1)));
-
-  CMD2_PEER        ("p.snubbed",     tr1::bind(&torrent::Peer::is_snubbed,  tr1::placeholders::_1));
-  CMD2_PEER_VALUE_V("p.snubbed.set", tr1::bind(&torrent::Peer::set_snubbed, tr1::placeholders::_1, tr1::placeholders::_2));
-  CMD2_PEER        ("p.banned",      tr1::bind(&torrent::Peer::is_banned,   tr1::placeholders::_1));
-  CMD2_PEER_VALUE_V("p.banned.set",  tr1::bind(&torrent::Peer::set_banned,  tr1::placeholders::_1, tr1::placeholders::_2));
+  CMD2_PEER("p.id",                bind(&retrieve_p_id, STD_PLACEHOLDERS::_1));
+  CMD2_PEER("p.id_html",           bind(&retrieve_p_id_html, STD_PLACEHOLDERS::_1));
+  CMD2_PEER("p.client_version",    bind(&retrieve_p_client_version, STD_PLACEHOLDERS::_1));
+
+  CMD2_PEER("p.options_str",       bind(&retrieve_p_options_str, STD_PLACEHOLDERS::_1));
+
+  CMD2_PEER("p.is_encrypted",      bind(&torrent::Peer::is_encrypted, STD_PLACEHOLDERS::_1));
+  CMD2_PEER("p.is_incoming",       bind(&torrent::Peer::is_incoming, STD_PLACEHOLDERS::_1));
+  CMD2_PEER("p.is_obfuscated",     bind(&torrent::Peer::is_obfuscated, STD_PLACEHOLDERS::_1));
+  CMD2_PEER("p.is_snubbed",        bind(&torrent::Peer::is_snubbed, STD_PLACEHOLDERS::_1));
+
+  CMD2_PEER("p.is_unwanted",       bind(&torrent::PeerInfo::is_unwanted,  bind(&torrent::Peer::peer_info, STD_PLACEHOLDERS::_1)));
+  CMD2_PEER("p.is_preferred",      bind(&torrent::PeerInfo::is_preferred, bind(&torrent::Peer::peer_info, STD_PLACEHOLDERS::_1)));
+
+  CMD2_PEER("p.address",           bind(&retrieve_p_address, STD_PLACEHOLDERS::_1));
+  CMD2_PEER("p.port",              bind(&retrieve_p_port, STD_PLACEHOLDERS::_1));
+
+  CMD2_PEER("p.completed_percent", bind(&retrieve_p_completed_percent, STD_PLACEHOLDERS::_1));
+
+  CMD2_PEER("p.up_rate",           bind(&torrent::Rate::rate,  bind(&torrent::Peer::up_rate, STD_PLACEHOLDERS::_1)));
+  CMD2_PEER("p.up_total",          bind(&torrent::Rate::total, bind(&torrent::Peer::up_rate, STD_PLACEHOLDERS::_1)));
+  CMD2_PEER("p.down_rate",         bind(&torrent::Rate::rate,  bind(&torrent::Peer::down_rate, STD_PLACEHOLDERS::_1)));
+  CMD2_PEER("p.down_total",        bind(&torrent::Rate::total, bind(&torrent::Peer::down_rate, STD_PLACEHOLDERS::_1)));
+  CMD2_PEER("p.peer_rate",         bind(&torrent::Rate::rate,  bind(&torrent::Peer::peer_rate, STD_PLACEHOLDERS::_1)));
+  CMD2_PEER("p.peer_total",        bind(&torrent::Rate::total, bind(&torrent::Peer::peer_rate, STD_PLACEHOLDERS::_1)));
+
+  CMD2_PEER        ("p.snubbed",     bind(&torrent::Peer::is_snubbed,  STD_PLACEHOLDERS::_1));
+  CMD2_PEER_VALUE_V("p.snubbed.set", bind(&torrent::Peer::set_snubbed, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
+  CMD2_PEER        ("p.banned",      bind(&torrent::Peer::is_banned,   STD_PLACEHOLDERS::_1));
+  CMD2_PEER_VALUE_V("p.banned.set",  bind(&torrent::Peer::set_banned,  STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
 
-  CMD2_PEER_V("p.disconnect",         tr1::bind(&torrent::Peer::disconnect, tr1::placeholders::_1, 0));
-  CMD2_PEER_V("p.disconnect_delayed", tr1::bind(&torrent::Peer::disconnect, tr1::placeholders::_1, torrent::ConnectionList::disconnect_delayed));
+  CMD2_PEER_V("p.disconnect",         bind(&torrent::Peer::disconnect, STD_PLACEHOLDERS::_1, 0));
+  CMD2_PEER_V("p.disconnect_delayed", bind(&torrent::Peer::disconnect, STD_PLACEHOLDERS::_1, torrent::ConnectionList::disconnect_delayed));
 }
