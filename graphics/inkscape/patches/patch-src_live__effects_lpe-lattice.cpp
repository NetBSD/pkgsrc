$NetBSD: patch-src_live__effects_lpe-lattice.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/live_effects/lpe-lattice.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/live_effects/lpe-lattice.cpp
@@ -33,6 +33,8 @@
 
 #include "desktop.h" // TODO: should be factored out (see below)
 
+using std::pow;
+
 using namespace Geom;
 
 namespace Inkscape {
