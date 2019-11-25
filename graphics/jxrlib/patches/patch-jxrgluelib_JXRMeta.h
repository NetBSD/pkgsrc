$NetBSD: patch-jxrgluelib_JXRMeta.h,v 1.1 2019/11/25 21:07:19 nros Exp $
* Fix warning
--- jxrgluelib/JXRMeta.h.orig	2019-11-16 11:24:33.138807563 +0000
+++ jxrgluelib/JXRMeta.h
@@ -34,7 +34,7 @@
 
 #ifndef UNREFERENCED_PARAMETER
 #define UNREFERENCED_PARAMETER(P) { (P) = (P); }
-#endif UNREFERENCED_PARAMETER
+#endif
 
 //================================================================
 // Container
