$NetBSD: patch-lib_usrp_dboard_db__wbx__version4.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_wbx_version4.cpp.orig	2020-05-09 15:49:39.733159439 +0000
+++ lib/usrp/dboard/db_wbx_version4.cpp
@@ -71,8 +71,8 @@ static int tx_pga0_gain_to_iobits(double
 wbx_base::wbx_version4::wbx_version4(wbx_base *_self_wbx_base) {
     //register our handle on the primary wbx_base instance
     self_base = _self_wbx_base;
-    _txlo = adf435x_iface::make_adf4351(boost::bind(&wbx_base::wbx_versionx::write_lo_regs, this, dboard_iface::UNIT_TX, _1));
-    _rxlo = adf435x_iface::make_adf4351(boost::bind(&wbx_base::wbx_versionx::write_lo_regs, this, dboard_iface::UNIT_RX, _1));
+    _txlo = adf435x_iface::make_adf4351(boost::bind(&wbx_base::wbx_versionx::write_lo_regs, this, dboard_iface::UNIT_TX, boost::placeholders::_1));
+    _rxlo = adf435x_iface::make_adf4351(boost::bind(&wbx_base::wbx_versionx::write_lo_regs, this, dboard_iface::UNIT_RX, boost::placeholders::_1));
 
     ////////////////////////////////////////////////////////////////////
     // Register RX properties
@@ -82,7 +82,7 @@ wbx_base::wbx_version4::wbx_version4(wbx
     if(rx_id == 0x0063) this->get_rx_subtree()->create<std::string>("name").set("WBXv4 RX");
     else if(rx_id == 0x0081) this->get_rx_subtree()->create<std::string>("name").set("WBX-120 RX");
     this->get_rx_subtree()->create<double>("freq/value")
-         .set_coercer(boost::bind(&wbx_base::wbx_version4::set_lo_freq, this, dboard_iface::UNIT_RX, _1))
+         .set_coercer(boost::bind(&wbx_base::wbx_version4::set_lo_freq, this, dboard_iface::UNIT_RX, boost::placeholders::_1))
          .set((wbx_v4_freq_range.start() + wbx_v4_freq_range.stop())/2.0);
     this->get_rx_subtree()->create<meta_range_t>("freq/range").set(wbx_v4_freq_range);
 
@@ -95,17 +95,17 @@ wbx_base::wbx_version4::wbx_version4(wbx
     else if(rx_id == 0x0081) this->get_tx_subtree()->create<std::string>("name").set("WBX-120 TX");
     for(const std::string &name:  wbx_v4_tx_gain_ranges.keys()){
         self_base->get_tx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&wbx_base::wbx_version4::set_tx_gain, this, _1, name))
+            .set_coercer(boost::bind(&wbx_base::wbx_version4::set_tx_gain, this, boost::placeholders::_1, name))
             .set(wbx_v4_tx_gain_ranges[name].start());
         self_base->get_tx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(wbx_v4_tx_gain_ranges[name]);
     }
     this->get_tx_subtree()->create<double>("freq/value")
-         .set_coercer(boost::bind(&wbx_base::wbx_version4::set_lo_freq, this, dboard_iface::UNIT_TX, _1))
+         .set_coercer(boost::bind(&wbx_base::wbx_version4::set_lo_freq, this, dboard_iface::UNIT_TX, boost::placeholders::_1))
          .set((wbx_v4_freq_range.start() + wbx_v4_freq_range.stop())/2.0);
     this->get_tx_subtree()->create<meta_range_t>("freq/range").set(wbx_v4_freq_range);
     this->get_tx_subtree()->create<bool>("enabled")
-        .add_coerced_subscriber(boost::bind(&wbx_base::wbx_version4::set_tx_enabled, this, _1))
+        .add_coerced_subscriber(boost::bind(&wbx_base::wbx_version4::set_tx_enabled, this, boost::placeholders::_1))
         .set(true); //start enabled
 
     //set attenuator control bits
