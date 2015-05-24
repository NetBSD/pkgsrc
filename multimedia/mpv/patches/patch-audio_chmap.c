$NetBSD: patch-audio_chmap.c,v 1.1 2015/05/24 08:03:05 adam Exp $

Avoid conflict with system popcount64().

--- audio/chmap.c.orig	2015-05-24 07:59:39.000000000 +0000
+++ audio/chmap.c
@@ -395,7 +395,7 @@ void mp_chmap_get_reorder(int src[MP_NUM
         assert(src[n] < 0 || (to->speaker[n] == from->speaker[src[n]]));
 }
 
-static int popcount64(uint64_t bits)
+static int mypopcount64(uint64_t bits)
 {
     int r = 0;
     for (int n = 0; n < 64; n++)
@@ -408,7 +408,7 @@ int mp_chmap_diffn(const struct mp_chmap
 {
     uint64_t a_mask = mp_chmap_to_lavc_unchecked(a);
     uint64_t b_mask = mp_chmap_to_lavc_unchecked(b);
-    return popcount64((a_mask ^ b_mask) & a_mask);
+    return mypopcount64((a_mask ^ b_mask) & a_mask);
 }
 
 // Returns something like "fl-fr-fc". If there's a standard layout in lavc
