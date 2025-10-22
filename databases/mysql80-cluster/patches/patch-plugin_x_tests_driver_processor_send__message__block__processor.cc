$NetBSD: patch-plugin_x_tests_driver_processor_send__message__block__processor.cc,v 1.1 2025/10/22 07:21:48 jnemeth Exp $

--- plugin/x/tests/driver/processor/send_message_block_processor.cc.orig	2025-10-20 04:09:59.450725036 +0000
+++ plugin/x/tests/driver/processor/send_message_block_processor.cc
@@ -160,7 +160,7 @@ std::string Send_message_block_processor
 #endif
 
   res[4] = client_msgs_by_name
-               [client_msgs_by_full_name[message.GetDescriptor()->full_name()]]
+               [client_msgs_by_full_name[std::string(message.GetDescriptor()->full_name())]]
                    .second;
   res.append(out);
 
