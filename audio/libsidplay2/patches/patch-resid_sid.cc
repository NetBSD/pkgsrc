$NetBSD: patch-resid_sid.cc,v 1.1 2014/02/07 14:16:34 wiedi Exp $

fix log(int) is ambiguous on SunOS
--- resid/sid.cc.orig	2004-06-14 20:08:23.000000000 +0000
+++ resid/sid.cc
@@ -552,7 +552,7 @@ bool SID::set_sampling_parameters(double
   // sample_offset a whole multiple of the filter table resolution.
   int res = method == SAMPLE_RESAMPLE_INTERPOLATE ?
     FIR_RES_INTERPOLATE : FIR_RES_FAST;
-  int n = (int)ceil(log(res/f_cycles_per_sample)/log(2));
+  int n = (int)ceil(log((double)res/f_cycles_per_sample)/log((double)2));
   fir_RES = 1 << n;
 
   // Allocate memory for FIR tables.
