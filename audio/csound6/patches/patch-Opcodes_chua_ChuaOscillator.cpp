$NetBSD: patch-Opcodes_chua_ChuaOscillator.cpp,v 1.1 2017/06/17 19:34:21 joerg Exp $

Workaround for Boost 1.64.

--- Opcodes/chua/ChuaOscillator.cpp.orig	2017-06-10 17:12:52.846589223 +0000
+++ Opcodes/chua/ChuaOscillator.cpp
@@ -118,6 +118,7 @@
 //     gnor = a*(x.^3) + b*(x.^2) + c*x + d;
 
 #include <OpcodeBase.hpp>
+#include <boost/serialization/array_wrapper.hpp>
 #include <boost/numeric/ublas/vector.hpp>
 using namespace boost::numeric;
 #include <cmath>
