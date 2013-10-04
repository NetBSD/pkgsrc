$NetBSD: patch-libtest__lite.h,v 1.1 2013/10/04 07:03:37 fhajny Exp $

alloca.h is a linux-ism

--- libtest/lite.h.orig	2013-05-03 04:58:08.000000000 +0000
+++ libtest/lite.h
@@ -51,7 +51,7 @@
 # include <string.h>
 #endif
 
-#if defined(WIN32)
+#if defined(WIN32) || defined(__NetBSD__)
 # include <malloc.h>
 #else
 # include <alloca.h>
