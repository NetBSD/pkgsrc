$NetBSD: patch-lib_usrp_dboard_db__rfx.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_rfx.cpp.orig	2020-05-09 15:49:14.740543409 +0000
+++ lib/usrp/dboard/db_rfx.cpp
@@ -176,17 +176,17 @@ rfx_xcvr::rfx_xcvr(
         .set_publisher(boost::bind(&rfx_xcvr::get_locked, this, dboard_iface::UNIT_RX));
     for(const std::string &name:  _rx_gain_ranges.keys()){
         this->get_rx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&rfx_xcvr::set_rx_gain, this, _1, name))
+            .set_coercer(boost::bind(&rfx_xcvr::set_rx_gain, this, boost::placeholders::_1, name))
             .set(_rx_gain_ranges[name].start());
         this->get_rx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(_rx_gain_ranges[name]);
     }
     this->get_rx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&rfx_xcvr::set_lo_freq, this, dboard_iface::UNIT_RX, _1))
+        .set_coercer(boost::bind(&rfx_xcvr::set_lo_freq, this, dboard_iface::UNIT_RX, boost::placeholders::_1))
         .set((_freq_range.start() + _freq_range.stop())/2.0);
     this->get_rx_subtree()->create<meta_range_t>("freq/range").set(_freq_range);
     this->get_rx_subtree()->create<std::string>("antenna/value")
-        .add_coerced_subscriber(boost::bind(&rfx_xcvr::set_rx_ant, this, _1))
+        .add_coerced_subscriber(boost::bind(&rfx_xcvr::set_rx_ant, this, boost::placeholders::_1))
         .set("RX2");
     this->get_rx_subtree()->create<std::vector<std::string> >("antenna/options")
         .set(rfx_rx_antennas);
@@ -212,11 +212,11 @@ rfx_xcvr::rfx_xcvr(
         .set_publisher(boost::bind(&rfx_xcvr::get_locked, this, dboard_iface::UNIT_TX));
     this->get_tx_subtree()->create<int>("gains"); //phony property so this dir exists
     this->get_tx_subtree()->create<double>("freq/value")
-        .set_coercer(boost::bind(&rfx_xcvr::set_lo_freq, this, dboard_iface::UNIT_TX, _1))
+        .set_coercer(boost::bind(&rfx_xcvr::set_lo_freq, this, dboard_iface::UNIT_TX, boost::placeholders::_1))
         .set((_freq_range.start() + _freq_range.stop())/2.0);
     this->get_tx_subtree()->create<meta_range_t>("freq/range").set(_freq_range);
     this->get_tx_subtree()->create<std::string>("antenna/value")
-        .add_coerced_subscriber(boost::bind(&rfx_xcvr::set_tx_ant, this, _1)).set(rfx_tx_antennas.at(0));
+        .add_coerced_subscriber(boost::bind(&rfx_xcvr::set_tx_ant, this, boost::placeholders::_1)).set(rfx_tx_antennas.at(0));
     this->get_tx_subtree()->create<std::vector<std::string> >("antenna/options")
         .set(rfx_tx_antennas);
     this->get_tx_subtree()->create<std::string>("connection").set("IQ");
