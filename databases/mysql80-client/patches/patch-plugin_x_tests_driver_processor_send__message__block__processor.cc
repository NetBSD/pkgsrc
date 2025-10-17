$NetBSD: patch-plugin_x_tests_driver_processor_send__message__block__processor.cc,v 1.1.2.2 2025/10/17 23:34:27 maya Exp $

--- plugin/x/tests/driver/processor/send_message_block_processor.cc.orig	2025-09-26 15:25:21.172316733 +0000
+++ plugin/x/tests/driver/processor/send_message_block_processor.cc
@@ -160,7 +160,7 @@ std::string Send_message_block_processor
 #endif
 
   res[4] = client_msgs_by_name
-               [client_msgs_by_full_name[message.GetDescriptor()->full_name()]]
+               [client_msgs_by_full_name[std::string(message.GetDescriptor()->full_name())]]
                    .second;
   res.append(out);
 
