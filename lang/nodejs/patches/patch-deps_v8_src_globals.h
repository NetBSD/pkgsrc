$NetBSD: patch-deps_v8_src_globals.h,v 1.1 2017/06/05 21:14:04 fhajny Exp $

stdarg.h needed for va_list on at least NetBSD.

--- deps/v8/src/globals.h.orig	2017-05-30 17:31:38.000000000 +0000
+++ deps/v8/src/globals.h
@@ -7,6 +7,7 @@
 
 #include <stddef.h>
 #include <stdint.h>
+#include <stdarg.h>
 
 #include <ostream>
 
