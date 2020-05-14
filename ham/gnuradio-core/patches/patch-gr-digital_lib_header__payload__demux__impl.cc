$NetBSD: patch-gr-digital_lib_header__payload__demux__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-digital/lib/header_payload_demux_impl.cc.orig	2020-05-10 02:22:34.316920013 +0000
+++ gr-digital/lib/header_payload_demux_impl.cc
@@ -154,7 +154,7 @@ namespace gr {
       }
       set_tag_propagation_policy(TPP_DONT);
       message_port_register_in(msg_port_id());
-      set_msg_handler(msg_port_id(), boost::bind(&header_payload_demux_impl::parse_header_data_msg, this, _1));
+      set_msg_handler(msg_port_id(), boost::bind(&header_payload_demux_impl::parse_header_data_msg, this, boost::placeholders::_1));
       for (size_t i = 0; i < special_tags.size(); i++) {
         d_special_tags.push_back(pmt::string_to_symbol(special_tags[i]));
         d_special_tags_last_value.push_back(pmt::PMT_NIL);
