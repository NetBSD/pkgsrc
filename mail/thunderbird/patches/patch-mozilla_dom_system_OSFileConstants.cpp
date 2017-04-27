$NetBSD: patch-mozilla_dom_system_OSFileConstants.cpp,v 1.4 2017/04/27 13:32:40 ryoon Exp $

--- mozilla/dom/system/OSFileConstants.cpp.orig	2017-04-14 04:53:07.000000000 +0000
+++ mozilla/dom/system/OSFileConstants.cpp
@@ -16,14 +16,17 @@
 #include "dirent.h"
 #include "poll.h"
 #include "sys/stat.h"
-#if defined(ANDROID)
+#if defined(XP_LINUX)
 #include <sys/vfs.h>
 #define statvfs statfs
+#define f_frsize f_bsize
 #else
 #include "sys/statvfs.h"
+#endif // defined(XP_LINUX)
+#if !defined(ANDROID)
 #include "sys/wait.h"
 #include <spawn.h>
-#endif // defined(ANDROID)
+#endif // !defined(ANDROID)
 #endif // defined(XP_UNIX)
 
 #if defined(XP_LINUX)
@@ -699,7 +702,7 @@ static const dom::ConstantSpec gLibcProp
 
   { "OSFILE_SIZEOF_STATVFS", JS::Int32Value(sizeof (struct statvfs)) },
 
-  { "OSFILE_OFFSETOF_STATVFS_F_BSIZE", JS::Int32Value(offsetof (struct statvfs, f_bsize)) },
+  { "OSFILE_OFFSETOF_STATVFS_F_FRSIZE", JS::Int32Value(offsetof (struct statvfs, f_frsize)) },
   { "OSFILE_OFFSETOF_STATVFS_F_BAVAIL", JS::Int32Value(offsetof (struct statvfs, f_bavail)) },
 
 #endif // defined(XP_UNIX)
