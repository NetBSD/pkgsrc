$NetBSD: patch-gnuradio-core_src_lib_filter_gri__fft__filter__fff__generic.cc,v 1.1 2013/02/26 19:25:02 jperkin Exp $

Avoid 'error: call of overloaded <x> is ambiguous' failures.

--- gnuradio-core/src/lib/filter/gri_fft_filter_fff_generic.cc.orig	2010-06-01 05:04:08.000000000 +0000
+++ gnuradio-core/src/lib/filter/gri_fft_filter_fff_generic.cc
@@ -86,7 +86,7 @@ gri_fft_filter_fff_generic::compute_size
 {
   int old_fftsize = d_fftsize;
   d_ntaps = ntaps;
-  d_fftsize = (int) (2 * pow(2.0, ceil(log(ntaps) / log(2))));
+  d_fftsize = (int) (2 * pow(2.0, ceil(log((float)ntaps) / log((float)2))));
   d_nsamples = d_fftsize - d_ntaps + 1;
 
   if (0)
