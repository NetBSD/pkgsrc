$NetBSD: patch-lib_usrp_dboard_eiscat_eiscat__radio__ctrl__impl.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/eiscat/eiscat_radio_ctrl_impl.cpp.orig	2020-05-09 15:49:34.413319138 +0000
+++ lib/usrp/dboard/eiscat/eiscat_radio_ctrl_impl.cpp
@@ -301,7 +301,7 @@ UHD_RFNOC_RADIO_BLOCK_CONSTRUCTOR(eiscat
     UHD_ASSERT_THROW(not _tree->exists("tick_rate"));
     _tree->create<double>("tick_rate")
         .set(EISCAT_TICK_RATE)
-        .set_coercer(boost::bind(&eiscat_radio_ctrl_impl::set_rate, this, _1))
+        .set_coercer(boost::bind(&eiscat_radio_ctrl_impl::set_rate, this, boost::placeholders::_1))
     ;
 }
 
