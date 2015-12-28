$NetBSD: patch-src_StretcherProcess.cpp,v 1.1 2015/12/28 03:29:33 kamil Exp $

NetBSD ships with alloca() in <stdlib.h>

--- src/StretcherProcess.cpp.orig	2012-10-28 10:30:09.000000000 +0000
+++ src/StretcherProcess.cpp
@@ -34,7 +34,9 @@
 #include "base/Profiler.h"
 #include "system/VectorOps.h"
 
-#ifndef _WIN32
+#ifdef __NetBSD__
+#include <stdlib.h>
+#elif !defined(_WIN32)
 #include <alloca.h>
 #endif
 
@@ -1290,4 +1292,3 @@ RubberBandStretcher::Impl::retrieve(floa
 }
 
 }
-
