$NetBSD: patch-lib_usrp_dboard_db__cbx.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_cbx.cpp.orig	2020-05-09 15:39:26.631024880 +0000
+++ lib/usrp/dboard/db_cbx.cpp
@@ -19,8 +19,8 @@ using namespace boost::assign;
 sbx_xcvr::cbx::cbx(sbx_xcvr *_self_sbx_xcvr) {
     //register the handle to our base CBX class
     self_base = _self_sbx_xcvr;
-    _txlo = max287x_iface::make<max2870>(boost::bind(&sbx_xcvr::cbx::write_lo_regs, this, dboard_iface::UNIT_TX, _1));
-    _rxlo = max287x_iface::make<max2870>(boost::bind(&sbx_xcvr::cbx::write_lo_regs, this, dboard_iface::UNIT_RX, _1));
+    _txlo = max287x_iface::make<max2870>(boost::bind(&sbx_xcvr::cbx::write_lo_regs, this, dboard_iface::UNIT_TX, boost::placeholders::_1));
+    _rxlo = max287x_iface::make<max2870>(boost::bind(&sbx_xcvr::cbx::write_lo_regs, this, dboard_iface::UNIT_RX, boost::placeholders::_1));
 }
 
 
