$NetBSD: patch-gr-filter_lib_freq__xlating__fir__filter__XXX__impl.cc.t,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-filter/lib/freq_xlating_fir_filter_XXX_impl.cc.t.orig	2020-05-09 00:48:50.738435461 +0000
+++ gr-filter/lib/freq_xlating_fir_filter_XXX_impl.cc.t
@@ -69,7 +69,7 @@ namespace gr {
       message_port_register_in(pmt::mp("freq"));
       set_msg_handler(pmt::mp("freq"),
                       boost::bind(&@IMPL_NAME@::handle_set_center_freq,
-                                  this, _1));
+                                  this, boost::placeholders::_1));
     }
 
     @IMPL_NAME@::~@IMPL_NAME@()
