$NetBSD: patch-scipy_special_boost__special__functions.h,v 1.2 2025/01/05 08:58:47 adam Exp $

Fix build.

--- scipy/special/boost_special_functions.h.orig	2025-01-02 22:53:29.000000000 +0000
+++ scipy/special/boost_special_functions.h
@@ -5,6 +5,7 @@
 #include <stdexcept>
 #include "sf_error.h"
 
+using std::isnan;
 
 #include "boost/math/special_functions/beta.hpp"
 #include "boost/math/special_functions/erf.hpp"
