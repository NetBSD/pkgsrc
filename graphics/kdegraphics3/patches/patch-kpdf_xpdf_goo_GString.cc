$NetBSD: patch-kpdf_xpdf_goo_GString.cc,v 1.1 2014/01/09 20:11:27 jperkin Exp $

Avoid ambiguous function call.

--- kpdf/xpdf/goo/GString.cc.orig	2007-05-14 07:39:30.000000000 +0000
+++ kpdf/xpdf/goo/GString.cc
@@ -528,7 +528,7 @@ void GString::formatDouble(double x, cha
   if ((neg = x < 0)) {
     x = -x;
   }
-  x = floor(x * pow(10, prec) + 0.5);
+  x = floor(x * pow(10.0, (double)prec) + 0.5);
   i = bufSize;
   started = !trim;
   for (j = 0; j < prec && i > 1; ++j) {
