$NetBSD: patch-plugin_x_protocol_plugin_encoder__file__output.h,v 1.1 2025/10/15 03:52:37 jnemeth Exp $

--- plugin/x/protocol/plugin/encoder_file_output.h.orig	2025-09-26 12:35:32.501446532 +0000
+++ plugin/x/protocol/plugin/encoder_file_output.h
@@ -79,7 +79,7 @@ class Encoder_file_output : public File_
       return;
 
     write_to_context(context, "");
-    write_to_context(context, "struct ", message->name(), " {");
+    write_to_context(context, "struct ", std::string(message->name()), " {");
 
     if (message->options().HasExtension(Mysqlx::server_message_id)) {
       const auto server_id_numeric = static_cast<int>(
@@ -97,7 +97,7 @@ class Encoder_file_output : public File_
       bool is_reserved = false;
       const auto field = message->field(i);
       const auto field_tag = std::to_string(field->number());
-      const auto field_name = get_cpp_field_name(field->name(), &is_reserved);
+      const auto field_name = get_cpp_field_name(std::string(field->name()), &is_reserved);
 
       if (is_reserved) {
         write_to_context(context,
@@ -129,7 +129,7 @@ class Encoder_file_output : public File_
 
       // Check if we there is a message containing Server message ID
       if (0 == m_used_message_ids.count(enum_value->number())) {
-        std::string value = "  " + enum_value->name() + " = " +
+        std::string value = std::string("  ") + std::string(enum_value->name()) + " = " +
                             std::to_string(enum_value->number());
 
         values.push_back(value);
