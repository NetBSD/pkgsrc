$NetBSD: patch-lib_framework_string__ext.h,v 1.1 2020/01/27 19:35:54 triaxx Exp $

Add header for varargs.

--- lib/framework/string_ext.h.orig	2019-08-31 18:17:22.000000000 +0000
+++ lib/framework/string_ext.h
@@ -32,6 +32,7 @@
 
 #include <string>
 #include <utility>
+#include <stdarg.h>
 
 /*!
  * On MSVC, in order to squelch tons of 'memory leaks' we set the allocator
