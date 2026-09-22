$NetBSD: patch-slideshow_source_engine_box2dtools.cxx,v 1.2 2026/09/22 08:34:00 ryoon Exp $

Use std::isfinite() for include/box2d/b2_math.h.

--- slideshow/source/engine/box2dtools.cxx.orig	2026-08-21 12:51:44.000000000 +0000
+++ slideshow/source/engine/box2dtools.cxx
@@ -7,6 +7,8 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/.
  */
 
+using namespace std;
+
 #include <box2dtools.hxx>
 
 #include <shapemanager.hxx>
