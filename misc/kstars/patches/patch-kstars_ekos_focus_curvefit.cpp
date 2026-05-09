$NetBSD: patch-kstars_ekos_focus_curvefit.cpp,v 1.1 2026/05/09 15:45:26 wiz Exp $

https://bugs.kde.org/show_bug.cgi?id=519958

kstars-3.8.1/kstars/ekos/focus/curvefit.cpp: In member function 'bool Ekos::CurveFitting::getGaussianParams(StarParams*)':
kstars-3.8.1/kstars/ekos/focus/curvefit.cpp:2593:9: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?
 2593 |     if (isnan(FWHM) || FWHM < 0.0)
      |         ^~~~~
      |         std::isnan

--- kstars/ekos/focus/curvefit.cpp.orig	2026-05-09 15:31:15.259844166 +0000
+++ kstars/ekos/focus/curvefit.cpp
@@ -2590,7 +2590,7 @@ bool CurveFitting::getGaussianParams(StarParams *starP
     double FWHMy = 2 * pow(2 * log(2) * sigmay2, 0.5);
     double FWHM  = (FWHMx + FWHMy) / 2.0;
 
-    if (isnan(FWHM) || FWHM < 0.0)
+    if (std::isnan(FWHM) || FWHM < 0.0)
     {
         qCDebug(KSTARS_EKOS_FOCUS) << QString("Error in CurveFitting::getGaussianParams FWHM=%1").arg(FWHM);
         return false;
