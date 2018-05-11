$NetBSD: patch-mfbt_tests_TestPoisonArea.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- mfbt/tests/TestPoisonArea.cpp.orig	2018-04-28 01:04:05.000000000 +0000
+++ mfbt/tests/TestPoisonArea.cpp
@@ -266,7 +266,11 @@ ReleaseRegion(void* aPage)
 static bool
 ProbeRegion(uintptr_t aPage)
 {
+#ifdef __sun
+  return !!posix_madvise(reinterpret_cast<void*>(aPage), PageSize(), MADV_NORMAL);
+#else
   return !!madvise(reinterpret_cast<void*>(aPage), PageSize(), MADV_NORMAL);
+#endif
 }
 
 static int
