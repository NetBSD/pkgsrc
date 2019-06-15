$NetBSD: patch-jack_types.h,v 1.1 2019/06/15 08:21:33 adam Exp $

size_t is more suitable for jack_shmsize_t.

--- jack/types.h.orig	2016-09-14 22:01:23.000000000 +0000
+++ jack/types.h
@@ -26,7 +26,7 @@
 
 typedef uint64_t jack_uuid_t;
 
-typedef int32_t jack_shmsize_t;
+typedef size_t jack_shmsize_t;
 
 #ifndef POST_PACKED_STRUCTURE
 #ifdef __GNUC__
