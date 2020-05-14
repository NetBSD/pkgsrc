$NetBSD: patch-lib_usrp_x300_x300__radio__ctrl__impl.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/x300/x300_radio_ctrl_impl.cpp.orig	2020-05-09 16:48:46.365817291 +0000
+++ lib/usrp/x300/x300_radio_ctrl_impl.cpp
@@ -151,7 +151,7 @@ UHD_RFNOC_RADIO_BLOCK_CONSTRUCTOR(x300_r
     _tree->create<meta_range_t>("rx_codecs" / _radio_slot / "gains" / "digital" / "range")
         .set(meta_range_t(0, 6.0, 0.5));
     _tree->create<double>("rx_codecs" / _radio_slot / "gains" / "digital" / "value")
-        .add_coerced_subscriber(boost::bind(&x300_adc_ctrl::set_gain, _adc, _1))
+        .add_coerced_subscriber(boost::bind(&x300_adc_ctrl::set_gain, _adc, boost::placeholders::_1))
         .set(0);
 
     ////////////////////////////////////////////////////////////////
@@ -187,7 +187,7 @@ UHD_RFNOC_RADIO_BLOCK_CONSTRUCTOR(x300_r
         if (_tree->exists(fs_path("time") / "cmd")) {
             _tree->access<time_spec_t>(fs_path("time") / "cmd")
                 .add_coerced_subscriber(
-                    boost::bind(&x300_radio_ctrl_impl::set_fe_cmd_time, this, _1, i));
+                    boost::bind(&x300_radio_ctrl_impl::set_fe_cmd_time, this, boost::placeholders::_1, i));
         }
     }
 
@@ -820,7 +820,7 @@ void x300_radio_ctrl_impl::setup_radio(u
                 this,
                 zpu_i2c,
                 (BASE_ADDR | addr),
-                _1));
+                boost::placeholders::_1));
     }
 
     // create a new dboard interface
@@ -894,7 +894,7 @@ void x300_radio_ctrl_impl::setup_radio(u
                                           / _rx_fe_map[i].db_fe_name / "antenna"
                                           / "value")
                     .add_desired_subscriber(boost::bind(
-                        &x300_radio_ctrl_impl::_update_atr_leds, this, _1, i));
+                        &x300_radio_ctrl_impl::_update_atr_leds, this, boost::placeholders::_1, i));
                 _update_atr_leds(_tree
                                      ->access<std::string>(db_path / "rx_frontends"
                                                            / _rx_fe_map[i].db_fe_name
@@ -921,7 +921,7 @@ void x300_radio_ctrl_impl::setup_radio(u
                             this,
                             db_path,
                             _root_path / "tx_fe_corrections" / _tx_fe_map[i].db_fe_name,
-                            _1));
+                            boost::placeholders::_1));
             }
         }
     }
@@ -938,7 +938,7 @@ void x300_radio_ctrl_impl::setup_radio(u
                             this,
                             db_path,
                             _root_path / "rx_fe_corrections" / _tx_fe_map[i].db_fe_name,
-                            _1));
+                            boost::placeholders::_1));
             }
         }
     }
