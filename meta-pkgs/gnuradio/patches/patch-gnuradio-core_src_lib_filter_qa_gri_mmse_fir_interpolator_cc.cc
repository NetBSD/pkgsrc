$NetBSD: patch-gnuradio-core_src_lib_filter_qa_gri_mmse_fir_interpolator_cc.cc,v 1.1 2012/11/23 20:46:41 markd Exp $

include <stdint.h> for intptr_t and gcc4.7

--- gnuradio-core/src/lib/filter/qa_gri_mmse_fir_interpolator_cc.cc.orig	2010-06-01 05:04:09.000000000 +0000
+++ gnuradio-core/src/lib/filter/qa_gri_mmse_fir_interpolator_cc.cc
@@ -26,6 +26,7 @@
 #include <stdio.h>
 #include <cmath>
 #include <stdexcept>
+#include <stdint.h>
 
 #define	NELEM(x) (sizeof (x) / sizeof (x[0]))
 
