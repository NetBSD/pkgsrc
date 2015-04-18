$NetBSD: patch-src_base_atomicops-internals-arm-v6plus.h,v 1.1.2.2 2015/04/18 22:02:11 tron Exp $

--- src/base/atomicops-internals-arm-v6plus.h.orig	2014-12-06 22:51:40.000000000 +0000
+++ src/base/atomicops-internals-arm-v6plus.h
@@ -50,7 +50,7 @@
 # define BASE_ATOMICOPS_HAS_LDREXD_AND_STREXD
 #endif
 
-typedef int32_t Atomic32;
+typedef intptr_t Atomic32;
 
 namespace base {
 namespace subtle {
