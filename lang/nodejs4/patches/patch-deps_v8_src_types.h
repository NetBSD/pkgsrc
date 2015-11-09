$NetBSD: patch-deps_v8_src_types.h,v 1.1 2015/11/09 20:21:51 fhajny Exp $

NetBSD 6 doesn't have nearbyint.

--- deps/v8/src/types.h.orig	2015-09-08 15:30:40.000000000 +0000
+++ deps/v8/src/types.h
@@ -10,6 +10,13 @@
 #include "src/handles.h"
 #include "src/ostreams.h"
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ - 0 < 699001700
+#define nearbyint rint
+#endif
+#endif
+
 namespace v8 {
 namespace internal {
 
