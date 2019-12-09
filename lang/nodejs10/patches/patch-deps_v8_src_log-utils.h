$NetBSD: patch-deps_v8_src_log-utils.h,v 1.1 2019/12/09 20:05:40 adam Exp $

Need stdarg.h for va_list.

--- deps/v8/src/log-utils.h.orig	2018-04-24 14:41:27.000000000 +0000
+++ deps/v8/src/log-utils.h
@@ -15,6 +15,10 @@
 #include "src/flags.h"
 #include "src/ostreams.h"
 
+#if defined(__NetBSD__)
+#include <stdarg.h>
+#endif
+
 namespace v8 {
 namespace internal {
 
