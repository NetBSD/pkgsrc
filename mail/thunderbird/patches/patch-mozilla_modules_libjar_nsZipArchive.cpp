$NetBSD: patch-mozilla_modules_libjar_nsZipArchive.cpp,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/modules/libjar/nsZipArchive.cpp.orig	2016-04-07 21:33:29.000000000 +0000
+++ mozilla/modules/libjar/nsZipArchive.cpp
@@ -626,7 +626,9 @@ MOZ_WIN_MEM_TRY_BEGIN
     // Success means optimized jar layout from bug 559961 is in effect
     uint32_t readaheadLength = xtolong(startp);
     if (readaheadLength) {
-#if defined(XP_UNIX)
+#if defined(OS_SOLARIS)
+      posix_madvise(const_cast<uint8_t*>(startp), readaheadLength, POSIX_MADV_WILLNEED);
+#elif defined(XP_UNIX)
       madvise(const_cast<uint8_t*>(startp), readaheadLength, MADV_WILLNEED);
 #elif defined(XP_WIN)
       if (aFd) {
