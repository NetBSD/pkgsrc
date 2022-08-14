$NetBSD: patch-lib_Support_Unix_Path.inc,v 1.3 2022/08/14 20:22:44 tnn Exp $

Use posix_madvise(2) instead of madvise(2).
Some operating systems (SmartOS) have a historical prototype
for madvise(2) which has caddr_t as the first argument.
Adapted from upstream b66b3247f598448aab50d8ae67729dd2312f3067.

--- lib/Support/Unix/Path.inc.orig	2022-06-22 16:46:24.000000000 +0000
+++ lib/Support/Unix/Path.inc
@@ -874,12 +874,14 @@ void mapped_file_region::unmapImpl() {
 
 void mapped_file_region::dontNeedImpl() {
   assert(Mode == mapped_file_region::readonly);
+  if (!Mapping)
+    return;
 #if defined(__MVS__) || defined(_AIX)
   // If we don't have madvise, or it isn't beneficial, treat this as a no-op.
-  return;
+#elif defined(POSIX_MADV_DONTNEED)
+  ::posix_madvise(Mapping, Size, POSIX_MADV_DONTNEED);
 #else
-  if (Mapping)
-    ::madvise(Mapping, Size, MADV_DONTNEED);
+  ::madvise(Mapping, Size, MADV_DONTNEED);
 #endif
 }
 
