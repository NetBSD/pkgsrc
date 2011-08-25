$NetBSD: patch-src_rawspeed_RawSpeed_Common.h,v 1.2 2011/08/25 14:42:53 jakllsch Exp $

Move typedef to correct place.

--- src/external/rawspeed/RawSpeed/Common.h.orig	2011-08-24 09:20:29.000000000 +0000
+++ src/external/rawspeed/RawSpeed/Common.h
@@ -42,8 +42,8 @@ void* _aligned_malloc(size_t bytes, size
 #define _aligned_free(a) do { free(a); } while (0)
 #ifndef MIN
 #define MIN(a, b)  lmin(a,b)
-typedef unsigned long long uint64;
 #endif
+typedef unsigned long long uint64;
 #ifndef MAX
 #define MAX(a, b)  lmax(a,b)
 #endif
