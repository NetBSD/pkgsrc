$NetBSD: patch-gr-digital_lib_constellation__receiver__cb__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-digital/lib/constellation_receiver_cb_impl.cc.orig	2020-05-10 02:22:19.685626371 +0000
+++ gr-digital/lib/constellation_receiver_cb_impl.cc
@@ -65,12 +65,12 @@ namespace gr {
       set_msg_handler(
         pmt::mp("set_constellation"),
         boost::bind(&constellation_receiver_cb_impl::handle_set_constellation,
-                    this, _1));
+                    this, boost::placeholders::_1));
 
       message_port_register_in(pmt::mp("rotate_phase"));
       set_msg_handler(pmt::mp("rotate_phase"),
                       boost::bind(&constellation_receiver_cb_impl::handle_rotate_phase,
-                                  this, _1));
+                                  this, boost::placeholders::_1));
     }
 
     constellation_receiver_cb_impl::~constellation_receiver_cb_impl()
