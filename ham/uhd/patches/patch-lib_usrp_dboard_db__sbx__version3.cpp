$NetBSD: patch-lib_usrp_dboard_db__sbx__version3.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_sbx_version3.cpp.orig	2020-05-09 15:37:17.228299743 +0000
+++ lib/usrp/dboard/db_sbx_version3.cpp
@@ -20,8 +20,8 @@ using namespace boost::assign;
 sbx_xcvr::sbx_version3::sbx_version3(sbx_xcvr *_self_sbx_xcvr) {
     //register the handle to our base SBX class
     self_base = _self_sbx_xcvr;
-    _txlo = adf435x_iface::make_adf4350(boost::bind(&sbx_xcvr::sbx_version3::write_lo_regs, this, dboard_iface::UNIT_TX, _1));
-    _rxlo = adf435x_iface::make_adf4350(boost::bind(&sbx_xcvr::sbx_version3::write_lo_regs, this, dboard_iface::UNIT_RX, _1));
+    _txlo = adf435x_iface::make_adf4350(boost::bind(&sbx_xcvr::sbx_version3::write_lo_regs, this, dboard_iface::UNIT_TX, boost::placeholders::_1));
+    _rxlo = adf435x_iface::make_adf4350(boost::bind(&sbx_xcvr::sbx_version3::write_lo_regs, this, dboard_iface::UNIT_RX, boost::placeholders::_1));
 }
 
 sbx_xcvr::sbx_version3::~sbx_version3(void){
