$NetBSD: patch-lib_usrp_dboard_db__dbsrx2.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_dbsrx2.cpp.orig	2020-05-09 15:49:00.790946323 +0000
+++ lib/usrp/dboard/db_dbsrx2.cpp
@@ -179,13 +179,13 @@ dbsrx2::dbsrx2(ctor_args_t args) : rx_db
         .set_publisher(boost::bind(&dbsrx2::get_locked, this));
     for(const std::string &name:  dbsrx2_gain_ranges.keys()){
         this->get_rx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&dbsrx2::set_gain, this, _1, name))
+            .set_coercer(boost::bind(&dbsrx2::set_gain, this, boost::placeholders::_1, name))
             .set(dbsrx2_gain_ranges[name].start());
         this->get_rx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(dbsrx2_gain_ranges[name]);
     }
     this->get_rx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&dbsrx2::set_lo_freq, this, _1))
+        .set_coercer(boost::bind(&dbsrx2::set_lo_freq, this, boost::placeholders::_1))
         .set(dbsrx2_freq_range.start());
     this->get_rx_subtree()->create<meta_range_t>("freq/range")
         .set(dbsrx2_freq_range);
@@ -203,7 +203,7 @@ dbsrx2::dbsrx2(ctor_args_t args) : rx_db
     double codec_rate = this->get_iface()->get_codec_rate(dboard_iface::UNIT_RX);
 
     this->get_rx_subtree()->create<double>("bandwidth/value")
-        .set_coercer(boost::bind(&dbsrx2::set_bandwidth, this, _1))
+        .set_coercer(boost::bind(&dbsrx2::set_bandwidth, this, boost::placeholders::_1))
         .set(2.0*(0.8*codec_rate/2.0)); //bandwidth in lowpass, convert to complex bandpass
                                         //default to anti-alias at different codec_rate
     this->get_rx_subtree()->create<meta_range_t>("bandwidth/range")
