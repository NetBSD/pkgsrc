$NetBSD: patch-mozilla_mfbt_Poison.cpp,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/mfbt/Poison.cpp.orig	2016-04-07 21:33:25.000000000 +0000
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
