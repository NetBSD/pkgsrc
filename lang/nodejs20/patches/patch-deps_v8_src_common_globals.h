$NetBSD: patch-deps_v8_src_common_globals.h,v 1.1 2023/11/02 13:16:54 adam Exp $

stdarg.h is needed for va_list on at least NetBSD.

--- deps/v8/src/common/globals.h.orig	2019-11-19 08:29:07.000000000 +0000
+++ deps/v8/src/common/globals.h
@@ -7,6 +7,7 @@
 
 #include <stddef.h>
 #include <stdint.h>
+#include <stdarg.h>
 
 #include <limits>
 #include <ostream>
