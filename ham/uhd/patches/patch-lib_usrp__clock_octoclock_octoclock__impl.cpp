$NetBSD: patch-lib_usrp__clock_octoclock_octoclock__impl.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp_clock/octoclock/octoclock_impl.cpp.orig	2020-05-09 17:03:32.128126677 +0000
+++ lib/usrp_clock/octoclock/octoclock_impl.cpp
@@ -232,7 +232,7 @@ octoclock_impl::octoclock_impl(const dev
         _oc_dict[oc].eeprom = octoclock_eeprom_t(_oc_dict[oc].ctrl_xport, _proto_ver);
         _tree->create<octoclock_eeprom_t>(oc_path / "eeprom")
             .set(_oc_dict[oc].eeprom)
-            .add_coerced_subscriber(boost::bind(&octoclock_impl::_set_eeprom, this, oc, _1));
+            .add_coerced_subscriber(boost::bind(&octoclock_impl::_set_eeprom, this, oc, boost::placeholders::_1));
 
         ////////////////////////////////////////////////////////////////////
         // Initialize non-GPSDO sensors
