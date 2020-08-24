$NetBSD: patch-librhash_util.h,v 1.1 2020/08/24 12:58:52 schmonz Exp $

Avoid choosing aligned_alloc() when it's not present, such as CentOS 6
with lang/gcc7.

--- librhash/util.h.orig	2020-07-14 19:35:11.000000000 +0000
+++ librhash/util.h
@@ -39,7 +39,7 @@ extern "C" {
 # define rhash_aligned_alloc(alignment, size) _aligned_malloc((size), (alignment))
 # define rhash_aligned_free(ptr) _aligned_free(ptr)
 
-#elif (__STDC_VERSION__ >= 201112L || defined(_ISOC11_SOURCE)) && !defined(__APPLE__)
+#elif (__STDC_VERSION__ >= 201112L || defined(_ISOC11_SOURCE)) && !defined(__APPLE__) && !defined(NOPE_DOES_NOT_HAS_STDC_ALIGNED_ALLOC)
 
 # define HAS_STDC_ALIGNED_ALLOC
 # include <stdlib.h>
