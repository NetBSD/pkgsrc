$NetBSD: patch-lib_usrp_dboard_db__sbx__common.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_sbx_common.cpp.orig	2020-05-09 15:36:12.520397133 +0000
+++ lib/usrp/dboard/db_sbx_common.cpp
@@ -149,17 +149,17 @@ sbx_xcvr::sbx_xcvr(ctor_args_t args) : x
         .set_publisher(boost::bind(&sbx_xcvr::get_locked, this, dboard_iface::UNIT_RX));
     for(const std::string &name:  sbx_rx_gain_ranges.keys()){
         this->get_rx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&sbx_xcvr::set_rx_gain, this, _1, name))
+            .set_coercer(boost::bind(&sbx_xcvr::set_rx_gain, this, boost::placeholders::_1, name))
             .set(sbx_rx_gain_ranges[name].start());
         this->get_rx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(sbx_rx_gain_ranges[name]);
     }
     this->get_rx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&sbx_xcvr::set_lo_freq, this, dboard_iface::UNIT_RX, _1))
+        .set_coercer(boost::bind(&sbx_xcvr::set_lo_freq, this, dboard_iface::UNIT_RX, boost::placeholders::_1))
         .set((freq_range.start() + freq_range.stop())/2.0);
     this->get_rx_subtree()->create<meta_range_t>("freq/range").set(freq_range);
     this->get_rx_subtree()->create<std::string>("antenna/value")
-        .add_coerced_subscriber(boost::bind(&sbx_xcvr::set_rx_ant, this, _1))
+        .add_coerced_subscriber(boost::bind(&sbx_xcvr::set_rx_ant, this, boost::placeholders::_1))
         .set("RX2");
     this->get_rx_subtree()->create<std::vector<std::string> >("antenna/options")
         .set(sbx_rx_antennas);
@@ -190,17 +190,17 @@ sbx_xcvr::sbx_xcvr(ctor_args_t args) : x
         .set_publisher(boost::bind(&sbx_xcvr::get_locked, this, dboard_iface::UNIT_TX));
     for(const std::string &name:  sbx_tx_gain_ranges.keys()){
         this->get_tx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&sbx_xcvr::set_tx_gain, this, _1, name))
+            .set_coercer(boost::bind(&sbx_xcvr::set_tx_gain, this, boost::placeholders::_1, name))
             .set(sbx_tx_gain_ranges[name].start());
         this->get_tx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(sbx_tx_gain_ranges[name]);
     }
     this->get_tx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&sbx_xcvr::set_lo_freq, this, dboard_iface::UNIT_TX, _1))
+        .set_coercer(boost::bind(&sbx_xcvr::set_lo_freq, this, dboard_iface::UNIT_TX, boost::placeholders::_1))
         .set((freq_range.start() + freq_range.stop())/2.0);
     this->get_tx_subtree()->create<meta_range_t>("freq/range").set(freq_range);
     this->get_tx_subtree()->create<std::string>("antenna/value")
-        .add_coerced_subscriber(boost::bind(&sbx_xcvr::set_tx_ant, this, _1))
+        .add_coerced_subscriber(boost::bind(&sbx_xcvr::set_tx_ant, this, boost::placeholders::_1))
         .set(sbx_tx_antennas.at(0));
     this->get_tx_subtree()->create<std::vector<std::string> >("antenna/options")
         .set(sbx_tx_antennas);
