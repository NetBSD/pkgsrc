$NetBSD: patch-plugin_x_tests_driver_formatters_message__formatter.cc,v 1.1 2025/10/15 03:52:37 jnemeth Exp $

--- plugin/x/tests/driver/formatters/message_formatter.cc.orig	2025-09-26 15:19:35.788614740 +0000
+++ plugin/x/tests/driver/formatters/message_formatter.cc
@@ -176,7 +176,7 @@ static std::string message_to_text(const
   message.ParseFromString(binary_message);
   google::protobuf::TextFormat::PrintToString(message, &result);
 
-  return message.GetDescriptor()->full_name() + " { " + result + " }";
+  return std::string(message.GetDescriptor()->full_name()) + " { " + result + " }";
 }
 
 static std::string messages_field_to_text(const Message &message,
@@ -206,7 +206,7 @@ static std::string messages_field_to_tex
       return xpl::to_string(reflection->GetBool(message, fd));
 
     case FieldDescriptor::CPPTYPE_ENUM:
-      return reflection->GetEnum(message, fd)->name();
+      return std::string(reflection->GetEnum(message, fd)->name());
 
     case FieldDescriptor::CPPTYPE_STRING:
       return reflection->GetString(message, fd);
@@ -247,7 +247,7 @@ static std::string messages_repeated_fie
       return xpl::to_string(reflection->GetRepeatedBool(message, fd, index));
 
     case FieldDescriptor::CPPTYPE_ENUM:
-      return reflection->GetRepeatedEnum(message, fd, index)->name();
+      return std::string(reflection->GetRepeatedEnum(message, fd, index)->name());
 
     case FieldDescriptor::CPPTYPE_STRING:
       return reflection->GetRepeatedString(message, fd, index);
@@ -313,7 +313,7 @@ std::string message_to_text(const Messag
     printer.PrintToString(message, &output);
   }
 
-  return message.GetDescriptor()->full_name() + " {\n" + output + "}\n";
+  return std::string(message.GetDescriptor()->full_name()) + " {\n" + output + "}\n";
 }
 
 /**
@@ -348,7 +348,7 @@ std::string message_to_text(const Messag
         std::find_if(output.begin(), output.end(), expected_field);
 
     if (output.end() == i) {
-      throw std::logic_error("Message '" + msg->GetDescriptor()->full_name() +
+      throw std::logic_error("Message '" + std::string(msg->GetDescriptor()->full_name()) +
                              "' doesn't contains field '" +
                              expected_field.m_name +
                              "'"
@@ -405,7 +405,7 @@ std::string message_to_text(const Messag
   std::string prefix = "";
 
   if (show_message_name)
-    prefix = message.GetDescriptor()->full_name() + "(" + field_path + ") = ";
+    prefix = std::string(message.GetDescriptor()->full_name()) + "(" + field_path + ") = ";
 
   if (!field_descriptor->is_repeated())
     return prefix + messages_field_to_text(*msg, field_descriptor);
