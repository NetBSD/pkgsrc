$NetBSD: patch-lib_usrp_dboard_db__ubx.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_ubx.cpp.orig	2020-05-09 15:40:25.281970601 +0000
+++ lib/usrp/dboard/db_ubx.cpp
@@ -395,10 +395,10 @@ public:
         // Initialize LOs
         if (_rev == 0)
         {
-            _txlo1 = max287x_iface::make<max2870>(boost::bind(&ubx_xcvr::write_spi_regs, this, TXLO1, _1));
-            _txlo2 = max287x_iface::make<max2870>(boost::bind(&ubx_xcvr::write_spi_regs, this, TXLO2, _1));
-            _rxlo1 = max287x_iface::make<max2870>(boost::bind(&ubx_xcvr::write_spi_regs, this, RXLO1, _1));
-            _rxlo2 = max287x_iface::make<max2870>(boost::bind(&ubx_xcvr::write_spi_regs, this, RXLO2, _1));
+            _txlo1 = max287x_iface::make<max2870>(boost::bind(&ubx_xcvr::write_spi_regs, this, TXLO1, boost::placeholders::_1));
+            _txlo2 = max287x_iface::make<max2870>(boost::bind(&ubx_xcvr::write_spi_regs, this, TXLO2, boost::placeholders::_1));
+            _rxlo1 = max287x_iface::make<max2870>(boost::bind(&ubx_xcvr::write_spi_regs, this, RXLO1, boost::placeholders::_1));
+            _rxlo2 = max287x_iface::make<max2870>(boost::bind(&ubx_xcvr::write_spi_regs, this, RXLO2, boost::placeholders::_1));
             std::vector<max287x_iface::sptr> los{_txlo1, _txlo2, _rxlo1, _rxlo2};
             for(max287x_iface::sptr lo:  los)
             {
@@ -409,10 +409,10 @@ public:
         }
         else if (_rev == 1 or _rev == 2)
         {
-            _txlo1 = max287x_iface::make<max2871>(boost::bind(&ubx_xcvr::write_spi_regs, this, TXLO1, _1));
-            _txlo2 = max287x_iface::make<max2871>(boost::bind(&ubx_xcvr::write_spi_regs, this, TXLO2, _1));
-            _rxlo1 = max287x_iface::make<max2871>(boost::bind(&ubx_xcvr::write_spi_regs, this, RXLO1, _1));
-            _rxlo2 = max287x_iface::make<max2871>(boost::bind(&ubx_xcvr::write_spi_regs, this, RXLO2, _1));
+            _txlo1 = max287x_iface::make<max2871>(boost::bind(&ubx_xcvr::write_spi_regs, this, TXLO1, boost::placeholders::_1));
+            _txlo2 = max287x_iface::make<max2871>(boost::bind(&ubx_xcvr::write_spi_regs, this, TXLO2, boost::placeholders::_1));
+            _rxlo1 = max287x_iface::make<max2871>(boost::bind(&ubx_xcvr::write_spi_regs, this, RXLO1, boost::placeholders::_1));
+            _rxlo2 = max287x_iface::make<max2871>(boost::bind(&ubx_xcvr::write_spi_regs, this, RXLO2, boost::placeholders::_1));
             std::vector<max287x_iface::sptr> los{_txlo1, _txlo2, _rxlo1, _rxlo2};
             for(max287x_iface::sptr lo:  los)
             {
@@ -439,12 +439,12 @@ public:
         get_rx_subtree()->create<std::vector<std::string> >("power_mode/options")
             .set(ubx_power_modes);
         get_rx_subtree()->create<std::string>("power_mode/value")
-            .add_coerced_subscriber(boost::bind(&ubx_xcvr::set_power_mode, this, _1))
+            .add_coerced_subscriber(boost::bind(&ubx_xcvr::set_power_mode, this, boost::placeholders::_1))
             .set("performance");
         get_rx_subtree()->create<std::vector<std::string> >("xcvr_mode/options")
             .set(ubx_xcvr_modes);
         get_rx_subtree()->create<std::string>("xcvr_mode/value")
-            .add_coerced_subscriber(boost::bind(&ubx_xcvr::set_xcvr_mode, this, _1))
+            .add_coerced_subscriber(boost::bind(&ubx_xcvr::set_xcvr_mode, this, boost::placeholders::_1))
             .set("FDX");
         get_rx_subtree()->create<std::vector<std::string> >("temp_comp_mode/options")
             .set(ubx_temp_comp_modes);
@@ -456,12 +456,12 @@ public:
         get_tx_subtree()->create<std::vector<std::string> >("power_mode/options")
             .set(ubx_power_modes);
         get_tx_subtree()->create<std::string>("power_mode/value")
-            .add_coerced_subscriber(boost::bind(&uhd::property<std::string>::set, &get_rx_subtree()->access<std::string>("power_mode/value"), _1))
+            .add_coerced_subscriber(boost::bind(&uhd::property<std::string>::set, &get_rx_subtree()->access<std::string>("power_mode/value"), boost::placeholders::_1))
             .set_publisher(boost::bind(&uhd::property<std::string>::get, &get_rx_subtree()->access<std::string>("power_mode/value")));
         get_tx_subtree()->create<std::vector<std::string> >("xcvr_mode/options")
             .set(ubx_xcvr_modes);
         get_tx_subtree()->create<std::string>("xcvr_mode/value")
-            .add_coerced_subscriber(boost::bind(&uhd::property<std::string>::set, &get_rx_subtree()->access<std::string>("xcvr_mode/value"), _1))
+            .add_coerced_subscriber(boost::bind(&uhd::property<std::string>::set, &get_rx_subtree()->access<std::string>("xcvr_mode/value"), boost::placeholders::_1))
             .set_publisher(boost::bind(&uhd::property<std::string>::get, &get_rx_subtree()->access<std::string>("xcvr_mode/value")));
         get_tx_subtree()->create<std::vector<std::string> >("temp_comp_mode/options")
             .set(ubx_temp_comp_modes);
@@ -488,18 +488,18 @@ public:
         get_tx_subtree()->create<sensor_value_t>("sensors/lo_locked")
             .set_publisher(boost::bind(&ubx_xcvr::get_locked, this, "TXLO"));
         get_tx_subtree()->create<double>("gains/PGA0/value")
-            .set_coercer(boost::bind(&ubx_xcvr::set_tx_gain, this, _1)).set(0);
+            .set_coercer(boost::bind(&ubx_xcvr::set_tx_gain, this, boost::placeholders::_1)).set(0);
         get_tx_subtree()->create<meta_range_t>("gains/PGA0/range")
             .set(ubx_tx_gain_range);
         get_tx_subtree()->create<double>("freq/value")
-            .set_coercer(boost::bind(&ubx_xcvr::set_tx_freq, this, _1))
+            .set_coercer(boost::bind(&ubx_xcvr::set_tx_freq, this, boost::placeholders::_1))
             .set(ubx_freq_range.start());
         get_tx_subtree()->create<meta_range_t>("freq/range")
             .set(ubx_freq_range);
         get_tx_subtree()->create<std::vector<std::string> >("antenna/options")
             .set(ubx_tx_antennas);
         get_tx_subtree()->create<std::string>("antenna/value")
-            .set_coercer(boost::bind(&ubx_xcvr::set_tx_ant, this, _1))
+            .set_coercer(boost::bind(&ubx_xcvr::set_tx_ant, this, boost::placeholders::_1))
             .set(ubx_tx_antennas.at(0));
         get_tx_subtree()->create<std::string>("connection")
             .set("QI");
@@ -512,7 +512,7 @@ public:
         get_tx_subtree()->create<meta_range_t>("bandwidth/range")
             .set(freq_range_t(bw, bw));
         get_tx_subtree()->create<int64_t>("sync_delay")
-            .add_coerced_subscriber(boost::bind(&ubx_xcvr::set_sync_delay, this, true, _1))
+            .add_coerced_subscriber(boost::bind(&ubx_xcvr::set_sync_delay, this, true, boost::placeholders::_1))
             .set(0);
 
         ////////////////////////////////////////////////////////////////////
@@ -524,19 +524,19 @@ public:
         get_rx_subtree()->create<sensor_value_t>("sensors/lo_locked")
             .set_publisher(boost::bind(&ubx_xcvr::get_locked, this, "RXLO"));
         get_rx_subtree()->create<double>("gains/PGA0/value")
-            .set_coercer(boost::bind(&ubx_xcvr::set_rx_gain, this, _1))
+            .set_coercer(boost::bind(&ubx_xcvr::set_rx_gain, this, boost::placeholders::_1))
             .set(0);
         get_rx_subtree()->create<meta_range_t>("gains/PGA0/range")
             .set(ubx_rx_gain_range);
         get_rx_subtree()->create<double>("freq/value")
-            .set_coercer(boost::bind(&ubx_xcvr::set_rx_freq, this, _1))
+            .set_coercer(boost::bind(&ubx_xcvr::set_rx_freq, this, boost::placeholders::_1))
             .set(ubx_freq_range.start());
         get_rx_subtree()->create<meta_range_t>("freq/range")
             .set(ubx_freq_range);
         get_rx_subtree()->create<std::vector<std::string> >("antenna/options")
             .set(ubx_rx_antennas);
         get_rx_subtree()->create<std::string>("antenna/value")
-            .set_coercer(boost::bind(&ubx_xcvr::set_rx_ant, this, _1)).set("RX2");
+            .set_coercer(boost::bind(&ubx_xcvr::set_rx_ant, this, boost::placeholders::_1)).set("RX2");
         get_rx_subtree()->create<std::string>("connection")
             .set("IQ");
         get_rx_subtree()->create<bool>("enabled")
@@ -548,7 +548,7 @@ public:
         get_rx_subtree()->create<meta_range_t>("bandwidth/range")
             .set(freq_range_t(bw, bw));
         get_rx_subtree()->create<int64_t>("sync_delay")
-            .add_coerced_subscriber(boost::bind(&ubx_xcvr::set_sync_delay, this, false, _1))
+            .add_coerced_subscriber(boost::bind(&ubx_xcvr::set_sync_delay, this, false, boost::placeholders::_1))
             .set(0);
     }
 
