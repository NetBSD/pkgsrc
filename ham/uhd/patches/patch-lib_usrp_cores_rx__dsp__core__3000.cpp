$NetBSD: patch-lib_usrp_cores_rx__dsp__core__3000.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/cores/rx_dsp_core_3000.cpp.orig	2020-05-09 15:26:15.563064777 +0000
+++ lib/usrp/cores/rx_dsp_core_3000.cpp
@@ -300,10 +300,10 @@ public:
             .set_publisher(boost::bind(&rx_dsp_core_3000::get_host_rates, this));
         subtree->create<double>("rate/value")
             .set(DEFAULT_RATE)
-            .set_coercer(boost::bind(&rx_dsp_core_3000::set_host_rate, this, _1));
+            .set_coercer(boost::bind(&rx_dsp_core_3000::set_host_rate, this, boost::placeholders::_1));
         subtree->create<double>("freq/value")
             .set(DEFAULT_CORDIC_FREQ)
-            .set_coercer(boost::bind(&rx_dsp_core_3000::set_freq, this, _1))
+            .set_coercer(boost::bind(&rx_dsp_core_3000::set_freq, this, boost::placeholders::_1))
             .set_publisher([this]() { return this->get_freq(); });
         subtree->create<meta_range_t>("freq/range")
             .set_publisher(boost::bind(&rx_dsp_core_3000::get_freq_range, this));
