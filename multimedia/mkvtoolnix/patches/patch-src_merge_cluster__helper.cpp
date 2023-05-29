$NetBSD: patch-src_merge_cluster__helper.cpp,v 1.1 2023/05/29 19:51:25 wiz Exp $

https://gitlab.com/mbunkus/mkvtoolnix/-/commit/5a0a3502d496a1a0d0881dd001bcf5888c6f88a9

--- src/merge/cluster_helper.cpp.orig	2023-04-30 10:27:25.000000000 +0000
+++ src/merge/cluster_helper.cpp
@@ -116,8 +116,8 @@ cluster_helper_c::render_before_adding_i
   timestamp_delay          = (int64_t)(timestamp_delay / g_timestamp_scale);
 
   mxdebug_if(m->debug_packets,
-             fmt::format("cluster_helper_c::add_packet(): new packet { source {0}/{1} "
-                         "timestamp: {2} duration: {3} bref: {4} fref: {5} assigned_timestamp: {6} timestamp_delay: {7} }\n",
+             fmt::format("cluster_helper_c::add_packet(): new packet {{ source {0}/{1} "
+                         "timestamp: {2} duration: {3} bref: {4} fref: {5} assigned_timestamp: {6} timestamp_delay: {7} }}\n",
                          packet->source->m_ti.m_id, packet->source->m_ti.m_fname, packet->timestamp,          packet->duration,
                          packet->bref,              packet->fref,                 packet->assigned_timestamp, mtx::string::format_timestamp(timestamp_delay)));
 
