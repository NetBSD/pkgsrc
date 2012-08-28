$NetBSD: patch-feature.h,v 1.1 2012/08/28 05:59:39 morr Exp $

--- src/feature.h.orig	2012-05-25 09:26:32.000000000 +0000
+++ src/feature.h
@@ -559,7 +559,7 @@
  *			(used only with NO_BUILTIN_TCAPS not defined).
  */
 #ifdef HAVE_TGETENT
-/* #define NO_BUILTIN_TCAPS */
+#define NO_BUILTIN_TCAPS
 #endif
 
 #if !defined(NO_BUILTIN_TCAPS) && !defined(FEAT_GUI_W16)
