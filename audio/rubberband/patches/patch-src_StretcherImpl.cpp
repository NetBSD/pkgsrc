$NetBSD: patch-src_StretcherImpl.cpp,v 1.1 2015/12/28 03:29:33 kamil Exp $

NetBSD ships with alloca() in <stdlib.h>

--- src/StretcherImpl.cpp.orig	2012-10-28 10:30:09.000000000 +0000
+++ src/StretcherImpl.cpp
@@ -37,7 +37,9 @@
 
 #include "base/Profiler.h"
 
-#ifndef _WIN32
+#ifdef __NetBSD__
+#include <stdlib.h>
+#elif !defined(_WIN32)
 #include <alloca.h>
 #endif
 
@@ -1340,4 +1342,3 @@ RubberBandStretcher::Impl::process(const
 
 
 }
-
