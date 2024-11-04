$NetBSD: patch-src_hrtf_portable__endian.h,v 1.4 2024/11/04 09:18:32 jperkin Exp $

https://github.com/hoene/libmysofa/pull/229

--- src/hrtf/portable_endian.h.orig	2024-11-04 09:08:56.159546686 +0000
+++ src/hrtf/portable_endian.h
@@ -13,7 +13,7 @@
 
 #endif
 
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__illumos__)
 
 #	include <endian.h>
 
