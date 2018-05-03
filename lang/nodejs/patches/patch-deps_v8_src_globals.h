$NetBSD: patch-deps_v8_src_globals.h,v 1.2 2018/05/03 21:19:16 fhajny Exp $

stdarg.h needed for va_list on at least NetBSD.

--- deps/v8/src/globals.h.orig	2018-04-24 14:41:26.000000000 +0000
+++ deps/v8/src/globals.h
@@ -7,6 +7,7 @@
 
 #include <stddef.h>
 #include <stdint.h>
+#include <stdarg.h>
 
 #include <limits>
 #include <ostream>
