$NetBSD: patch-src_effects_nyquist_Nyquist.cpp,v 1.2 2018/03/31 20:08:12 joerg Exp $

GCC 6 wants std namespace, found via <cmath>.

--- src/effects/nyquist/Nyquist.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/effects/nyquist/Nyquist.cpp
@@ -67,6 +67,7 @@ effects from this one class.
 #include <ostream>
 #include <sstream>
 #include <float.h>
+#include <cmath>
 
 #include "../../Experimental.h"
 
@@ -666,7 +667,7 @@ bool NyquistEffect::Process()
                // with very small values, bandwidth calculation may be inf.
                // (Observed on Linux)
                double bw = log(mF1 / mF0) / log(2.0);
-               if (!isinf(bw)) {
+               if (!std::isinf(bw)) {
                   bandwidth.Printf(wxT("(float %s)"), Internat::ToString(bw).c_str());
                }
             }
