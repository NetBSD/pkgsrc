$NetBSD: patch-ext_core_src_util_rational.cpp,v 1.1 2025/02/04 08:31:24 wiz Exp $

Include header for std::numeric_limits.

--- ext/core/src/util/rational.cpp.orig	2025-02-04 08:26:54.500208360 +0000
+++ ext/core/src/util/rational.cpp
@@ -24,6 +24,8 @@
 
 #include "util/stringutils.h"
 
+#include <limits>
+
 namespace olive::core {
 
 const rational rational::NaN = rational(0, 0);
