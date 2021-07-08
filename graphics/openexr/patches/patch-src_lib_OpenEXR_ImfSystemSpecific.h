$NetBSD: patch-src_lib_OpenEXR_ImfSystemSpecific.h,v 1.1 2021/07/08 21:13:06 markd Exp $

Work around lack of posix_memalign() on (some?) Solaris, from PR 47867.

--- src/lib/OpenEXR/ImfSystemSpecific.h.orig	2019-09-18 01:02:06.000000000 +0000
+++ src/lib/OpenEXR/ImfSystemSpecific.h
@@ -59,6 +59,8 @@ EXRAllocAligned (size_t size, size_t ali
     return _aligned_malloc (size, alignment);
 #elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
     return _mm_malloc (size, alignment);
+#elif defined(__sun)
+    return memalign(alignment, size);
 #elif defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)
     void* ptr = 0;
     // With fortify_source on, just doing the (void) cast trick
