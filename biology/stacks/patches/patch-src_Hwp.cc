$NetBSD: patch-src_Hwp.cc,v 1.1 2022/04/25 14:34:06 tnn Exp $

avoid ambiguous math functions

--- src/Hwp.cc.orig	2020-06-24 17:47:53.000000000 +0000
+++ src/Hwp.cc
@@ -20,6 +20,9 @@
 
 #include "Hwp.h"
 
+using std::log;
+using std::pow;
+
 double
 GuoThompson_Hwp::exec_locus(int start, int end, const Datum **d, size_t hap_cnt)
 {
