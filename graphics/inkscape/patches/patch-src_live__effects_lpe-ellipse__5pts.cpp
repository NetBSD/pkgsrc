$NetBSD: patch-src_live__effects_lpe-ellipse__5pts.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/live_effects/lpe-ellipse_5pts.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/live_effects/lpe-ellipse_5pts.cpp
@@ -23,6 +23,9 @@
 #include "desktop.h"
 #include "message-stack.h"
 
+using std::cos;
+using std::sin;
+
 namespace Inkscape {
 namespace LivePathEffect {
 
