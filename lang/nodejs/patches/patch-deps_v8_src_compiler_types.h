$NetBSD: patch-deps_v8_src_compiler_types.h,v 1.2 2017/06/05 21:14:04 fhajny Exp $

NetBSD 6 doesn't have nearbyint/nearbyintf.

--- deps/v8/src/compiler/types.h.orig	2017-05-30 17:31:37.000000000 +0000
+++ deps/v8/src/compiler/types.h
@@ -5,6 +5,14 @@
 #ifndef V8_COMPILER_TYPES_H_
 #define V8_COMPILER_TYPES_H_
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ - 0 < 699001700
+#define nearbyint rint
+#define nearbyintf rintf
+#endif
+#endif
+
 #include "src/base/compiler-specific.h"
 #include "src/conversions.h"
 #include "src/globals.h"
