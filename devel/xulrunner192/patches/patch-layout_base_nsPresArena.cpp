$NetBSD: patch-layout_base_nsPresArena.cpp,v 1.1 2016/09/16 11:42:24 jperkin Exp $

Use posix_madvise() on SunOS.

--- layout/base/nsPresArena.cpp.orig	2012-03-06 14:45:35.000000000 +0000
+++ layout/base/nsPresArena.cpp
@@ -180,7 +180,11 @@ ReleaseRegion(void *region, PRUword size
 static bool
 ProbeRegion(PRUword region, PRUword size)
 {
+#ifdef __sun
+  if (posix_madvise((caddr_t)region, size, MADV_NORMAL)) {
+#else
   if (madvise((caddr_t)region, size, MADV_NORMAL)) {
+#endif
     return true;
   } else {
     return false;
