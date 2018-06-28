$NetBSD: patch-src_live__effects_lpe-lattice2.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/live_effects/lpe-lattice2.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/live_effects/lpe-lattice2.cpp
@@ -37,6 +37,8 @@
 // TODO due to internal breakage in glibmm headers, this must be last:
 #include <glibmm/i18n.h>
 
+using std::pow;
+
 using namespace Geom;
 
 namespace Inkscape {
