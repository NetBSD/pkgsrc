$NetBSD: patch-lib_usrp_cores_rx__frontend__core__3000.cpp,v 1.1 2021/04/24 16:34:54 tnn Exp $

libuhd.so.3.15.0: undefined reference to `int boost::math::sign<double>(double const&)'

--- lib/usrp/cores/rx_frontend_core_3000.cpp.orig	2020-01-01 04:21:49.000000000 +0000
+++ lib/usrp/cores/rx_frontend_core_3000.cpp
@@ -13,6 +13,7 @@
 #include <boost/assign/list_of.hpp>
 #include <boost/bind.hpp>
 #include <boost/math/special_functions/round.hpp>
+#include <boost/math/special_functions/sign.hpp>
 
 using namespace uhd;
 
