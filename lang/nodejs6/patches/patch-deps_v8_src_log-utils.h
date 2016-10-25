$NetBSD: patch-deps_v8_src_log-utils.h,v 1.1 2016/10/25 19:54:00 fhajny Exp $

Need stdarg.h for va_list.

--- deps/v8/src/log-utils.h.orig	2015-10-29 12:22:04.000000000 +0000
+++ deps/v8/src/log-utils.h
@@ -9,6 +9,10 @@
 #include "src/base/platform/mutex.h"
 #include "src/flags.h"
 
+#if defined(__NetBSD__)
+#include <stdarg.h>
+#endif
+
 namespace v8 {
 namespace internal {
 
