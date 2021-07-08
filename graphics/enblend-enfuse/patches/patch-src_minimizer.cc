$NetBSD: patch-src_minimizer.cc,v 1.1 2021/07/08 21:30:45 markd Exp $

build with gcc11

--- src/minimizer.cc.orig	2016-03-20 14:44:49.000000000 +0000
+++ src/minimizer.cc
@@ -20,6 +20,7 @@
 
 #include <gsl/gsl_errno.h>
 
+#include <limits>
 #include "minimizer.h"
 
 
