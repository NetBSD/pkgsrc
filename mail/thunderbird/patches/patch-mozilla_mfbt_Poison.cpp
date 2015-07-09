$NetBSD: patch-mozilla_mfbt_Poison.cpp,v 1.2 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/mfbt/Poison.cpp.orig	2015-06-08 17:49:26.000000000 +0000
+++ mozilla/mfbt/Poison.cpp
@@ -129,7 +129,11 @@ ReleaseRegion(void* aRegion, uintptr_t a
 static bool
 ProbeRegion(uintptr_t aRegion, uintptr_t aSize)
 {
+#if !defined(__sun__)
   if (madvise(reinterpret_cast<void*>(aRegion), aSize, MADV_NORMAL)) {
+#else
+  if (posix_madvise(reinterpret_cast<void*>(aRegion), aSize, MADV_NORMAL)) {
+#endif
     return true;
   } else {
     return false;
