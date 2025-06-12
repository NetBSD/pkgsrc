$NetBSD: patch-Source_Core_Common_MathUtil.h,v 1.1 2025/06/12 07:37:34 wiz Exp $

Add missing include for numeric_limits.

--- Source/Core/Common/MathUtil.h.orig	2025-06-12 07:32:24.866763473 +0000
+++ Source/Core/Common/MathUtil.h
@@ -6,6 +6,7 @@
 
 #include <algorithm>
 #include <cstdlib>
+#include <limits>
 #include <vector>
 
 #include "Common/CommonTypes.h"
