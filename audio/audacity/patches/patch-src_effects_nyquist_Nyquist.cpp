$NetBSD: patch-src_effects_nyquist_Nyquist.cpp,v 1.1 2018/02/08 07:28:58 mrg Exp $

GCC 6 wants std namespace, found via <cmath>.

--- src/effects/nyquist/Nyquist.cpp.orig	2018-02-07 10:04:58.228319803 +0000
+++ src/effects/nyquist/Nyquist.cpp	2018-02-07 10:14:46.346004080 +0000
@@ -666,7 +666,7 @@
                // with very small values, bandwidth calculation may be inf.
                // (Observed on Linux)
                double bw = log(mF1 / mF0) / log(2.0);
-               if (!isinf(bw)) {
+               if (!std::isinf(bw)) {
                   bandwidth.Printf(wxT("(float %s)"), Internat::ToString(bw).c_str());
                }
             }
