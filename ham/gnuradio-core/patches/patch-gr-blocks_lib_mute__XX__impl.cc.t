$NetBSD: patch-gr-blocks_lib_mute__XX__impl.cc.t,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/mute_XX_impl.cc.t.orig	2020-05-09 00:48:46.934718299 +0000
+++ gr-blocks/lib/mute_XX_impl.cc.t
@@ -48,7 +48,7 @@ namespace gr {
     {
       message_port_register_in(pmt::intern("set_mute"));
       set_msg_handler(pmt::intern("set_mute"),
-        boost::bind(&@NAME_IMPL@::set_mute_pmt, this, _1));
+        boost::bind(&@NAME_IMPL@::set_mute_pmt, this, boost::placeholders::_1));
     }
 
     @NAME_IMPL@::~@NAME_IMPL@()
