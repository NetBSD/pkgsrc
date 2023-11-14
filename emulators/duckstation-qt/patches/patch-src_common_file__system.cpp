$NetBSD: patch-src_common_file__system.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/common/file_system.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/common/file_system.cpp
@@ -17,7 +17,7 @@
 #include <sys/param.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -1474,15 +1474,14 @@ static u32 RecursiveFindFiles(const char
     FILESYSTEM_FIND_DATA outData;
     outData.Attributes = 0;
 
-#if defined(__HAIKU__) || defined(__APPLE__) || defined(__FreeBSD__)
-    struct stat sDir;
-    if (stat(full_path.c_str(), &sDir) < 0)
-      continue;
-
-#else
+#ifdef __linux__
     struct stat64 sDir;
     if (stat64(full_path.c_str(), &sDir) < 0)
       continue;
+#else
+    struct stat sDir;
+    if (stat(full_path.c_str(), &sDir) < 0)
+      continue;
 #endif
 
     if (S_ISDIR(sDir.st_mode))
@@ -1587,12 +1586,12 @@ bool FileSystem::StatFile(const char* pa
     return false;
 
     // stat file
-#if defined(__HAIKU__) || defined(__APPLE__) || defined(__FreeBSD__)
-  struct stat sysStatData;
-  if (stat(path, &sysStatData) < 0)
-#else
+#ifdef __linux__
   struct stat64 sysStatData;
   if (stat64(path, &sysStatData) < 0)
+#else
+  struct stat sysStatData;
+  if (stat(path, &sysStatData) < 0)
 #endif
     return false;
 
@@ -1620,12 +1619,12 @@ bool FileSystem::StatFile(std::FILE* fp,
     return false;
 
     // stat file
-#if defined(__HAIKU__) || defined(__APPLE__) || defined(__FreeBSD__)
-  struct stat sysStatData;
-  if (fstat(fd, &sysStatData) < 0)
-#else
+#ifdef __linux__
   struct stat64 sysStatData;
   if (fstat64(fd, &sysStatData) < 0)
+#else
+  struct stat sysStatData;
+  if (fstat(fd, &sysStatData) < 0)
 #endif
     return false;
 
@@ -1653,12 +1652,12 @@ bool FileSystem::FileExists(const char* 
     return false;
 
     // stat file
-#if defined(__HAIKU__) || defined(__APPLE__) || defined(__FreeBSD__)
-  struct stat sysStatData;
-  if (stat(path, &sysStatData) < 0)
-#else
+#ifdef __linux__
   struct stat64 sysStatData;
   if (stat64(path, &sysStatData) < 0)
+#else
+  struct stat sysStatData;
+  if (stat(path, &sysStatData) < 0)
 #endif
     return false;
 
@@ -1675,12 +1674,12 @@ bool FileSystem::DirectoryExists(const c
     return false;
 
     // stat file
-#if defined(__HAIKU__) || defined(__APPLE__) || defined(__FreeBSD__)
-  struct stat sysStatData;
-  if (stat(path, &sysStatData) < 0)
-#else
+#ifdef __linux__
   struct stat64 sysStatData;
   if (stat64(path, &sysStatData) < 0)
+#else
+  struct stat sysStatData;
+  if (stat(path, &sysStatData) < 0)
 #endif
     return false;
 
@@ -1886,6 +1885,16 @@ std::string FileSystem::GetProgramPath()
 
   buffer[cb] = '\0';
   return buffer;
+#elif defined(__NetBSD__)
+  int mib[4] = {CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME};
+  char buffer[PATH_MAX];
+  size_t cb = sizeof(buffer) - 1;
+  int res = sysctl(mib, std::size(mib), buffer, &cb, nullptr, 0);
+  if (res != 0)
+    return {};
+
+  buffer[cb] = '\0';
+  return buffer;
 #else
   return {};
 #endif
