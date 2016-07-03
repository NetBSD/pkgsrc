$NetBSD: patch-feature.h,v 1.2 2016/07/03 13:20:59 morr Exp $

--- src/feature.h.orig	2012-05-25 09:26:32.000000000 +0000
+++ src/feature.h
@@ -548,7 +548,7 @@
  *			(used only with NO_BUILTIN_TCAPS not defined).
  */
 #ifdef HAVE_TGETENT
-/* #define NO_BUILTIN_TCAPS */
+#define NO_BUILTIN_TCAPS
 #endif
 
 #if !defined(NO_BUILTIN_TCAPS)
