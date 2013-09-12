$NetBSD: patch-libtest_lite.h,v 1.1 2013/09/12 14:20:56 fhajny Exp $

NetBSD doesn't have alloca.h.
--- libtest/lite.h.orig	2013-04-03 04:22:00.000000000 +0000
+++ libtest/lite.h
@@ -53,7 +53,7 @@
 
 #if defined(_WIN32)
 # include <malloc.h>
-#else
+#elif !defined(__NetBSD__)
 # include <alloca.h>
 #endif
 
