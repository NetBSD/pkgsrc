$NetBSD: patch-plugin_x_protocol_plugin_message__field__chain.cc,v 1.1 2025/10/22 07:21:48 jnemeth Exp $

--- plugin/x/protocol/plugin/message_field_chain.cc.orig	2024-07-13 15:30:43.000000000 +0000
+++ plugin/x/protocol/plugin/message_field_chain.cc
@@ -26,6 +26,7 @@
 #include "plugin/x/protocol/plugin/message_field_chain.h"
 
 #include <string>
+#include <string_view>
 
 #include "my_compiler.h"
 MY_COMPILER_DIAGNOSTIC_PUSH()
@@ -58,7 +59,7 @@ bool Message_field_chain::begin_validate
 
   // Check against cycles in Message dependencies graph
   const bool was_node_visited =
-      message && 0 != m_types_done.count(message->full_name());
+      message && 0 != m_types_done.count(std::string(message->full_name()));
 
   if (nullptr == message || was_node_visited || 0 == message->field_count()) {
     m_output_file->append_chain(m_context, chain);
@@ -74,7 +75,7 @@ bool Message_field_chain::begin_validate
 
 void Message_field_chain::end_validate_field(const FieldDescriptor *field,
                                              const Descriptor *message) {
-  m_types_done.erase(message->full_name());
+  m_types_done.erase(std::string(message->full_name()));
   const auto position = m_chain.find_last_of(".");
 
   if (std::string::npos != position) m_chain.resize(position);
