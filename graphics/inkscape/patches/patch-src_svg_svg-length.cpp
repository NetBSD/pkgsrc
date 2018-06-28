$NetBSD: patch-src_svg_svg-length.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/svg/svg-length.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/svg/svg-length.cpp
@@ -20,6 +20,8 @@
 #include "stringstream.h"
 #include "util/units.h"
 
+using std::pow;
+
 static unsigned sp_svg_length_read_lff(gchar const *str, SVGLength::Unit *unit, float *val, float *computed, char **next);
 
 #ifndef MAX
