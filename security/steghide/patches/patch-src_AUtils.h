$NetBSD: patch-src_AUtils.h,v 1.1 2022/04/25 15:01:53 tnn Exp $

avoid ambiguous math functions

--- src/AUtils.h.orig	2003-10-05 10:17:50.000000000 +0000
+++ src/AUtils.h
@@ -24,7 +24,7 @@
 #include <cmath>
 #ifndef log2
 	// this is in an #ifndef because some cmath implementations #define log2 and some not
-#	define log2(x) (log(x) / log(2.0))
+#	define log2(x) (log((double)(x)) / log(2.0))
 #endif
 
 /**
