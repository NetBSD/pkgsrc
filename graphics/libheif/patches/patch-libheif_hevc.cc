$NetBSD: patch-libheif_hevc.cc,v 1.2 2023/05/16 08:56:02 wiz Exp $

Explicitly use std::pow.
https://github.com/strukturag/libheif/pull/866

--- libheif/hevc.cc.orig	2023-05-03 07:03:54.000000000 +0000
+++ libheif/hevc.cc
@@ -23,6 +23,7 @@
 
 #include <cmath>
 
+using std::pow;
 
 static double read_depth_rep_info_element(BitReader& reader)
 {
