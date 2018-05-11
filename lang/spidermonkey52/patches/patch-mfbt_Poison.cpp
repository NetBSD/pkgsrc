$NetBSD: patch-mfbt_Poison.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- mfbt/Poison.cpp.orig	2018-04-28 01:04:05.000000000 +0000
+++ mfbt/Poison.cpp
@@ -129,7 +129,11 @@ ReleaseRegion(void* aRegion, uintptr_t a
 static bool
 ProbeRegion(uintptr_t aRegion, uintptr_t aSize)
 {
+#ifdef __sun
+  if (posix_madvise(reinterpret_cast<void*>(aRegion), aSize, MADV_NORMAL)) {
+#else
   if (madvise(reinterpret_cast<void*>(aRegion), aSize, MADV_NORMAL)) {
+#endif
     return true;
   } else {
     return false;
