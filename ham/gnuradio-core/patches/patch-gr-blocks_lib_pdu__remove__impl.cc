$NetBSD: patch-gr-blocks_lib_pdu__remove__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/pdu_remove_impl.cc.orig	2020-05-09 00:14:25.622411218 +0000
+++ gr-blocks/lib/pdu_remove_impl.cc
@@ -45,7 +45,7 @@ namespace gr {
     {
       message_port_register_out(pdu::pdu_port_id());
       message_port_register_in(pdu::pdu_port_id());
-      set_msg_handler(pdu::pdu_port_id(), boost::bind(&pdu_remove_impl::handle_msg, this, _1));
+      set_msg_handler(pdu::pdu_port_id(), boost::bind(&pdu_remove_impl::handle_msg, this, boost::placeholders::_1));
     }
 
     void
