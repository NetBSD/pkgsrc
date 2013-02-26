$NetBSD: patch-gnuradio-core_src_lib_general_gr__firdes.cc,v 1.1 2013/02/26 19:25:02 jperkin Exp $

Avoid 'error: call of overloaded <x> is ambiguous' failures.

--- gnuradio-core/src/lib/general/gr_firdes.cc.orig	2010-06-02 00:57:52.000000000 +0000
+++ gnuradio-core/src/lib/general/gr_firdes.cc
@@ -574,7 +574,7 @@ gr_firdes::gaussian (double gain,
   vector<float> taps(ntaps);
   double scale = 0;
   double dt = 1.0/spb;
-  double s = 1.0/(sqrt(log(2)) / (2*M_PI*bt));
+  double s = 1.0/(sqrt(log((float)2)) / (2*M_PI*bt));
   double t0 = -0.5 * ntaps;
   double ts;
   for(int i=0;i<ntaps;i++)
