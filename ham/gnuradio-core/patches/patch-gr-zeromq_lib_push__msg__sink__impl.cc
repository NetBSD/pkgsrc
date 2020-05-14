$NetBSD: patch-gr-zeromq_lib_push__msg__sink__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-zeromq/lib/push_msg_sink_impl.cc.orig	2020-05-10 01:25:20.808024050 +0000
+++ gr-zeromq/lib/push_msg_sink_impl.cc
@@ -60,7 +60,7 @@ namespace gr {
 
       message_port_register_in(pmt::mp("in"));
       set_msg_handler(pmt::mp("in"),
-                      boost::bind(&push_msg_sink_impl::handler, this, _1));
+                      boost::bind(&push_msg_sink_impl::handler, this, boost::placeholders::_1));
     }
 
     push_msg_sink_impl::~push_msg_sink_impl()
