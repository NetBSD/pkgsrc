$NetBSD: patch-librecad_src_lib_engine_rs__ellipse.cpp,v 1.1 2021/05/22 10:18:23 nia Exp $

Subject: [PATCH] add boost tuple include to fix build

With boost 1.76, we see:
lib/engine/rs_ellipse.cpp:70:15: error: 'tuple' in namespace 'boost::math' does not name a template type
   70 |  boost::math::tuple<double, double, double> operator()(double const& z) const {
      |               ^~~~~

Fix this by including the proper boost header.

https://github.com/LibreCAD/LibreCAD/pull/1345

--- librecad/src/lib/engine/rs_ellipse.cpp.orig	2020-12-29 23:31:50.000000000 +0000
+++ librecad/src/lib/engine/rs_ellipse.cpp
@@ -48,6 +48,9 @@
 #include <boost/version.hpp>
 #include <boost/math/tools/roots.hpp>
 #include <boost/math/special_functions/ellint_2.hpp>
+#if BOOST_VERSION > 104500
+#include <boost/math/tools/tuple.hpp>
+#endif
 #endif
 
 namespace{
