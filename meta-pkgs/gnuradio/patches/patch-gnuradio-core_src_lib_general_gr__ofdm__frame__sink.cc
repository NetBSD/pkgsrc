$NetBSD: patch-gnuradio-core_src_lib_general_gr__ofdm__frame__sink.cc,v 1.1 2013/02/26 19:25:02 jperkin Exp $

Avoid 'error: call of overloaded <x> is ambiguous' failures.

--- gnuradio-core/src/lib/general/gr_ofdm_frame_sink.cc.orig	2010-06-01 05:04:09.000000000 +0000
+++ gnuradio-core/src/lib/general/gr_ofdm_frame_sink.cc
@@ -281,7 +281,7 @@ gr_ofdm_frame_sink::set_sym_value_out(co
 
   d_sym_position  = sym_position;
   d_sym_value_out = sym_value_out;
-  d_nbits = (unsigned long)ceil(log10(d_sym_value_out.size()) / log10(2.0));
+  d_nbits = (unsigned long)ceil(log10((double)d_sym_value_out.size()) / log10((float)2.0));
 
   return true;
 }
