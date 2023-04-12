$NetBSD: patch-libheif_heif__hevc.cc,v 1.3 2023/04/12 09:35:29 jperkin Exp $

Avoid ambiguous function call.

--- libheif/heif_hevc.cc.orig	2022-11-15 13:24:59.000000000 +0000
+++ libheif/heif_hevc.cc
@@ -24,6 +24,7 @@
 #include <cmath>
 
 using namespace heif;
+using std::pow;
 
 
 static double read_depth_rep_info_element(BitReader& reader)
