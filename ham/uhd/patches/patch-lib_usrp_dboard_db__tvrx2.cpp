$NetBSD: patch-lib_usrp_dboard_db__tvrx2.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_tvrx2.cpp.orig	2020-05-09 15:49:26.498190121 +0000
+++ lib/usrp/dboard/db_tvrx2.cpp
@@ -958,12 +958,12 @@ tvrx2::tvrx2(ctor_args_t args) : rx_dboa
         .set_publisher(boost::bind(&tvrx2::get_temp, this));
     for(const std::string &name:  tvrx2_gain_ranges.keys()){
         this->get_rx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&tvrx2::set_gain, this, _1, name));
+            .set_coercer(boost::bind(&tvrx2::set_gain, this, boost::placeholders::_1, name));
         this->get_rx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(tvrx2_gain_ranges[name]);
     }
     this->get_rx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&tvrx2::set_lo_freq, this, _1));
+        .set_coercer(boost::bind(&tvrx2::set_lo_freq, this, boost::placeholders::_1));
     this->get_rx_subtree()->create<meta_range_t>("freq/range")
         .set(tvrx2_freq_range);
     this->get_rx_subtree()->create<std::string>("antenna/value")
@@ -973,12 +973,12 @@ tvrx2::tvrx2(ctor_args_t args) : rx_dboa
     this->get_rx_subtree()->create<std::string>("connection")
         .set(tvrx2_sd_name_to_conn[get_subdev_name()]);
     this->get_rx_subtree()->create<bool>("enabled")
-        .set_coercer(boost::bind(&tvrx2::set_enabled, this, _1))
+        .set_coercer(boost::bind(&tvrx2::set_enabled, this, boost::placeholders::_1))
         .set(_enabled);
     this->get_rx_subtree()->create<bool>("use_lo_offset")
         .set(false);
     this->get_rx_subtree()->create<double>("bandwidth/value")
-        .set_coercer(boost::bind(&tvrx2::set_bandwidth, this, _1))
+        .set_coercer(boost::bind(&tvrx2::set_bandwidth, this, boost::placeholders::_1))
         .set(_bandwidth);
     this->get_rx_subtree()->create<meta_range_t>("bandwidth/range")
         .set(tvrx2_bandwidth_range);
