$NetBSD: patch-config_gcc-stl-wrapper.template.h,v 1.6 2026/01/22 19:41:09 ryoon Exp $

--- config/gcc-stl-wrapper.template.h.orig	2026-01-08 21:44:55.000000000 +0000
+++ config/gcc-stl-wrapper.template.h
@@ -30,8 +30,8 @@
 // limits) and bug 1694575 (iosfwd).
 // Please be careful when adding more exceptions, especially regarding
 // the header not directly or indirectly including <new>.
-#ifndef moz_dont_include_mozalloc_for_cstdlib
-#  define moz_dont_include_mozalloc_for_cstdlib
+#ifndef moz_dont_include_mozalloc_for_${HEADER}
+#  define moz_dont_include_mozalloc_for_${HEADER}
 #endif
 
 #ifndef moz_dont_include_mozalloc_for_cmath
@@ -53,7 +53,7 @@
 // Include mozalloc after the STL header and all other headers it includes
 // have been preprocessed.
 #if !defined(MOZ_INCLUDE_MOZALLOC_H) && \
-    !defined(moz_dont_include_mozalloc_for_${HEADER})
+    !defined(moz_dont_include_mozalloc_for_cstdlib)
 #  define MOZ_INCLUDE_MOZALLOC_H
 #  define MOZ_INCLUDE_MOZALLOC_H_FROM_${HEADER}
 #endif
@@ -81,5 +81,7 @@
 #ifndef mozilla_throw_gcc_h
 #  include "mozilla/throw_gcc.h"
 #endif
+
+#undef moz_dont_include_mzalloc_for_${HEADER}
 
 #endif  // if mozilla_${HEADER}_h
