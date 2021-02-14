$NetBSD: patch-ext_libarchive__internal.h,v 1.1 2021/02/14 15:23:57 taca Exp $

* Fix for Ruby 3.

--- ext/libarchive_internal.h.orig	2021-01-11 05:55:51.159908652 +0000
+++ ext/libarchive_internal.h
@@ -28,7 +28,10 @@
 #include <archive_entry.h>
 
 #include <ruby.h>
+#include <ruby/version.h>
+#if RUBY_API_VERSION_MAJOR < 3
 #include <rubysig.h>
+#endif
 
 #ifdef _WIN32
 #include "libarchive_win32.h"
