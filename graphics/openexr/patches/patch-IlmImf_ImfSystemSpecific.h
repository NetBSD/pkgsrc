$NetBSD: patch-IlmImf_ImfSystemSpecific.h,v 1.2 2018/10/02 12:05:35 adam Exp $

Work around lack of posix_memalign() on (some?) Solaris, from PR 47867.

--- IlmImf/ImfSystemSpecific.h.orig	2018-08-10 01:34:58.000000000 +0000
+++ IlmImf/ImfSystemSpecific.h
@@ -65,6 +65,8 @@ static void* EXRAllocAligned(size_t size
     // GNUC is used for things like mingw to (cross-)compile for windows
 #ifdef _WIN32
     return _aligned_malloc(size, alignment);
+#elif defined(_sun)
+    return memalign(alignment, size);
 #else
     void* ptr = 0;
     posix_memalign(&ptr, alignment, size);
