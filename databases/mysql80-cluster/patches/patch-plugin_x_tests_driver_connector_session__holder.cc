$NetBSD: patch-plugin_x_tests_driver_connector_session__holder.cc,v 1.1 2025/10/22 07:21:48 jnemeth Exp $

--- plugin/x/tests/driver/connector/session_holder.cc.orig	2025-10-20 03:43:37.105949620 +0000
+++ plugin/x/tests/driver/connector/session_holder.cc
@@ -358,7 +358,7 @@ xcl::Handler_result Session_holder::coun
       Mysqlx::ServerMessages::descriptor()->full_name();
   const bool is_empty_message = (protobuf_message_name == server_message_name);
   const std::string &msg_name = !is_empty_message
-                                    ? msg.GetDescriptor()->full_name()
+                                    ? std::string(msg.GetDescriptor()->full_name())
                                     : server_msgs_by_id[msg_id].second;
 
   ++m_received_msg_counters[msg_name];
@@ -367,11 +367,11 @@ xcl::Handler_result Session_holder::coun
     return xcl::Handler_result::Continue;
 
   static const std::array<std::string, 5> k_notice_type_id = {
-      Mysqlx::Notice::Warning::descriptor()->full_name(),
-      Mysqlx::Notice::SessionVariableChanged::descriptor()->full_name(),
-      Mysqlx::Notice::SessionStateChanged::descriptor()->full_name(),
-      Mysqlx::Notice::GroupReplicationStateChanged::descriptor()->full_name(),
-      Mysqlx::Notice::ServerHello::descriptor()->full_name(),
+      std::string(Mysqlx::Notice::Warning::descriptor()->full_name()),
+      std::string(Mysqlx::Notice::SessionVariableChanged::descriptor()->full_name()),
+      std::string(Mysqlx::Notice::SessionStateChanged::descriptor()->full_name()),
+      std::string(Mysqlx::Notice::GroupReplicationStateChanged::descriptor()->full_name()),
+      std::string(Mysqlx::Notice::ServerHello::descriptor()->full_name()),
   };
 
   const auto notice_type =
