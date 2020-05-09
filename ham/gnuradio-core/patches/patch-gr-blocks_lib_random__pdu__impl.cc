$NetBSD: patch-gr-blocks_lib_random__pdu__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/random_pdu_impl.cc.orig	2020-05-09 00:14:29.761401160 +0000
+++ gr-blocks/lib/random_pdu_impl.cc
@@ -50,7 +50,7 @@ namespace gr {
     {
       message_port_register_out(pdu::pdu_port_id());
       message_port_register_in(pmt::mp("generate"));
-      set_msg_handler(pmt::mp("generate"), boost::bind(&random_pdu_impl::generate_pdu, this, _1));
+      set_msg_handler(pmt::mp("generate"), boost::bind(&random_pdu_impl::generate_pdu, this, boost::placeholders::_1));
       if(length_modulo < 1)
         throw std::runtime_error("length_module must be >= 1");
       if(max_items < length_modulo)
