$NetBSD: patch-deps_v8_src_types.h,v 1.2 2015/11/09 20:19:35 fhajny Exp $

NetBSD 6 doesn't have nearbyint.

--- deps/v8/src/types.h.orig	2015-10-29 12:22:04.000000000 +0000
+++ deps/v8/src/types.h
@@ -5,6 +5,13 @@
 #ifndef V8_TYPES_H_
 #define V8_TYPES_H_
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ - 0 < 699001700
+#define nearbyint rint
+#endif
+#endif
+
 #include "src/conversions.h"
 #include "src/handles.h"
 #include "src/objects.h"
