$NetBSD: patch-IlmImf_ImfSystemSpecific.h,v 1.1 2013/07/04 06:25:23 dholland Exp $

Work around lack of posix_memalign() on (some?) Solaris, from PR 47867.

--- IlmImf/ImfSystemSpecific.h~	2013-04-09 17:08:02.000000000 +0000
+++ IlmImf/ImfSystemSpecific.h
@@ -60,9 +60,13 @@ static bool GLOBAL_SYSTEM_LITTLE_ENDIAN 
 
 static void* EXRAllocAligned(size_t size, size_t alignment)
 {
+#ifdef __sun
+    return memalign(alignment, size);
+#else
     void* ptr = 0;
     posix_memalign(&ptr, alignment, size);
     return ptr;
+#endif
 }
 
 
