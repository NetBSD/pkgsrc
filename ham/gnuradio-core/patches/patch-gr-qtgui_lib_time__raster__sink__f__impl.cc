$NetBSD: patch-gr-qtgui_lib_time__raster__sink__f__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/time_raster_sink_f_impl.cc.orig	2020-05-10 01:47:45.039050549 +0000
+++ gr-qtgui/lib/time_raster_sink_f_impl.cc
@@ -82,7 +82,7 @@ namespace gr {
       // setup PDU handling input port
       message_port_register_in(pmt::mp("in"));
       set_msg_handler(pmt::mp("in"),
-                      boost::bind(&time_raster_sink_f_impl::handle_pdus, this, _1));
+                      boost::bind(&time_raster_sink_f_impl::handle_pdus, this, boost::placeholders::_1));
 
       d_icols = static_cast<int>(ceil(d_cols));
       d_tmpflt = (float*)volk_malloc(d_icols*sizeof(float),
