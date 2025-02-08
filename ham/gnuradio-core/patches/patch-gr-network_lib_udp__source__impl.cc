$NetBSD: patch-gr-network_lib_udp__source__impl.cc,v 1.1 2025/02/08 13:35:40 wiz Exp $

Fix build with boost 1.87.
https://github.com/gnuradio/gnuradio/pull/7554

--- gr-network/lib/udp_source_impl.cc.orig	2024-01-17 20:36:19.000000000 +0000
+++ gr-network/lib/udp_source_impl.cc
@@ -163,7 +163,6 @@ bool udp_source_impl::stop()
         delete d_udpsocket;
         d_udpsocket = nullptr;
 
-        d_io_context.reset();
         d_io_context.stop();
     }
 
@@ -275,7 +274,7 @@ int udp_source_impl::work(int noutput_it
             // Get the data and add it to our local queue.  We have to maintain a
             // local queue in case we read more bytes than noutput_items is asking
             // for.  In that case we'll only return noutput_items bytes
-            const char* read_data = asio::buffer_cast<const char*>(d_read_buffer.data());
+            const char* read_data = static_cast<const char*>(d_read_buffer.data().data());
 
             // Discard bytes if the input is longer than the buffer
             if (bytes_read > d_localqueue_writer->bufsize()) {
