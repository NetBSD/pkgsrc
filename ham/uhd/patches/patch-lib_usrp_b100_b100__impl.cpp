$NetBSD: patch-lib_usrp_b100_b100__impl.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/b100/b100_impl.cpp.orig	2020-05-09 16:46:31.268190497 +0000
+++ lib/usrp/b100/b100_impl.cpp
@@ -274,7 +274,7 @@ b100_impl::b100_impl(const device_addr_t
     _tree->create<std::string>(mb_path / "name").set("B100");
     _tree->create<std::string>(mb_path / "codename").set("B-Hundo");
     _tree->create<std::string>(mb_path / "load_eeprom")
-        .add_coerced_subscriber(boost::bind(&fx2_ctrl::usrp_load_eeprom, _fx2_ctrl, _1));
+        .add_coerced_subscriber(boost::bind(&fx2_ctrl::usrp_load_eeprom, _fx2_ctrl, boost::placeholders::_1));
 
     ////////////////////////////////////////////////////////////////////
     // setup the mboard eeprom
@@ -282,7 +282,7 @@ b100_impl::b100_impl(const device_addr_t
     const mboard_eeprom_t mb_eeprom = this->get_mb_eeprom(_fx2_ctrl);
     _tree->create<mboard_eeprom_t>(mb_path / "eeprom")
         .set(mb_eeprom)
-        .add_coerced_subscriber(boost::bind(&b100_impl::set_mb_eeprom, this, _1));
+        .add_coerced_subscriber(boost::bind(&b100_impl::set_mb_eeprom, this, boost::placeholders::_1));
 
     ////////////////////////////////////////////////////////////////////
     // create clock control objects
@@ -290,12 +290,12 @@ b100_impl::b100_impl(const device_addr_t
     //^^^ clock created up top, just reg props here... ^^^
     _tree->create<double>(mb_path / "tick_rate")
         .set_publisher(boost::bind(&b100_clock_ctrl::get_fpga_clock_rate, _clock_ctrl))
-        .add_coerced_subscriber(boost::bind(&fifo_ctrl_excelsior::set_tick_rate, _fifo_ctrl, _1))
-        .add_coerced_subscriber(boost::bind(&b100_impl::update_tick_rate, this, _1));
+        .add_coerced_subscriber(boost::bind(&fifo_ctrl_excelsior::set_tick_rate, _fifo_ctrl, boost::placeholders::_1))
+        .add_coerced_subscriber(boost::bind(&b100_impl::update_tick_rate, this, boost::placeholders::_1));
 
     //add_coerced_subscriber the command time while we are at it
     _tree->create<time_spec_t>(mb_path / "time/cmd")
-        .add_coerced_subscriber(boost::bind(&fifo_ctrl_excelsior::set_time, _fifo_ctrl, _1));
+        .add_coerced_subscriber(boost::bind(&fifo_ctrl_excelsior::set_time, _fifo_ctrl, boost::placeholders::_1));
 
     ////////////////////////////////////////////////////////////////////
     // create codec control objects
@@ -306,12 +306,12 @@ b100_impl::b100_impl(const device_addr_t
     _tree->create<std::string>(rx_codec_path / "name").set("ad9522");
     _tree->create<meta_range_t>(rx_codec_path / "gains/pga/range").set(b100_codec_ctrl::rx_pga_gain_range);
     _tree->create<double>(rx_codec_path / "gains/pga/value")
-        .set_coercer(boost::bind(&b100_impl::update_rx_codec_gain, this, _1))
+        .set_coercer(boost::bind(&b100_impl::update_rx_codec_gain, this, boost::placeholders::_1))
         .set(0.0);
     _tree->create<std::string>(tx_codec_path / "name").set("ad9522");
     _tree->create<meta_range_t>(tx_codec_path / "gains/pga/range").set(b100_codec_ctrl::tx_pga_gain_range);
     _tree->create<double>(tx_codec_path / "gains/pga/value")
-        .add_coerced_subscriber(boost::bind(&b100_codec_ctrl::set_tx_pga_gain, _codec_ctrl, _1))
+        .add_coerced_subscriber(boost::bind(&b100_codec_ctrl::set_tx_pga_gain, _codec_ctrl, boost::placeholders::_1))
         .set_publisher(boost::bind(&b100_codec_ctrl::get_tx_pga_gain, _codec_ctrl))
         .set(0.0);
 
@@ -328,27 +328,27 @@ b100_impl::b100_impl(const device_addr_t
     _tx_fe = tx_frontend_core_200::make(_fifo_ctrl, TOREG(SR_TX_FE));
 
     _tree->create<subdev_spec_t>(mb_path / "rx_subdev_spec")
-        .add_coerced_subscriber(boost::bind(&b100_impl::update_rx_subdev_spec, this, _1));
+        .add_coerced_subscriber(boost::bind(&b100_impl::update_rx_subdev_spec, this, boost::placeholders::_1));
     _tree->create<subdev_spec_t>(mb_path / "tx_subdev_spec")
-        .add_coerced_subscriber(boost::bind(&b100_impl::update_tx_subdev_spec, this, _1));
+        .add_coerced_subscriber(boost::bind(&b100_impl::update_tx_subdev_spec, this, boost::placeholders::_1));
 
     const fs_path rx_fe_path = mb_path / "rx_frontends" / "A";
     const fs_path tx_fe_path = mb_path / "tx_frontends" / "A";
 
     _tree->create<std::complex<double> >(rx_fe_path / "dc_offset" / "value")
-        .set_coercer(boost::bind(&rx_frontend_core_200::set_dc_offset, _rx_fe, _1))
+        .set_coercer(boost::bind(&rx_frontend_core_200::set_dc_offset, _rx_fe, boost::placeholders::_1))
         .set(std::complex<double>(0.0, 0.0));
     _tree->create<bool>(rx_fe_path / "dc_offset" / "enable")
-        .add_coerced_subscriber(boost::bind(&rx_frontend_core_200::set_dc_offset_auto, _rx_fe, _1))
+        .add_coerced_subscriber(boost::bind(&rx_frontend_core_200::set_dc_offset_auto, _rx_fe, boost::placeholders::_1))
         .set(true);
     _tree->create<std::complex<double> >(rx_fe_path / "iq_balance" / "value")
-        .add_coerced_subscriber(boost::bind(&rx_frontend_core_200::set_iq_balance, _rx_fe, _1))
+        .add_coerced_subscriber(boost::bind(&rx_frontend_core_200::set_iq_balance, _rx_fe, boost::placeholders::_1))
         .set(std::complex<double>(0.0, 0.0));
     _tree->create<std::complex<double> >(tx_fe_path / "dc_offset" / "value")
-        .set_coercer(boost::bind(&tx_frontend_core_200::set_dc_offset, _tx_fe, _1))
+        .set_coercer(boost::bind(&tx_frontend_core_200::set_dc_offset, _tx_fe, boost::placeholders::_1))
         .set(std::complex<double>(0.0, 0.0));
     _tree->create<std::complex<double> >(tx_fe_path / "iq_balance" / "value")
-        .add_coerced_subscriber(boost::bind(&tx_frontend_core_200::set_iq_balance, _tx_fe, _1))
+        .add_coerced_subscriber(boost::bind(&tx_frontend_core_200::set_iq_balance, _tx_fe, boost::placeholders::_1))
         .set(std::complex<double>(0.0, 0.0));
 
     ////////////////////////////////////////////////////////////////////
@@ -367,20 +367,20 @@ b100_impl::b100_impl(const device_addr_t
 
         _rx_dsps[dspno]->set_link_rate(B100_LINK_RATE_BPS);
         _tree->access<double>(mb_path / "tick_rate")
-            .add_coerced_subscriber(boost::bind(&rx_dsp_core_200::set_tick_rate, _rx_dsps[dspno], _1));
+            .add_coerced_subscriber(boost::bind(&rx_dsp_core_200::set_tick_rate, _rx_dsps[dspno], boost::placeholders::_1));
         fs_path rx_dsp_path = mb_path / str(boost::format("rx_dsps/%u") % dspno);
         _tree->create<meta_range_t>(rx_dsp_path / "rate/range")
             .set_publisher(boost::bind(&rx_dsp_core_200::get_host_rates, _rx_dsps[dspno]));
         _tree->create<double>(rx_dsp_path / "rate/value")
             .set(1e6) //some default
-            .set_coercer(boost::bind(&rx_dsp_core_200::set_host_rate, _rx_dsps[dspno], _1))
-            .add_coerced_subscriber(boost::bind(&b100_impl::update_rx_samp_rate, this, dspno, _1));
+            .set_coercer(boost::bind(&rx_dsp_core_200::set_host_rate, _rx_dsps[dspno], boost::placeholders::_1))
+            .add_coerced_subscriber(boost::bind(&b100_impl::update_rx_samp_rate, this, dspno, boost::placeholders::_1));
         _tree->create<double>(rx_dsp_path / "freq/value")
-            .set_coercer(boost::bind(&rx_dsp_core_200::set_freq, _rx_dsps[dspno], _1));
+            .set_coercer(boost::bind(&rx_dsp_core_200::set_freq, _rx_dsps[dspno], boost::placeholders::_1));
         _tree->create<meta_range_t>(rx_dsp_path / "freq/range")
             .set_publisher(boost::bind(&rx_dsp_core_200::get_freq_range, _rx_dsps[dspno]));
         _tree->create<stream_cmd_t>(rx_dsp_path / "stream_cmd")
-            .add_coerced_subscriber(boost::bind(&rx_dsp_core_200::issue_stream_command, _rx_dsps[dspno], _1));
+            .add_coerced_subscriber(boost::bind(&rx_dsp_core_200::issue_stream_command, _rx_dsps[dspno], boost::placeholders::_1));
     }
 
     ////////////////////////////////////////////////////////////////////
@@ -391,15 +391,15 @@ b100_impl::b100_impl(const device_addr_t
     );
     _tx_dsp->set_link_rate(B100_LINK_RATE_BPS);
     _tree->access<double>(mb_path / "tick_rate")
-        .add_coerced_subscriber(boost::bind(&tx_dsp_core_200::set_tick_rate, _tx_dsp, _1));
+        .add_coerced_subscriber(boost::bind(&tx_dsp_core_200::set_tick_rate, _tx_dsp, boost::placeholders::_1));
     _tree->create<meta_range_t>(mb_path / "tx_dsps/0/rate/range")
         .set_publisher(boost::bind(&tx_dsp_core_200::get_host_rates, _tx_dsp));
     _tree->create<double>(mb_path / "tx_dsps/0/rate/value")
         .set(1e6) //some default
-        .set_coercer(boost::bind(&tx_dsp_core_200::set_host_rate, _tx_dsp, _1))
-        .add_coerced_subscriber(boost::bind(&b100_impl::update_tx_samp_rate, this, 0, _1));
+        .set_coercer(boost::bind(&tx_dsp_core_200::set_host_rate, _tx_dsp, boost::placeholders::_1))
+        .add_coerced_subscriber(boost::bind(&b100_impl::update_tx_samp_rate, this, 0, boost::placeholders::_1));
     _tree->create<double>(mb_path / "tx_dsps/0/freq/value")
-        .set_coercer(boost::bind(&tx_dsp_core_200::set_freq, _tx_dsp, _1));
+        .set_coercer(boost::bind(&tx_dsp_core_200::set_freq, _tx_dsp, boost::placeholders::_1));
     _tree->create<meta_range_t>(mb_path / "tx_dsps/0/freq/range")
         .set_publisher(boost::bind(&tx_dsp_core_200::get_freq_range, _tx_dsp));
 
@@ -415,21 +415,21 @@ b100_impl::b100_impl(const device_addr_t
         _fifo_ctrl, TOREG(SR_TIME64), time64_rb_bases
     );
     _tree->access<double>(mb_path / "tick_rate")
-        .add_coerced_subscriber(boost::bind(&time64_core_200::set_tick_rate, _time64, _1));
+        .add_coerced_subscriber(boost::bind(&time64_core_200::set_tick_rate, _time64, boost::placeholders::_1));
     _tree->create<time_spec_t>(mb_path / "time/now")
         .set_publisher(boost::bind(&time64_core_200::get_time_now, _time64))
-        .add_coerced_subscriber(boost::bind(&time64_core_200::set_time_now, _time64, _1));
+        .add_coerced_subscriber(boost::bind(&time64_core_200::set_time_now, _time64, boost::placeholders::_1));
     _tree->create<time_spec_t>(mb_path / "time/pps")
         .set_publisher(boost::bind(&time64_core_200::get_time_last_pps, _time64))
-        .add_coerced_subscriber(boost::bind(&time64_core_200::set_time_next_pps, _time64, _1));
+        .add_coerced_subscriber(boost::bind(&time64_core_200::set_time_next_pps, _time64, boost::placeholders::_1));
     //setup time source props
     _tree->create<std::string>(mb_path / "time_source/value")
-        .add_coerced_subscriber(boost::bind(&time64_core_200::set_time_source, _time64, _1));
+        .add_coerced_subscriber(boost::bind(&time64_core_200::set_time_source, _time64, boost::placeholders::_1));
     _tree->create<std::vector<std::string> >(mb_path / "time_source/options")
         .set_publisher(boost::bind(&time64_core_200::get_time_sources, _time64));
     //setup reference source props
     _tree->create<std::string>(mb_path / "clock_source/value")
-        .add_coerced_subscriber(boost::bind(&b100_impl::update_clock_source, this, _1));
+        .add_coerced_subscriber(boost::bind(&b100_impl::update_clock_source, this, boost::placeholders::_1));
     static const std::vector<std::string> clock_sources = {
         "internal", "external", "auto"
     };
@@ -440,7 +440,7 @@ b100_impl::b100_impl(const device_addr_t
     ////////////////////////////////////////////////////////////////////
     _user = user_settings_core_200::make(_fifo_ctrl, TOREG(SR_USER_REGS));
     _tree->create<user_settings_core_200::user_reg_t>(mb_path / "user/regs")
-        .add_coerced_subscriber(boost::bind(&user_settings_core_200::set_reg, _user, _1));
+        .add_coerced_subscriber(boost::bind(&user_settings_core_200::set_reg, _user, boost::placeholders::_1));
 
     ////////////////////////////////////////////////////////////////////
     // create dboard control objects
@@ -458,13 +458,13 @@ b100_impl::b100_impl(const device_addr_t
     //create the properties and register subscribers
     _tree->create<dboard_eeprom_t>(mb_path / "dboards/A/rx_eeprom")
         .set(rx_db_eeprom)
-        .add_coerced_subscriber(boost::bind(&b100_impl::set_db_eeprom, this, "rx", _1));
+        .add_coerced_subscriber(boost::bind(&b100_impl::set_db_eeprom, this, "rx", boost::placeholders::_1));
     _tree->create<dboard_eeprom_t>(mb_path / "dboards/A/tx_eeprom")
         .set(tx_db_eeprom)
-        .add_coerced_subscriber(boost::bind(&b100_impl::set_db_eeprom, this, "tx", _1));
+        .add_coerced_subscriber(boost::bind(&b100_impl::set_db_eeprom, this, "tx", boost::placeholders::_1));
     _tree->create<dboard_eeprom_t>(mb_path / "dboards/A/gdb_eeprom")
         .set(gdb_eeprom)
-        .add_coerced_subscriber(boost::bind(&b100_impl::set_db_eeprom, this, "gdb", _1));
+        .add_coerced_subscriber(boost::bind(&b100_impl::set_db_eeprom, this, "gdb", boost::placeholders::_1));
 
     //create a new dboard interface and manager
     _dboard_manager = dboard_manager::make(
@@ -477,12 +477,12 @@ b100_impl::b100_impl(const device_addr_t
     const fs_path db_tx_fe_path = mb_path / "dboards" / "A" / "tx_frontends";
     for(const std::string &name:  _tree->list(db_tx_fe_path)){
         _tree->access<double>(db_tx_fe_path / name / "freq" / "value")
-            .add_coerced_subscriber(boost::bind(&b100_impl::set_tx_fe_corrections, this, _1));
+            .add_coerced_subscriber(boost::bind(&b100_impl::set_tx_fe_corrections, this, boost::placeholders::_1));
     }
     const fs_path db_rx_fe_path = mb_path / "dboards" / "A" / "rx_frontends";
     for(const std::string &name:  _tree->list(db_rx_fe_path)){
         _tree->access<double>(db_rx_fe_path / name / "freq" / "value")
-            .add_coerced_subscriber(boost::bind(&b100_impl::set_rx_fe_corrections, this, _1));
+            .add_coerced_subscriber(boost::bind(&b100_impl::set_rx_fe_corrections, this, boost::placeholders::_1));
     }
 
     //initialize io handling
@@ -498,7 +498,7 @@ b100_impl::b100_impl(const device_addr_t
     this->update_rates();
 
     _tree->access<double>(mb_path / "tick_rate") //now add_coerced_subscriber the clock rate setter
-        .add_coerced_subscriber(boost::bind(&b100_clock_ctrl::set_fpga_clock_rate, _clock_ctrl, _1));
+        .add_coerced_subscriber(boost::bind(&b100_clock_ctrl::set_fpga_clock_rate, _clock_ctrl, boost::placeholders::_1));
 
     //reset cordic rates and their properties to zero
     for(const std::string &name:  _tree->list(mb_path / "rx_dsps")){
