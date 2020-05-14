$NetBSD: patch-gr-fec_lib_depuncture__bb__impl.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-fec/lib/depuncture_bb_impl.cc.orig	2020-05-10 02:07:20.402816615 +0000
+++ gr-fec/lib/depuncture_bb_impl.cc
@@ -76,7 +76,7 @@ namespace gr {
       set_fixed_rate(true);
       set_relative_rate((double)d_puncsize/(d_puncsize - d_puncholes));
       set_output_multiple(d_puncsize);
-      //set_msg_handler(boost::bind(&depuncture_bb_impl::catch_msg, this, _1));
+      //set_msg_handler(boost::bind(&depuncture_bb_impl::catch_msg, this, boost::placeholders::_1));
     }
 
     depuncture_bb_impl::~depuncture_bb_impl()
