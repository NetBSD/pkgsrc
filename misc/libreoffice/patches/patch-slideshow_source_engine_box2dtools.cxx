$NetBSD: patch-slideshow_source_engine_box2dtools.cxx,v 1.1 2021/02/06 06:47:24 ryoon Exp $

Use std::isfinite() for include/box2d/b2_math.h.

--- slideshow/source/engine/box2dtools.cxx.orig	2021-01-27 19:33:49.000000000 +0000
+++ slideshow/source/engine/box2dtools.cxx
@@ -7,6 +7,8 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/.
  */
 
+using namespace std;
+
 #include <box2dtools.hxx>
 #include <config_box2d.h>
 #include BOX2D_HEADER
