$NetBSD: patch-include-schily-mconfig.h,v 1.1 2011/08/04 11:40:50 joerg Exp $

--- include/schily/mconfig.h.orig	2011-08-03 11:32:36.000000000 +0000
+++ include/schily/mconfig.h
@@ -151,6 +151,11 @@ extern "C" {
 #endif
 #endif
 
+#ifdef __clang__
+/* Bad interactions with the compiler, so disable this crap... */
+#undef	HAVE_SCANSTACK
+#endif
+
 /*
  * Allow to overwrite the defines in the makefiles by calling
  *
