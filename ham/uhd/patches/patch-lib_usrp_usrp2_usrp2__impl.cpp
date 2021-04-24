$NetBSD: patch-lib_usrp_usrp2_usrp2__impl.cpp,v 1.1 2021/04/24 16:34:54 tnn Exp $

libuhd.so.3.15.0: undefined reference to `int boost::math::sign<double>(double const&)'

--- lib/usrp/usrp2/usrp2_impl.cpp.orig	2020-01-01 04:21:49.000000000 +0000
+++ lib/usrp/usrp2/usrp2_impl.cpp
@@ -835,6 +835,9 @@ void usrp2_impl::set_tx_fe_corrections(c
     }
 }
 
+#include <boost/math/special_functions/round.hpp>
+#include <boost/math/special_functions/sign.hpp>
+
 double usrp2_impl::set_tx_dsp_freq(
     const std::string &mb,
     const double freq_
@@ -878,8 +881,6 @@ meta_range_t usrp2_impl::get_tx_dsp_freq
     );
 }
 
-#include <boost/math/special_functions/round.hpp>
-#include <boost/math/special_functions/sign.hpp>
 
 void usrp2_impl::update_clock_source(const std::string &mb, const std::string &source){
     //NOTICE: U2_REG_MISC_CTRL_CLOCK is on the wb clock, and cannot be set from fifo_ctrl
