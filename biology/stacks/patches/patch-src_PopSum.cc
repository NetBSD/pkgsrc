$NetBSD: patch-src_PopSum.cc,v 1.1 2022/04/25 14:34:06 tnn Exp $

avoid ambiguous math functions

--- src/PopSum.cc.orig	2021-10-21 14:47:59.000000000 +0000
+++ src/PopSum.cc
@@ -20,6 +20,8 @@
 
 #include "PopSum.h"
 
+using std::log;
+
 LocPopSum::LocPopSum(size_t cloc_len, const MetaPopInfo& mpopi)
 {
     this->_pop_cnt  = mpopi.pops().size();
