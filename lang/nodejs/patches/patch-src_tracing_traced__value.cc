$NetBSD: patch-src_tracing_traced__value.cc,v 1.2 2025/09/02 07:37:58 wiz Exp $

Fix build on NetBSD.
https://github.com/nodejs/node/issues/59714

--- src/tracing/traced_value.cc.orig	2025-09-02 07:14:52.741019499 +0000
+++ src/tracing/traced_value.cc
@@ -9,6 +9,7 @@
 #include <unicode/utypes.h>
 #endif
 
+#include <cmath>
 #include <sstream>
 
 #include "node_metadata.h"
