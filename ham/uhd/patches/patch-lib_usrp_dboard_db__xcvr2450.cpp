$NetBSD: patch-lib_usrp_dboard_db__xcvr2450.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_xcvr2450.cpp.orig	2020-05-09 15:31:27.549815118 +0000
+++ lib/usrp/dboard/db_xcvr2450.cpp
@@ -227,18 +227,18 @@ xcvr2450::xcvr2450(ctor_args_t args) : x
         .set_publisher(boost::bind(&xcvr2450::get_rssi, this));
     for(const std::string &name:  xcvr_rx_gain_ranges.keys()){
         this->get_rx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&xcvr2450::set_rx_gain, this, _1, name))
+            .set_coercer(boost::bind(&xcvr2450::set_rx_gain, this, boost::placeholders::_1, name))
             .set(xcvr_rx_gain_ranges[name].start());
         this->get_rx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(xcvr_rx_gain_ranges[name]);
     }
     this->get_rx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&xcvr2450::set_lo_freq, this, _1))
+        .set_coercer(boost::bind(&xcvr2450::set_lo_freq, this, boost::placeholders::_1))
         .set(double(2.45e9));
     this->get_rx_subtree()->create<meta_range_t>("freq/range")
         .set(xcvr_freq_range);
     this->get_rx_subtree()->create<std::string>("antenna/value")
-        .add_coerced_subscriber(boost::bind(&xcvr2450::set_rx_ant, this, _1))
+        .add_coerced_subscriber(boost::bind(&xcvr2450::set_rx_ant, this, boost::placeholders::_1))
         .set(xcvr_antennas.at(0));
     this->get_rx_subtree()->create<std::vector<std::string> >("antenna/options")
         .set(xcvr_antennas);
@@ -249,7 +249,7 @@ xcvr2450::xcvr2450(ctor_args_t args) : x
     this->get_rx_subtree()->create<bool>("use_lo_offset")
         .set(false);
     this->get_rx_subtree()->create<double>("bandwidth/value")
-        .set_coercer(boost::bind(&xcvr2450::set_rx_bandwidth, this, _1)) //complex bandpass bandwidth 
+        .set_coercer(boost::bind(&xcvr2450::set_rx_bandwidth, this, boost::placeholders::_1)) //complex bandpass bandwidth 
         .set(2.0*_rx_bandwidth); //_rx_bandwidth in lowpass, convert to complex bandpass
     this->get_rx_subtree()->create<meta_range_t>("bandwidth/range")
         .set(xcvr_rx_bandwidth_range);
@@ -263,18 +263,18 @@ xcvr2450::xcvr2450(ctor_args_t args) : x
         .set_publisher(boost::bind(&xcvr2450::get_locked, this));
     for(const std::string &name:  xcvr_tx_gain_ranges.keys()){
         this->get_tx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&xcvr2450::set_tx_gain, this, _1, name))
+            .set_coercer(boost::bind(&xcvr2450::set_tx_gain, this, boost::placeholders::_1, name))
             .set(xcvr_tx_gain_ranges[name].start());
         this->get_tx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(xcvr_tx_gain_ranges[name]);
     }
     this->get_tx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&xcvr2450::set_lo_freq, this, _1))
+        .set_coercer(boost::bind(&xcvr2450::set_lo_freq, this, boost::placeholders::_1))
         .set(double(2.45e9));
     this->get_tx_subtree()->create<meta_range_t>("freq/range")
         .set(xcvr_freq_range);
     this->get_tx_subtree()->create<std::string>("antenna/value")
-        .add_coerced_subscriber(boost::bind(&xcvr2450::set_tx_ant, this, _1))
+        .add_coerced_subscriber(boost::bind(&xcvr2450::set_tx_ant, this, boost::placeholders::_1))
         .set(xcvr_antennas.at(1));
     this->get_tx_subtree()->create<std::vector<std::string> >("antenna/options")
         .set(xcvr_antennas);
@@ -285,7 +285,7 @@ xcvr2450::xcvr2450(ctor_args_t args) : x
     this->get_tx_subtree()->create<bool>("use_lo_offset")
         .set(false);
     this->get_tx_subtree()->create<double>("bandwidth/value")
-        .set_coercer(boost::bind(&xcvr2450::set_tx_bandwidth, this, _1)) //complex bandpass bandwidth
+        .set_coercer(boost::bind(&xcvr2450::set_tx_bandwidth, this, boost::placeholders::_1)) //complex bandpass bandwidth
         .set(2.0*_tx_bandwidth); //_tx_bandwidth in lowpass, convert to complex bandpass
     this->get_tx_subtree()->create<meta_range_t>("bandwidth/range")
         .set(xcvr_tx_bandwidth_range);
