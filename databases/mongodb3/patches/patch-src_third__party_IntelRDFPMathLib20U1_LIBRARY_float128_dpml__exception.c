$NetBSD: patch-src_third__party_IntelRDFPMathLib20U1_LIBRARY_float128_dpml__exception.c,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/third_party/IntelRDFPMathLib20U1/LIBRARY/float128/dpml_exception.c.orig	2017-04-20 21:43:42.000000000 +0000
+++ src/third_party/IntelRDFPMathLib20U1/LIBRARY/float128/dpml_exception.c
@@ -131,6 +131,7 @@
 #if !defined(DPML_SIGNAL) && !defined(MINIMAL_SILENT_MODE_EXCEPTION_HANDLER) && \
     !defined(wnt)
 
+#   include <sys/types.h>
 #   include <sys/signal.h>
 #   define DPML_SIGNAL(p)	 raise(SIGFPE)
 
