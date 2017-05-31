$NetBSD: patch-snappy.cc,v 1.1 2017/05/31 08:52:41 jperkin Exp $

Fix SSE2 include, patch from upstream.

--- snappy.cc.orig	1980-01-01 08:00:00.000000000 +0000
+++ snappy.cc
@@ -30,7 +30,7 @@
 #include "snappy-internal.h"
 #include "snappy-sinksource.h"
 
-#if defined(__x86_64__) || defined(_M_X64)
+#ifdef __SSE2__
 #include <emmintrin.h>
 #endif
 #include <stdio.h>
