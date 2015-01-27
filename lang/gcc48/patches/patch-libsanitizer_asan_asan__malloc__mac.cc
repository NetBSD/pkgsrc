$NetBSD: patch-libsanitizer_asan_asan__malloc__mac.cc,v 1.1 2015/01/27 04:46:06 dbj Exp $

--- libsanitizer/asan/asan_malloc_mac.cc.orig	2013-01-23 11:41:33.000000000 +0000
+++ libsanitizer/asan/asan_malloc_mac.cc
@@ -13,7 +13,6 @@
 #ifdef __APPLE__
 
 #include <AvailabilityMacros.h>
-#include <CoreFoundation/CFBase.h>
 #include <dlfcn.h>
 #include <malloc/malloc.h>
 
