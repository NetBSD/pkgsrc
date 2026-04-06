$NetBSD: patch-lib_ncutil_src_fileutil.cpp,v 1.1 2026/04/06 13:46:38 nia Exp $

Make code that is not really Linux-specific universal.

Add some specific code for finding KERN_PROC_PATHNAME on NetBSD.

--- lib/ncutil/src/fileutil.cpp.orig	2026-04-06 12:05:58.664053408 +0000
+++ lib/ncutil/src/fileutil.cpp
@@ -18,6 +18,9 @@
 #endif
 
 #include <sys/types.h>
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
 #include <sys/stat.h>
 
 #if defined(__APPLE__)
@@ -240,7 +243,15 @@ std::string FileUtil::GetSelfPath()
   {
     return std::string(pathbuf);
   }
-#elif defined(__linux__)
+#elif defined(__NetBSD__)
+  char buf[PATH_MAX];
+  int mib[4] = { CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME };
+  size_t buflen = sizeof(buf);
+  if (sysctl(mib, 4, buf, &buflen, NULL, 0) == 0)
+  {
+    return std::string(buf);
+  }
+#else
   char pathbuf[PATH_MAX];
   ssize_t count = readlink("/proc/self/exe", pathbuf, sizeof(pathbuf));
   if (count > 0)
@@ -255,10 +266,9 @@ std::string FileUtil::GetLibSuffix()
 {
 #if defined(__APPLE__)
   return ".dylib";
-#elif defined(__linux__)
+#else
   return ".so";
 #endif
-  return "";
 }
 
 std::string FileUtil::GetSuffixedCount(ssize_t p_Size)
