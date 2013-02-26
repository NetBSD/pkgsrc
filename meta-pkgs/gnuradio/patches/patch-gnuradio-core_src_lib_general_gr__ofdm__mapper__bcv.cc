$NetBSD: patch-gnuradio-core_src_lib_general_gr__ofdm__mapper__bcv.cc,v 1.1 2013/02/26 19:25:02 jperkin Exp $

Avoid 'error: call of overloaded <x> is ambiguous' failures.

--- gnuradio-core/src/lib/general/gr_ofdm_mapper_bcv.cc.orig	2010-06-01 05:04:09.000000000 +0000
+++ gnuradio-core/src/lib/general/gr_ofdm_mapper_bcv.cc
@@ -113,7 +113,7 @@ gr_ofdm_mapper_bcv::gr_ofdm_mapper_bcv (
     throw std::invalid_argument("gr_ofdm_mapper_bcv: subcarriers allocated exceeds size of occupied carriers");
   }
   
-  d_nbits = (unsigned long)ceil(log10(d_constellation.size()) / log10(2.0));
+  d_nbits = (unsigned long)ceil(log10((double)d_constellation.size()) / log10((float)2.0));
 }
 
 gr_ofdm_mapper_bcv::~gr_ofdm_mapper_bcv(void)
