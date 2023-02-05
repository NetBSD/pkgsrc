$NetBSD: patch-config_gcc-stl-wrapper.template.h,v 1.3 2023/02/05 09:05:29 he Exp $

--- config/gcc-stl-wrapper.template.h.orig	2020-08-28 21:32:29.000000000 +0000
+++ config/gcc-stl-wrapper.template.h
@@ -32,8 +32,8 @@
 // limits) and bug 1694575 (iosfwd).
 // Please be careful when adding more exceptions, especially regarding
 // the header not directly or indirectly including <new>.
-#ifndef moz_dont_include_mozalloc_for_cstdlib
-#  define moz_dont_include_mozalloc_for_cstdlib
+#ifndef moz_dont_include_mozalloc_for_${HEADER}
+#  define moz_dont_include_mozalloc_for_${HEADER}
 #endif
 
 #ifndef moz_dont_include_mozalloc_for_cmath
@@ -55,7 +55,7 @@
 // Include mozalloc after the STL header and all other headers it includes
 // have been preprocessed.
 #if !defined(MOZ_INCLUDE_MOZALLOC_H) && \
-    !defined(moz_dont_include_mozalloc_for_${HEADER})
+    !defined(moz_dont_include_mozalloc_for_cstdlib)
 #  define MOZ_INCLUDE_MOZALLOC_H
 #  define MOZ_INCLUDE_MOZALLOC_H_FROM_${HEADER}
 #endif
@@ -84,4 +84,6 @@
 #  include "mozilla/throw_gcc.h"
 #endif
 
+#undef moz_dont_include_mzalloc_for_${HEADER}
+
 #endif  // if mozilla_${HEADER}_h
