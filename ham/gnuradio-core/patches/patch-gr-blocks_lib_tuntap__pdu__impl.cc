$NetBSD: patch-gr-blocks_lib_tuntap__pdu__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/tuntap_pdu_impl.cc.orig	2020-05-09 00:14:38.266368341 +0000
+++ gr-blocks/lib/tuntap_pdu_impl.cc
@@ -97,7 +97,7 @@ namespace gr {
 
       // set up input message port
       message_port_register_in(pdu::pdu_port_id());
-      set_msg_handler(pdu::pdu_port_id(), boost::bind(&tuntap_pdu_impl::send, this, _1));
+      set_msg_handler(pdu::pdu_port_id(), boost::bind(&tuntap_pdu_impl::send, this, boost::placeholders::_1));
     }
 
     int
