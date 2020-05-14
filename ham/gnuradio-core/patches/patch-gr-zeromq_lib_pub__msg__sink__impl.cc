$NetBSD: patch-gr-zeromq_lib_pub__msg__sink__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-zeromq/lib/pub_msg_sink_impl.cc.orig	2020-05-10 01:26:09.507359022 +0000
+++ gr-zeromq/lib/pub_msg_sink_impl.cc
@@ -58,7 +58,7 @@ namespace gr {
 
       message_port_register_in(pmt::mp("in"));
       set_msg_handler( pmt::mp("in"),
-        boost::bind(&pub_msg_sink_impl::handler, this, _1));
+        boost::bind(&pub_msg_sink_impl::handler, this, boost::placeholders::_1));
     }
 
     pub_msg_sink_impl::~pub_msg_sink_impl()
