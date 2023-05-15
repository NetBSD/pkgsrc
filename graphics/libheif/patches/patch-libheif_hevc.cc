$NetBSD: patch-libheif_hevc.cc,v 1.1 2023/05/15 09:23:18 jperkin Exp $

Explicitly use std::pow.

--- libheif/hevc.cc.orig	2023-05-03 07:03:54.000000000 +0000
+++ libheif/hevc.cc
@@ -23,6 +23,7 @@
 
 #include <cmath>
 
+using std::pow;
 
 static double read_depth_rep_info_element(BitReader& reader)
 {
