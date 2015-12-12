$NetBSD: patch-gsl.cc,v 1.1 2015/12/12 20:44:13 markd Exp $

Support GSL 2.0 (upstream commit 71ff9e769ba5d9995b367201f0d41b7a8dedab9d)

--- gsl.cc.orig	2015-11-29 11:11:59.000000000 +0000
+++ gsl.cc
@@ -27,6 +27,7 @@
 #include <gsl/gsl_rng.h>
 #include <gsl/gsl_randist.h>
 #include <gsl/gsl_cdf.h>
+#include <gsl/gsl_version.h>
 
 #include "opsymbols.h"
 
@@ -1089,7 +1090,11 @@ void gen_rungsl_venv(venv &ve)
   addGSLDOUBLE2Func<gsl_sf_ellint_E>(SYM(E));
   addGSLDOUBLE3Func<gsl_sf_ellint_P>(SYM(P),SYM(phi),SYM(k),SYM(n));
+#if GSL_MAJOR_VERSION >= 2
+  addGSLDOUBLE2Func<gsl_sf_ellint_D>(SYM(D),SYM(phi),SYM(k));
+#else  
   addGSLDOUBLE3Func<gsl_sf_ellint_D>(SYM(D),SYM(phi),SYM(k),SYM(n));
+#endif
   addGSLDOUBLE2Func<gsl_sf_ellint_RC>(SYM(RC),SYM(x),SYM(y));
   addGSLDOUBLE3Func<gsl_sf_ellint_RD>(SYM(RD),SYM(x),SYM(y),SYM(z));
   addGSLDOUBLE3Func<gsl_sf_ellint_RF>(SYM(RF),SYM(x),SYM(y),SYM(z));
   addGSLDOUBLE4Func<gsl_sf_ellint_RJ>(SYM(RJ),SYM(x),SYM(y),SYM(z),SYM(p));
