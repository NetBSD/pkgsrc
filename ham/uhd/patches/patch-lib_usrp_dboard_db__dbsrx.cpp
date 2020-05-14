$NetBSD: patch-lib_usrp_dboard_db__dbsrx.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_dbsrx.cpp.orig	2020-05-09 15:44:27.579328645 +0000
+++ lib/usrp/dboard/db_dbsrx.cpp
@@ -198,13 +198,13 @@ dbsrx::dbsrx(ctor_args_t args) : rx_dboa
         .set_publisher(boost::bind(&dbsrx::get_locked, this));
     for(const std::string &name:  dbsrx_gain_ranges.keys()){
         this->get_rx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&dbsrx::set_gain, this, _1, name))
+            .set_coercer(boost::bind(&dbsrx::set_gain, this, boost::placeholders::_1, name))
             .set(dbsrx_gain_ranges[name].start());
         this->get_rx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(dbsrx_gain_ranges[name]);
     }
     this->get_rx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&dbsrx::set_lo_freq, this, _1));
+        .set_coercer(boost::bind(&dbsrx::set_lo_freq, this, boost::placeholders::_1));
     this->get_rx_subtree()->create<meta_range_t>("freq/range")
         .set(dbsrx_freq_range);
     this->get_rx_subtree()->create<std::string>("antenna/value")
@@ -218,7 +218,7 @@ dbsrx::dbsrx(ctor_args_t args) : rx_dboa
     this->get_rx_subtree()->create<bool>("use_lo_offset")
         .set(false);
     this->get_rx_subtree()->create<double>("bandwidth/value")
-        .set_coercer(boost::bind(&dbsrx::set_bandwidth, this, _1));
+        .set_coercer(boost::bind(&dbsrx::set_bandwidth, this, boost::placeholders::_1));
     this->get_rx_subtree()->create<meta_range_t>("bandwidth/range")
         .set(dbsrx_bandwidth_range);
 
