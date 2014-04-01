$NetBSD: patch-libtest_lite.h,v 1.2 2014/04/01 13:51:56 fhajny Exp $

NetBSD doesn't have alloca.h.
--- libtest/lite.h.orig	2014-02-09 11:52:42.000000000 +0000
+++ libtest/lite.h
@@ -53,7 +53,7 @@
 
 #if defined(WIN32)
 # include <malloc.h>
-#else
+#elif !defined(__NetBSD__)
 # include <alloca.h>
 #endif
 
