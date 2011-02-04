$NetBSD: patch-pngconf.h,v 1.1 2011/02/04 23:35:29 adam Exp $

--- pngconf.h.orig	2011-02-04 23:31:35.000000000 +0000
+++ pngconf.h
@@ -287,7 +287,7 @@
  * PNG_EXPORT function for every compiler.
  */
 #ifndef PNG_FUNCTION
-#  ifdef __GNUC__
+#  if defined(__GNUC__) && !defined(__clang__)
 #     define PNG_FUNCTION(type, name, args, attributes)\
          attributes type name args
 #  else /* !GNUC */
@@ -347,7 +347,7 @@
    * functions in png.h will generate compiler warnings.  Added at libpng
    * version 1.2.41.
    */
-#  ifdef __GNUC__
+#  if defined(__GNUC__) && !defined(__clang__)
 #    ifndef PNG_USE_RESULT
 #      define PNG_USE_RESULT __attribute__((__warn_unused_result__))
 #    endif
