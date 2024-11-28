$NetBSD: patch-common_common.h,v 1.1 2024/11/28 09:35:34 nia Exp $

See the CMakeLists patch for how HAVE_ALLOCA_H gets defined.

--- common/common.h.orig	2024-11-28 09:30:21.789646942 +0000
+++ common/common.h
@@ -98,6 +98,10 @@
 #define X265_LL "%lld"
 #endif
 
+#if HAVE_ALLOCA_H
+#include <alloca.h>
+#endif
+
 #if _DEBUG && defined(_MSC_VER)
 #define DEBUG_BREAK() __debugbreak()
 #elif __APPLE_CC__
