$NetBSD: patch-src_third__party_IntelRDFPMathLib20U1_LIBRARY_float128_dpml__exception.c,v 1.2 2026/01/02 13:09:26 ryoon Exp $

--- src/third_party/IntelRDFPMathLib20U1/LIBRARY/float128/dpml_exception.c.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/IntelRDFPMathLib20U1/LIBRARY/float128/dpml_exception.c
@@ -131,7 +131,8 @@
 #if !defined(DPML_SIGNAL) && !defined(MINIMAL_SILENT_MODE_EXCEPTION_HANDLER) && \
     !defined(wnt)
 
-#   include <sys/signal.h>
+#   include <sys/types.h>
+#   include <signal.h>
 #   define DPML_SIGNAL(p)	 raise(SIGFPE)
 
 #else
