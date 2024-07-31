$NetBSD: patch-scipy_special_boost__special__functions.h,v 1.1 2024/07/31 18:15:38 adam Exp $

Fix build.

--- scipy/special/boost_special_functions.h.orig	2024-07-31 10:20:15.401014832 +0000
+++ scipy/special/boost_special_functions.h
@@ -5,6 +5,7 @@
 #include <stdexcept>
 #include "sf_error.h"
 
+using std::isnan;
 
 // Override some default BOOST policies.
 // These are required to ensure that the Boost function ibeta_inv
