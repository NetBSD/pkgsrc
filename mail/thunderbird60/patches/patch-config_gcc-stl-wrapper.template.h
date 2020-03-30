$NetBSD: patch-config_gcc-stl-wrapper.template.h,v 1.1 2020/03/30 19:46:01 joerg Exp $

--- config/gcc-stl-wrapper.template.h.orig	2019-10-31 12:34:19.000000000 +0000
+++ config/gcc-stl-wrapper.template.h
@@ -28,14 +28,14 @@
 #endif
 
 // Don't include mozalloc for cstdlib. See bug 1245076.
-#ifndef moz_dont_include_mozalloc_for_cstdlib
-#  define moz_dont_include_mozalloc_for_cstdlib
+#ifndef moz_dont_include_mozalloc_for_${HEADER}
+#  define moz_dont_include_mozalloc_for_${HEADER}
 #endif
 
 // Include mozalloc after the STL header and all other headers it includes
 // have been preprocessed.
 #if !defined(MOZ_INCLUDE_MOZALLOC_H) && \
-    !defined(moz_dont_include_mozalloc_for_${HEADER})
+    !defined(moz_dont_include_mozalloc_for_cstdlib)
 #  define MOZ_INCLUDE_MOZALLOC_H
 #  define MOZ_INCLUDE_MOZALLOC_H_FROM_${HEADER}
 #endif
@@ -64,4 +64,6 @@
 #  include "mozilla/throw_gcc.h"
 #endif
 
+#undef moz_dont_include_mzalloc_for_${HEADER}
+
 #endif  // if mozilla_${HEADER}_h
