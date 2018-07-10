$NetBSD: patch-gr-blocks_lib_message__strobe__impl.cc,v 1.1 2018/07/10 07:05:06 dbj Exp $

Fix compiling with Boost 1.67
patch from upstream https://github.com/gnuradio/gnuradio.git
commit 86fa85feef81e69dd1354b393118459340b94489

--- gr-blocks/lib/message_strobe_impl.cc.orig	2017-02-27 23:19:00.000000000 +0000
+++ gr-blocks/lib/message_strobe_impl.cc
@@ -90,7 +90,7 @@ namespace gr {
     void message_strobe_impl::run()
     {
       while(!d_finished) {
-        boost::this_thread::sleep(boost::posix_time::milliseconds(d_period_ms));
+        boost::this_thread::sleep(boost::posix_time::milliseconds(static_cast<long>(d_period_ms)));
         if(d_finished) {
           return;
         }
