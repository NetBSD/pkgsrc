$NetBSD: patch-libtest_lite.h,v 1.3.30.1 2017/10/15 11:26:40 spz Exp $

NetBSD doesn't have alloca.h.

--- libtest/lite.h.orig	2014-02-09 11:52:42.000000000 +0000
+++ libtest/lite.h
@@ -53,7 +53,7 @@
 
 #if defined(WIN32)
 # include <malloc.h>
-#else
+#elif !defined(__NetBSD__) && !defined(__FreeBSD__)
 # include <alloca.h>
 #endif
 
