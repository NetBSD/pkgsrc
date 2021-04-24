$NetBSD: patch-lib_usrp_cores_rx__dsp__core__3000.cpp,v 1.2 2021/04/24 16:34:54 tnn Exp $

libuhd.so.3.15.0: undefined reference to `int boost::math::sign<double>(double const&)'

--- lib/usrp/cores/rx_dsp_core_3000.cpp.orig	2020-01-01 04:21:49.000000000 +0000
+++ lib/usrp/cores/rx_dsp_core_3000.cpp
@@ -14,6 +14,7 @@
 #include <uhdlib/usrp/cores/rx_dsp_core_3000.hpp>
 #include <boost/assign/list_of.hpp>
 #include <boost/math/special_functions/round.hpp>
+#include <boost/math/special_functions/sign.hpp>
 #include <boost/thread/thread.hpp> //thread sleep
 #include <algorithm>
 #include <cmath>
@@ -300,10 +301,10 @@ public:
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
