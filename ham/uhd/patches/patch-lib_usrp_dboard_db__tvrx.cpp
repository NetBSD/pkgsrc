$NetBSD: patch-lib_usrp_dboard_db__tvrx.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_tvrx.cpp.orig	2020-05-09 15:47:27.655845074 +0000
+++ lib/usrp/dboard/db_tvrx.cpp
@@ -180,12 +180,12 @@ tvrx::tvrx(ctor_args_t args) : rx_dboard
     this->get_rx_subtree()->create<int>("sensors"); //phony property so this dir exists
     for(const std::string &name:  get_tvrx_gain_ranges().keys()){
         this->get_rx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&tvrx::set_gain, this, _1, name));
+            .set_coercer(boost::bind(&tvrx::set_gain, this, boost::placeholders::_1, name));
         this->get_rx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(get_tvrx_gain_ranges()[name]);
     }
     this->get_rx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&tvrx::set_freq, this, _1));
+        .set_coercer(boost::bind(&tvrx::set_freq, this, boost::placeholders::_1));
     this->get_rx_subtree()->create<meta_range_t>("freq/range")
         .set(tvrx_freq_range);
     this->get_rx_subtree()->create<std::string>("antenna/value")
