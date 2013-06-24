$NetBSD: patch-src_plugins_render_satellites_mex_astrolib.h,v 1.1 2013/06/24 06:52:52 jperkin Exp $

Avoid 'sun' clash.

--- src/plugins/render/satellites/mex/astrolib.h.orig	2013-05-03 04:38:26.036168912 +0000
+++ src/plugins/render/satellites/mex/astrolib.h
@@ -13,6 +13,8 @@
 
 #include "attlib.h"
 
+#undef sun
+
 double ddd (int d, int m, double s); // deg, min, sec -> decimal degrees
 void dms (double dd, int &d, int &m, double &s); // dec deg -> deg, min, sec
 double mjd (int day, int month, int year, double hour); // modified Julian date
