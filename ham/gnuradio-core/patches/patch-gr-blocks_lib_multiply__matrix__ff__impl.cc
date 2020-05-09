$NetBSD: patch-gr-blocks_lib_multiply__matrix__ff__impl.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/multiply_matrix_ff_impl.cc.orig	2020-05-09 00:14:17.402598574 +0000
+++ gr-blocks/lib/multiply_matrix_ff_impl.cc
@@ -57,7 +57,7 @@ namespace gr {
       message_port_register_in(port_name);
       set_msg_handler(
           port_name,
-          boost::bind(&multiply_matrix_ff_impl::msg_handler_A, this, _1)
+          boost::bind(&multiply_matrix_ff_impl::msg_handler_A, this, boost::placeholders::_1)
       );
     }
 
