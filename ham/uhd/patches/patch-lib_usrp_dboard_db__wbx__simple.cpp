$NetBSD: patch-lib_usrp_dboard_db__wbx__simple.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/dboard/db_wbx_simple.cpp.orig	2020-05-09 15:49:57.928917699 +0000
+++ lib/usrp/dboard/db_wbx_simple.cpp
@@ -78,7 +78,7 @@ wbx_simple::wbx_simple(ctor_args_t args)
         std::string(str(boost::format("%s+GDB") % this->get_rx_subtree()->access<std::string>("name").get()
     )));
     this->get_rx_subtree()->create<std::string>("antenna/value")
-        .add_coerced_subscriber(boost::bind(&wbx_simple::set_rx_ant, this, _1))
+        .add_coerced_subscriber(boost::bind(&wbx_simple::set_rx_ant, this, boost::placeholders::_1))
         .set("RX2");
     this->get_rx_subtree()->create<std::vector<std::string> >("antenna/options")
         .set(wbx_rx_antennas);
@@ -90,7 +90,7 @@ wbx_simple::wbx_simple(ctor_args_t args)
         std::string(str(boost::format("%s+GDB") % this->get_tx_subtree()->access<std::string>("name").get()
     )));
     this->get_tx_subtree()->create<std::string>("antenna/value")
-        .add_coerced_subscriber(boost::bind(&wbx_simple::set_tx_ant, this, _1))
+        .add_coerced_subscriber(boost::bind(&wbx_simple::set_tx_ant, this, boost::placeholders::_1))
         .set(wbx_tx_antennas.at(0));
     this->get_tx_subtree()->create<std::vector<std::string> >("antenna/options")
         .set(wbx_tx_antennas);
