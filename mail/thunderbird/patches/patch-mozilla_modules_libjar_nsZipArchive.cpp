$NetBSD: patch-mozilla_modules_libjar_nsZipArchive.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/modules/libjar/nsZipArchive.cpp.orig	2013-10-23 22:09:14.000000000 +0000
+++ mozilla/modules/libjar/nsZipArchive.cpp
@@ -590,7 +590,9 @@ MOZ_WIN_MEM_TRY_BEGIN
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
