$NetBSD: patch-lib_usrp_dboard_db__wbx__common.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_wbx_common.cpp.orig	2020-05-09 15:50:03.270707228 +0000
+++ lib/usrp/dboard/db_wbx_common.cpp
@@ -62,14 +62,14 @@ wbx_base::wbx_base(ctor_args_t args) : x
         .set_publisher(boost::bind(&wbx_base::get_locked, this, dboard_iface::UNIT_RX));
     for(const std::string &name:  wbx_rx_gain_ranges.keys()){
         this->get_rx_subtree()->create<double>("gains/"+name+"/value")
-            .set_coercer(boost::bind(&wbx_base::set_rx_gain, this, _1, name))
+            .set_coercer(boost::bind(&wbx_base::set_rx_gain, this, boost::placeholders::_1, name))
             .set(wbx_rx_gain_ranges[name].start());
         this->get_rx_subtree()->create<meta_range_t>("gains/"+name+"/range")
             .set(wbx_rx_gain_ranges[name]);
     }
     this->get_rx_subtree()->create<std::string>("connection").set("IQ");
     this->get_rx_subtree()->create<bool>("enabled")
-        .add_coerced_subscriber(boost::bind(&wbx_base::set_rx_enabled, this, _1))
+        .add_coerced_subscriber(boost::bind(&wbx_base::set_rx_enabled, this, boost::placeholders::_1))
         .set(true); //start enabled
     this->get_rx_subtree()->create<bool>("use_lo_offset").set(false);
 
