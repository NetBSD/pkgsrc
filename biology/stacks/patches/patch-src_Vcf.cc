$NetBSD: patch-src_Vcf.cc,v 1.1 2022/04/25 14:34:06 tnn Exp $

avoid ambiguous math functions

--- src/Vcf.cc.orig	2021-06-28 20:21:30.000000000 +0000
+++ src/Vcf.cc
@@ -22,6 +22,8 @@
 
 #include "Vcf.h"
 
+using std::log;
+
 const VcfMeta VcfMeta::predefs::info_AD ("INFO","<ID=AD,Number=R,Type=Integer,Description=\"Total Depth for Each Allele\">");
 const VcfMeta VcfMeta::predefs::info_AF ("INFO","<ID=AF,Number=A,Type=Float,Description=\"Allele Frequency\">");
 const VcfMeta VcfMeta::predefs::info_DP ("INFO","<ID=DP,Number=1,Type=Integer,Description=\"Total Depth\">");
