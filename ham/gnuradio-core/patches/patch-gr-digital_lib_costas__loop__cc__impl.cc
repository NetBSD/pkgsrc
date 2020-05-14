$NetBSD: patch-gr-digital_lib_costas__loop__cc__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-digital/lib/costas_loop_cc_impl.cc.orig	2020-05-10 02:22:30.424208998 +0000
+++ gr-digital/lib/costas_loop_cc_impl.cc
@@ -83,7 +83,7 @@ namespace gr {
       set_msg_handler(
         pmt::mp("noise"),
         boost::bind(&costas_loop_cc_impl::handle_set_noise,
-                    this, _1));
+                    this, boost::placeholders::_1));
     }
 
     costas_loop_cc_impl::~costas_loop_cc_impl()
