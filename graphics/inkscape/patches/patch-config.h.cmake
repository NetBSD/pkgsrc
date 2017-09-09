$NetBSD: patch-config.h.cmake,v 1.1 2017/09/09 21:48:56 prlw1 Exp $

Support poppler 0.58
https://gitlab.com/inkscape/inkscape/commit/9418824967eb4c53371ef8588243fed4cab496e0

--- config.h.cmake.orig	2017-02-13 23:46:57.000000000 +0000
+++ config.h.cmake
@@ -149,6 +149,9 @@
 /* Use color space API from Poppler >= 0.29.0 */
 #cmakedefine POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API 1
 
+/* Use object API from Poppler >= 0.58.0 */
+#cmakedefine POPPLER_NEW_OBJECT_API 1
+
 /* Define to 1 if you have the `pow' function. */
 #cmakedefine HAVE_POW 1
 
