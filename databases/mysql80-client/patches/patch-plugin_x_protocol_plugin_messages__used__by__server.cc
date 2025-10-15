$NetBSD: patch-plugin_x_protocol_plugin_messages__used__by__server.cc,v 1.1 2025/10/15 03:52:37 jnemeth Exp $

--- plugin/x/protocol/plugin/messages_used_by_server.cc.orig	2025-09-26 12:39:53.077862873 +0000
+++ plugin/x/protocol/plugin/messages_used_by_server.cc
@@ -49,14 +49,14 @@ bool Messages_used_by_server::begin_vali
     const auto &message_options = message->options();
 
     if (!message_options.HasExtension(Mysqlx::server_message_id)) {
-      if (0 == m_forced_packages.count(message->file()->package()))
+      if (0 == m_forced_packages.count(std::string(message->file()->package())))
         return false;
     }
   }
 
   // Check against cycles in Message dependencies graph
   const bool was_node_visited =
-      message && 0 != m_types_done.count(message->full_name());
+      message && 0 != m_types_done.count(std::string(message->full_name()));
 
   if (nullptr == message || was_node_visited) {
     return false;
