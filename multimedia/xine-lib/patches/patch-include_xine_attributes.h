$NetBSD: patch-include_xine_attributes.h,v 1.1 2016/06/19 23:05:17 joerg Exp $

Protected symbols must only be referenced as such in the defining DSO.
xine is generally not prepared for that, so just use explicit default
visibility.

--- include/xine/attributes.h.orig	2016-06-19 19:53:49.487665526 +0000
+++ include/xine/attributes.h
@@ -59,9 +59,7 @@
 #endif
 
 /* Export protected only for libxine functions */
-#if defined(XINE_LIBRARY_COMPILE) && defined(SUPPORT_ATTRIBUTE_VISIBILITY_PROTECTED)
-# define XINE_PROTECTED __attribute__((__visibility__("protected")))
-#elif defined(XINE_LIBRARY_COMPILE) && defined(SUPPORT_ATTRIBUTE_VISIBILITY_DEFAULT)
+#if defined(XINE_LIBRARY_COMPILE) && defined(SUPPORT_ATTRIBUTE_VISIBILITY_DEFAULT)
 # define XINE_PROTECTED __attribute__((__visibility__("default")))
 #else
 # define XINE_PROTECTED
